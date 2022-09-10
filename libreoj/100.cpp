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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, p, m;
    cin >> n >> p >> m;
    ll a[n][p], b[p][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < p; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < p; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    ll res[n][m];
    memset(res, 0, sizeof(res));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            for(int k = 0; k < p; ++k) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
            res[i][j] %= mod;
            if(res[i][j] < 0)
                res[i][j] += mod;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}