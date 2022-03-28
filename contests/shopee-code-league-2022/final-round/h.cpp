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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // while dfs bisa more than length 1
    // gabung 2 edge
    ll n, b;
    cin >> n >> b;
    ll adj[n][n];
    memset(adj, 0, sizeof(adj));
    string names[n];
    for(ll i = 0; i < n; ++i)
        cin >> names[i];
    for(ll i = 0; i < b; ++i) {
        ll m, idx; string target;
        cin >> m >> target;
        for(ll j = 0; j < n; ++j)
            if(target == names[j])
                idx = j;
        for(ll j = 0; j < m; ++j) {
            ll p, s;
            cin >> p >> s;
            ll c = p / s;
            for(ll k = 0; k < s; ++k) {
                string tmp;
                cin >> tmp;
                ll tmp2 = 0;
                for(ll l = 0; l < n; ++l) {
                    if(tmp == names[l])
                        tmp2 = l;
                }
                adj[tmp2][idx] += c;
            }
        }
    }
    bool changed = 1;
    while(changed) {
        changed = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) {
                for(ll k = 0; k < n; ++k) {
                    if(i != j && j != k && adj[i][j] && adj[j][k]) {
                        changed = 1;
                        ll tmp = min(adj[i][j], adj[j][k]);
                        adj[i][k] += tmp;
                        adj[i][j] -= tmp;
                        adj[j][k] -= tmp;
                    }
                }
            }
        }
    }
    ll cnt = 0, ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i != j && adj[i][j])
                ans += adj[i][j];
        }
    }
    // try to divide groups
    cout << ans << " " << cnt << endl;
    return 0;
}