#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
using namespace std;
/*
// fi is node, se is dist
set<pair<int, int>> edges[100001];
bool grape[100001];
bool vis[2005];
long long dfs(int nd, long long prev) {
    vis[nd] = 1;
    if(grape[nd])
        return prev;
    else {
        long long res = LLONG_MAX;
        for(pair<int, int> i : edges[nd]) {
            if(!vis[i.first])
                res = min(res, dfs(i.first, prev + i.second));
        }
        return res;
    }
}
*/

vector<pair<int, int>> edges[100001];
bool grape[100001], vis[100001];
// get subtree size, index in ett and dist from root
int subtree[100001], idx[100001], tmp = 0;
lll dist[100001], inf = 1e10;
int dfs(int nd = 1, lll pr = 0) {
    idx[nd] = tmp++;
    vis[nd] = 1;
    dist[nd] = pr;
    subtree[nd] = 1;
    for(pair<int, int> i : edges[nd]) {
        if(!vis[i.first]) {
            subtree[nd] += dfs(i.first, pr + i.second);
        }
    }
    return subtree[nd];
}
struct segtree {
    lll a[1 << 18], lazy[1 << 18], arr_size = 1 << 17;
    segtree() {
        fill(a, a + (1 << 18), inf);
        fill(lazy, lazy + (1 << 18), 0);
    }
    void update(int nd, int l, int r, int cl, int cr, lll val) {
        // we add by val
        if(cl > r || cr < l)
            return;
        else if(cl >= l && cr <= r) {
            // simpen lazy
            lazy[nd] += val;
            a[nd] += val;
            //cout << "end " << nd << " " << (ll)a[nd] << endl;
        }
        else {
            int mid = (cl + cr) / 2;
            // propagate to child
            lazy[2 * nd] += lazy[nd], lazy[2 * nd + 1] += lazy[nd], a[2 * nd] += lazy[nd], a[2 * nd + 1] += lazy[nd];
            lazy[nd] = 0;
            update(2 * nd, l, r, cl, mid, val);
            update(2 * nd + 1, l, r, mid + 1, cr, val);
            a[nd] = min(a[2 * nd], a[2 * nd + 1]);
            //cout << nd << " " << (ll)a[nd] << endl;
        }
    }
    void update(int l, int r, lll val) {
        update(1, l, r, 0, arr_size - 1, val);
    }
    lll query(int nd, int l, int r, int cl, int cr) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return inf;
        else {
            int mid = (cl + cr) / 2;
            lazy[2 * nd] += lazy[nd], lazy[2 * nd + 1] += lazy[nd], a[2 * nd] += lazy[nd], a[2 * nd + 1] += lazy[nd];
            lazy[nd] = 0;
            return min(query(2 * nd, l, r, cl, mid), query(2 * nd + 1, l, r, mid + 1, cr));
        }
    }
    lll query(int l, int r) {
        return query(1, l, r, 0, arr_size - 1);
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    // subtask 1
    /*
    for(int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].insert(make_pair(b, w));
        edges[b].insert(make_pair(a, w));
    }
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int nd;
            cin >> nd;
            memset(vis, 0, sizeof(vis));
            long long tmp = dfs(nd, 0);
            if(tmp == LLONG_MAX)
                cout << -1 << endl;
            else
                cout << tmp << endl;
        }
        else if(t == 2) {
            int nd;
            cin >> nd;
            grape[nd] = !grape[nd];
        }
        else {
            int a, b, w;
            cin >> a >> b >> w;
            edges[a].erase(edges[a].lower_bound(make_pair(b, 0)));
            edges[b].erase(edges[b].lower_bound(make_pair(a, 0)));
            edges[a].insert(make_pair(b, w));
            edges[b].insert(make_pair(a, w));
        }
    }
    */
    // subtask 2
    // we don't need to maintain edges, we can just check it from 2 point queries
    for(int i = 0; i < n - 1; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[a].push_back(make_pair(b, w));
        edges[b].push_back(make_pair(a, w));
    }
    dfs(1);
    segtree d, qu;
    for(int i = 1; i <= n; ++i) {
        d.update(idx[i], idx[i], dist[i] - d.query(idx[i], idx[i]));
    }
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int nd;
            cin >> nd;
            lll tmp = qu.query(1, n);
            if(tmp >= 1e18)
                cout << -1 << endl;
            else
                cout << (ll)tmp << endl;
        }
        else if(t == 2) {
            int nd;
            cin >> nd;
            nd = idx[nd];
            //cout << nd << endl;
            if(grape[nd]) {
                qu.update(nd, nd, inf - qu.query(nd, nd));
            }
            else {
                qu.update(nd, nd, d.query(nd, nd) - qu.query(nd, nd));
            }
            grape[nd] = !grape[nd];
        }
        else {
            int a, b, w;
            cin >> a >> b >> w;
            if(subtree[a] < subtree[b])
                swap(a, b);
            int tmp1 = a, tmp2 = b;
            a = idx[a], b = idx[b];
            lll prev_dist = d.query(b, b) - d.query(a, a);
            qu.update(b, b + subtree[tmp2] - 1, w - prev_dist);
            d.update(b, b + subtree[tmp2] - 1, w - prev_dist);
        }
    }
    // subtask 1 -> just update the value, for seek node, just use dfs to find min dist
    // subtask 2 -> maintain the distance of every node to node 1, use lazy segment tree
    // we maintain 2 lazy segment trees, first with actual distance, second with unactivated nodes set to infinity
    // first is for getting distance (point query range update), second is for seek operations (do minimum query)
    // subtask 3 -> for each update operation, we update the parent of the updated nodes
    // subtask 4 -> find distance to grape by finding LCA (binlift)
    // subtask 5 -> anneal actions are merging nodes, might be possible using dsu on tree?
}
