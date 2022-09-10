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
long double c = sqrt(86);
ll gcd(ll a, ll b) {
    while(b != 0) {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    ll a, b;
    cin >> n >> a >> b;
    vector<pair<int, int>> ans;
    for(int i = 1; i <= sqrt(n); ++i) {
        if(n / i <= a && i <= a && n % i == 0)
            ans.pb(mp(i, n / i)), ans.pb(mp(n / i, i));
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i.fi << " 0 " << i.se << " 0" << endl;
    /*
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    for(int i = -a + 1; i < a; ++i) {
        for(int j = -b + 1; j < b; ++j) {
            for(int k = -a + 1; k < a; ++k) {
                for(int l = -b + 1; l < b; ++l) {
                    if(i * l + j * k == 0 && i * k + 86 * j * l == n && i + j * c >= 0 && k + l * c >= 0)
                        ans.pb(mp(mp(i, j), mp(k, l)));
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i.fi.fi << " " << i.fi.se << " " << i.se.fi << " " << i.se.se << endl;
    */
    return 0;
}