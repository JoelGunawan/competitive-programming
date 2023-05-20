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
const int lim = 5e5 + 5;
vector<int> child[lim];
int d[lim], md;
void dfs(int nd, int depth) {
    d[nd] = ++depth;
    md = max(md, d[nd]);
    for(auto i : child[nd])
        dfs(i, depth);
}
vector<vector<bool>> val[lim];
struct disjoint_set {
    int head[lim], size[lim];
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
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
            // merge logic agak rumit
            // since depth kiri tidak selalu sama dengan depth kanan, maka kita mulai dari paling atas (back)
            // jika ada kelebihan agak rumit
            if(val[x].size() < val[y].size())
                swap(val[x], val[y]);
            // mulai dari belakang
            for(int i = 1; i <= val[y].size(); ++i) {
                for(int j = 0; j < 26; ++j) {
                    val[x][val[x].size() - i][j] = val[x][val[x].size() - i][j] ^ val[y][val[y].size() - i][j];
                }
            }
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int par[n + 1];
    for(int i = 2; i <= n; ++i)
        cin >> par[i], child[par[i]].pb(i);
    char a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<pair<int, int>> query[n + 1];
    for(int i = 0; i < m; ++i) {
        int v, h;
        cin >> v >> h;
        query[v].pb(mp(h, i));
    }
    pair<int, int> nodes[n];
    for(int i = 1; i <= n; ++i)
        nodes[i - 1] = mp(d[i], i);
    sort(nodes, nodes + n);
    reverse(nodes, nodes + n);
    bool ans[m];
    disjoint_set dsu;
    dfs(1, 0);
    for(auto p : nodes) {
        // merging process agak rumit
        // kita perlu merge tiap child dari node, kemudian dari hasilnya kita append ke arraynya
        // buat handle query agak rumit
        //cout << p.se << endl;
        for(auto i : child[p.se])
            dsu.merge(i, p.se);
        for(auto q : query[p.se]) {
            //cout << q.se << " " << d[p.se] << " " << q.fi << endl;
            if(q.fi <= d[p.se] || q.fi - d[p.se] > val[dsu.find_head(p.se)].size())
                ans[q.se] = 1;
            else {
                // cek array
                int odd_cnt = 0;
                for(int i = 0; i < 26; ++i) {
                    odd_cnt += (val[dsu.find_head(p.se)][val[dsu.find_head(p.se)].size() - (q.fi - d[p.se])][i]);
                }
                //cout << q.se << " " << odd_cnt << endl;
                ans[q.se] = (odd_cnt <= 1);
            }
        }
        val[dsu.find_head(p.se)].pb(vector<bool>(26, 0));
        val[dsu.find_head(p.se)].back()[a[p.se] - 'a'] = 1;
    }
    for(auto i : ans) {
        if(i)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}