// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int mod = 998244353;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    char grid[n + 1][m + 1];
    memset(grid, 0, sizeof(grid));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> grid[i][j];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(grid[i - 1][j] == '#' || grid[i - 1][j - 1] == '#')
                grid[i][j] = '#';
        }
        cout << endl;
    }
    int a = max(n, m);
    int pref[n + m][a + 1];
    memset(pref, 0, sizeof(pref));
    // diag number didapat dr i - j + m
    //cout << "HERE" << endl;
    int diag[n + 1][m + 1];
    vector<pair<int, int>> b[n + m];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) 
            diag[i][j] = (n + m) - (i - j + m), b[diag[i][j]].pb(mp(i, j));
    }
    for(int i = 1; i <= n + m - 1; ++i) 
        sort(b[i].begin(), b[i].end());
    //cout << "TEST" << endl;
    ll res = 0;
    for(int i = 1; i <= n + m - 1; ++i) {
        for(auto p : b[i]) {
            if(grid[p.fi][p.se] != '#') {
                // berarti gas transisi :D
                // hanya boleh dr yg lebih kecil
                pref[i][p.se] = pref[i - 1][p.se - 1] + 1;
                //cout << i << " " << p.se << " " << pref[i][p.se] << endl;
            }
        }
        for(int j = 1; j <= a; ++j) {
            pref[i][j] = pref[i][j - 1] + pref[i][j];
            if(pref[i][j] > mod)
                pref[i][j] -= mod;
        }
        res += pref[i][a];
        for(int j = 1; j <= a; ++j) {
            pref[i][j] += pref[i - 1][j];
            if(pref[i][j] > mod)
                pref[i][j] -= mod;
        }
    }
    cout << (res + 1) % mod << endl;
    return 0;
}