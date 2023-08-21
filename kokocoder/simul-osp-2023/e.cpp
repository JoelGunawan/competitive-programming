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
    int n;
    cin >> n;
    ll s[n + 1], x[n + 1], in[n + 1];
    memset(in, 0, sizeof(in));
    vector<int> child[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    for(int i = 1; i <= n; ++i)
        cin >> x[i], ++in[x[i]], child[x[i]].pb(i);
    ll res = 0;
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0)
            q.push(i);
    }
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(q.size()) {
        int nd = q.front();
        q.pop();
        if(in[nd] || vis[nd]) 
            continue;
        vis[nd] = 1;
        //cout << nd << " " << s[nd] << endl;
        for(auto i : child[nd])
            if(s[i] > 0)
                s[nd] += s[i];
        res += s[nd];
        //cout << nd << " " << s[nd] << endl;
        if(x[nd] != 0) {
            --in[x[nd]];
            q.push(x[nd]);
        }
    }
    cout << res << endl;
    return 0;
}