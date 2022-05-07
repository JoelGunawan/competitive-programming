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
const int lim = 1e5 + 5;
vector<int> edges[lim];
vector<pair<int, int>> queries[lim];
int c[lim], ans[lim];
struct disjoint_set {
    int head[lim], size[lim];
    map<int, int> m[lim];
    ordered_multiset a[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        //cout << "MERGE " << x << " " << y << " ";
        x = find_head(x), y = find_head(y);
        //cout << x << " " << y << endl;
        if(x != y) {
            if(size[y] > size[x])
                swap(x, y);
            size[x] += size[y], head[y] = x;
            for(auto i : m[y]) {
                int &tmp = i.se;
                /*
                for(auto j : a[x])
                    cout << j << " ";
                cout << endl;
                */
                if(m[x][i.fi]) {
                    a[x].erase(--a[x].lb(m[x][i.fi]));
                    //cout << "CHANGE " << i.fi << " " << m[x][i.fi] << " " << tmp + m[x][i.fi] << endl;
                    a[x].ins(tmp + m[x][i.fi]);
                }
                else
                    a[x].ins(tmp);
                //, cout << "INSERT " << i.fi << " " << tmp << endl;
                m[x][i.fi] += tmp;
                /*
                for(auto j : a[x])
                    cout << j << " ";
                cout << endl;
                */
            }
        }
        return x != y;
    }
};
int d[lim];
bool vis[lim];
vector<int> child[lim];
void get_d(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            child[nd].pb(i);
            d[i] = d[nd] + 1;
            get_d(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    disjoint_set dsu;
    for(int i = 1; i <= n; ++i) {
        dsu.a[i].ins(1);
        dsu.m[i][c[i]] = 1;
    }
    // sort queries per node
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    for(int i = 0; i < m; ++i) {
        int v, k;
        cin >> v >> k;
        queries[v].pb(mp(k, i));
    }
    get_d(1);
    pair<int, int> nodes[n];
    for(int i = 1; i <= n; ++i)
        nodes[i - 1] = mp(d[i], i);
    sort(nodes, nodes + n);
    reverse(nodes, nodes + n);
    for(auto i : nodes) {
        for(auto j : child[i.se])
            dsu.merge(j, i.se);
        int tmp = dsu.find_head(i.se);
        /*
        cout << "NODE " << i.se << endl;
        for(auto j : dsu.a[tmp]) {
            cout << j << " ";
        }
        cout << endl;
        for(auto j : dsu.m[tmp]) {
            cout << j.fi << " " << j.se << endl;
        }
        */
        for(auto q : queries[i.se]) {
            if(*dsu.a[tmp].begin() >= q.fi)
                ans[q.se] = dsu.a[tmp].size();
            else if(*--dsu.a[tmp].end() < q.fi)
                ans[q.se] = 0;
            else {
                ans[q.se] = dsu.a[tmp].size() - dsu.a[tmp].order_of_key(q.fi);
            }
        }
        //cout << "END" << endl;
    }
    for(int i = 0; i < m; ++i)
        cout << ans[i] << endl;
    return 0;
}