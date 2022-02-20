// header file
#include <bits/stdc++.h>
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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll fact[m + 1]; 
    fact[0] = 1;
    for(int i = 1; i <= m; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    ll res = 1;
    vector<pair<int, int>> a[m + 1];
    for(int i = 1; i <= n; ++i) {
        set<pair<int, int>> x;
        int g;
        cin >> g;
        for(int j = 0; j < g; ++j) {
            int input;
            cin >> input;
            if(x.lb(mp(input, 0)) == x.end() || (*x.lb(mp(input, 0))).fi != input)
                x.ins(mp(input, 1));
            else {
                pair<int, int> tmp = *x.lb(mp(input, 0));
                ++tmp.se;
                x.erase(x.lb(mp(input, 0)));
                x.ins(tmp);
            }
        }
        for(auto j : x)
            a[j.fi].pb(mp(i, j.se));
    }
    for(int i = 1; i <= m; ++i)
        sort(a[i].begin(), a[i].end());
    sort(a, a + m + 1);
    map<vector<pair<int, int>>, bool> vis;
    for(int i = 1; i <= m; ++i) {
        if(!vis[a[i]]) {
            //cout << i << endl;
            //for(auto j : a[i])
            //    cout << j.fi << " " << j.se << endl;
            vis[a[i]] = 1;
            res = (res * fact[upper_bound(a + 1, a + m + 1, a[i]) - lower_bound(a + 1, a + m + 1, a[i])]) % mod;
        }
    }
    cout << res << endl;
    return 0;
}