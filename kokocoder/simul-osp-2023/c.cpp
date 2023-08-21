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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, b, k;
    cin >> n >> b >> k;
    ll m[k + 1], s[k + 1], p[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> m[i] >> s[i] >> p[i];
    // bsta
    ll l = 1, r = LLONG_MAX, ans;
    while(l <= r) {
        ll mid = (l + r) / 2;
        vector<ll> v;
        for(int i = 1; i <= k; ++i) {
            ll tmp = (mid - p[i]) / s[i];
            tmp = min(tmp, 0ll + m[i]);
            tmp = max(tmp, 0ll);
            //cout << tmp << " ";
            v.push_back(tmp);
        }
        //cout << endl;
        sort(v.begin(), v.end(), greater<ll>());
        lll res = 0;
        for(int i = 0; i < n; ++i) {
            res += v[i];
        }
        //cout << mid << " " << res << endl;
        if(res >= b)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}