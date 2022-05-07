// header file
#include <bits/stdc++.h>
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
bool vis[100005];
ll val[100005];
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n], v[n];
    vector<int> connected[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> v[i], --a[i];
    for(int i = 0; i < n; ++i) {
        //cout << a[i] << " " << v[i] << endl;
        val[a[i]] += v[i];
    }
    set<pair<ll, int>> s;
    for(int i = 0; i < n; ++i) {
        s.ins(mp(val[i], i));
    }
    ll res = 0;
    while(s.size() > 0) {
        //for(auto i : s)
        //    cout << i.se << " ";
        //cout << endl;
        pair<ll, int> cur = *s.begin();
        ll dist = cur.fi; int nd = cur.se;
        //cout << nd << " " << dist << endl;
        s.erase(s.begin());
        int dest = a[nd];
        if(vis[dest])
            continue;
        vis[nd] = 1;
        res += v[nd];
        // reduce dest by a[nd]
        //cout << nd << " " << a[nd] << " " << val[a[nd]] << endl;
        s.erase(s.find(mp(val[a[nd]], a[nd])));
        val[a[nd]] -= v[nd];
        s.ins(mp(val[a[nd]], a[nd]));
    }
    cout << res << endl;
    return 0;
}