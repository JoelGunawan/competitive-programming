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
int mod = 1e9 + 9;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll sub(ll a, ll b) {
    a -= b;
    a %= mod;
    if(a < 0)
        a += mod;
    return a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    char a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // k + 1 and empty
    // k and empty
    // k + 1 and k
    // obs: k + 1 is just extension of k, but with additional in the edges
    // k + 1, extension of k + 1
    // divide into k parts
    // check if all k parts are the same
    bool ans[n + 1];
    memset(ans, 0, sizeof(ans));
    ll pref[n + 1];
    pref[0] = 0;
    int key = 998242353;
    for(int i = 1; i <= n; ++i) {
        pref[i] = (pref[i - 1] * key + a[i]) % mod;
        //cout << pref[i] << " ";
    }
    //cout << endl;
    ll pow[n + 1];
    pow[0] = 1;
    for(int i = 1; i <= n; ++i)
        pow[i] = (pow[i - 1] * key) % mod;
    vector<int> s, e;
    for(int i = k; i <= n; i += k) {
        // divide into k parts, use prefix hashing
        ll tmp = pow[i / k], res = 1;
        for(int j = 1; j < k; ++j)
            res = tmp * res + 1, res %= mod;
        if(mul(pref[i / k], res) == pref[i]) {
            //cout << i << endl;
            int l = i + 1, r = i + i / k, ans = i;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(mid <= n && sub(pref[mid], pref[i] * pow[mid - i]) == pref[mid - i])
                    l = mid + 1, ans = mid;
                else
                    r = mid - 1;
            }
            s.push_back(i);
            e.push_back(ans);
        }
    }
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    sort(e.begin(), e.end());
    reverse(e.begin(), e.end());
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        while(s.size() && s.back() == i)
            ++cnt, s.pop_back();
        ans[i] = cnt;
        while(e.size() && e.back() == i)
            --cnt, e.pop_back();
    }
    // divide into k + 1 exactly
    // ALWAYS from divide into k (no need)
    for(int i = 1; i <= n; ++i)
        cout << (int)ans[i];
    cout << endl;
    return 0;
}