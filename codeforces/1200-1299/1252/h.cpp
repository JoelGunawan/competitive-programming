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
    int n;
    cin >> n;
    pair<ll, ll> land[n];
    for(int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        land[i] = mp(min(u, v), max(u, v));
    }
    sort(land, land + n);
    multiset<pair<ll, ll>> reversed;
    for(int i = 0; i < n; ++i)
        reversed.ins(mp(land[i].se, land[i].fi));
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        reversed.erase(reversed.find(mp(land[i].se, land[i].fi)));
        if(reversed.size() > 0)
            res = max(res, 2 * land[i].fi * min((*--reversed.end()).fi, land[i].se));
        res = max(res, land[i].fi * land[i].se);
    }
    if(res & 1)
        cout << res / 2 << ".5" << endl;
    else
        cout << res / 2 << ".0" << endl;
    return 0;
}