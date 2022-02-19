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
struct disjoint_set {
    int head[300001], size[300001];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + 300001, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[y] > size[x])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
// fi is node, se.fi is weight, se.se is edge number
vector<pair<int, pair<int, int>>> edges[300001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[x].pb(mp(y, mp(w, i + 1)));
        edges[y].pb(mp(x, mp(w, i + 1)));
    }
    // fi is dist, se.fi is node, se.se is edge number
    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push(mp(0, mp(1, -1)));
    while(pq.size() > 0) {
        if(ans.size() == k + 1)
            break;
        int nd = pq.top().se.fi, edge_num = pq.top().se.se;
        ll dist = -pq.top().fi;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        ans.pb(edge_num);
        for(auto i : edges[nd]) {
            if(!vis[i.fi])
                pq.push(mp(-(dist + i.se.fi), mp(i.fi, i.se.se)));
        }
    }
    cout << ans.size() - 1 << endl;
    for(auto i : ans)   
        if(i != -1)
            cout << i << " ";
    cout << endl;
    return 0;
}