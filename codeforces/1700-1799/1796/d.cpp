// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct segment_tree {
    vector<ll> a;
    int size;
    void update(int idx, ll val) {
        idx += size;
        a[idx] = val;
        while(idx) {
            idx >>= 1;
            a[idx] = min(a[2 * idx], a[2 * idx + 1]);
        }
    }
    ll query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l)
            return 1e18;
        else {
            int mid = (cl + cr) >> 1;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
void tc() {
    // for 1...k positions do directly
    // else find position with lowest prefix sum
    ll n, k, x;
    cin >> n >> k >> x;
    int tmp = 1;
    segment_tree seg;
    while(tmp <= n)
        tmp *= 2;
    seg.size = tmp, seg.a.resize(2 * tmp, 1e18);
    // this is the x positive case
    ll pref[n + 1], a[n + 1];
    pref[0] = 0;
    seg.update(0, 0);
    for(int i = 1; i <= n; ++i)
        cin >> a[i], pref[i] = pref[i - 1] + a[i] - x, seg.update(i, pref[i]);
    ll ans = 0; ll m = 1e18;
    for(int i = 1; i <= n; ++i) {
        // brute force k ke belakang
        // x positive
        if(i >= k)
            m = min(m, pref[i - k]);
        if(x >= 0) {
            ll sum = 0;
            for(int j = i; j >= max(i - k + 1, 1ll); --j) {
                sum += a[j] + x;
                ans = max(ans, sum);
            }
            ans = max(ans, pref[i] - seg.query(1, 0, seg.size - 1, 0, i - k) + k * 2 * x);
        }
        else {
            // x negative
            // if x negative, try to put in the next positions
            // or in previous positions if allowed
            // since k is low, brute forcing is probably possible
            int empty = n - i;
            ans = max(ans, pref[i] - seg.query(1, 0, seg.size - 1, 0, i) + max(min((ll)i, k - empty), 0ll) * 2 * x);
            // brute force k remaining positions in the back
            if(empty < k) {
                empty = k - empty;
                for(int j = 0; j <= min(i, empty); ++j) {
                    //cout << pref[i] << " " << pref[j] << " " << empty - j << endl;
                    ans = max(ans, pref[i] - seg.query(1, 0, seg.size - 1, j, i) + 2 * x * min(i, (empty - j)));
                }
                ans = max(ans, pref[i] - seg.query(1, 0, seg.size - 1, empty, i));
            }
        }
    }
    cout << ans << endl;
    // x negative: put in next positions
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}