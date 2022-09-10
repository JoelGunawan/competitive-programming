#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int lim = 2e4 + 5;
struct dsu {
    int head[lim], size[lim];
    dsu() {
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
        }
        return x != y;
    }
};
int main() {
    int n, m, k;
    vector<pair<int, int>> batu, beton;
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        if(c)
            beton.pb({u, v});
        else
            batu.pb({u, v});
    }
    dsu dsu1, dsu2, dsu3;
    vector<pair<int, int>> batu_penting, beton_penting;
    for(auto i : batu)
        dsu1.merge(i.first, i.second);
    for(auto i : beton) {
        if(dsu1.merge(i.first, i.second))
            beton_penting.push_back(i);
    }

    for(auto i : beton)
        dsu2.merge(i.first, i.second);
    for(auto i : batu) {
        if(dsu2.merge(i.first, i.second))
            batu_penting.push_back(i);
    }
    // jumlah total edge -> n - 1
    if(dsu1.size[dsu1.find_head(1)] != n || batu_penting.size() > k || beton_penting.size() > n - 1 - k)
        cout << "no solution" << endl, exit(0);
    for(auto i : batu_penting)
        cout << i.first << " " << i.second << " " << 0 << endl, dsu3.merge(i.first, i.second);
    for(auto i : beton_penting)
        cout << i.first << " " << i.second << " " << 1 << endl, dsu3.merge(i.first, i.second);
    for(int i = 0; i < k - batu_penting.size(); ++i) {
        while(!dsu3.merge(batu.back().first, batu.back().second))
            batu.pop_back();
        cout << batu.back().first << " " << batu.back().second << " " << 0 << endl;
        batu.pop_back();
    }
    for(auto i : beton) {
        if(dsu3.merge(i.first, i.second))
            cout << i.first << " " << i.second << " " << 1 << endl;
    }
}
/*
struct dsu {
    int head[lim], size[lim];
    dsu() {
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
        }
        return x != y;
    }
};
int main() {
    dsu concrete_only, cobble_only;
    vector<pair<int, int>> crucial_cobble, crucial_concrete;
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> cobble_edge, concrete_edge;
    for(int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        if(c)
            concrete_edge.push_back({u, v});
        else
            cobble_edge.push_back({u, v});
    }
    for(auto i : concrete_edge) {
        concrete_only.merge(i.first, i.second);
    }
    for(auto i : cobble_edge) {
        cobble_only.merge(i.first, i.second);
    }
    for(auto i : concrete_edge) {
        if(cobble_only.merge(i.first, i.second))
            crucial_concrete.push_back(i);
    }
    for(auto i : cobble_edge) {
        if(concrete_only.merge(i.first, i.second))
            crucial_cobble.push_back(i);
    }
    if(cobble_only.size[cobble_only.find_head(1)] != n || concrete_only.size[concrete_only.find_head(1)] != n || crucial_concrete.size() > n - 1 - k || crucial_cobble.size() > k) {
        cout << "no solution" << endl, exit(0);
    }
    dsu res;
    for(auto i : crucial_concrete)
        res.merge(i.first, i.second);
    for(auto i : crucial_cobble)
        res.merge(i.first, i.second);
    vector<pair<int, int>> ans;
    for(int i = 0; i < k - crucial_cobble.size(); ++i) {
        while(!res.merge(cobble_edge.back().first, cobble_edge.back().second))
            cobble_edge.pop_back();
        cout << cobble_edge.back().first << " " << cobble_edge.back().second << " " << 0 << endl;
        cobble_edge.pop_back();
    }
    for(auto i : concrete_edge) {
        if(res.merge(i.first, i.second)) {
            cout << i.first << " " << i.second << " " << 1 << endl;
        }
    }
    for(auto i : crucial_concrete)
        cout << i.first << " " << i.second << " " << 1 << endl;
    for(auto i : crucial_cobble)
        cout << i.first << " " << i.second << " " << 0 << endl;
}
*/
/*
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> concrete[n + 1], cobble[n + 1];
    set<pair<bool, pair<int, int>>> roads;
    dsu final_graph, concrete_only;
    for(int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if(c)
            concrete[u].pb(v), concrete[v].pb(u);
        else
            cobble[u].pb(v), cobble[v].pb(u);
        roads.insert({c, {u, v}});
    }
    vector<pair<bool, pair<int, int>>> ans;
    stack<int> dfs;
    dfs.push(1);
    bool vis[n + 1]; memset(vis, 0, sizeof(vis));
    while(dfs.size() > 0)
    {
        int cur = dfs.top(); dfs.pop();
        if(vis[cur])
            continue;
        vis[cur] = 1;
        for(auto it = concrete[cur].begin(); it != concrete[cur].end(); ++it)
            dfs.push(*it);
        for(auto it = cobble[cur].begin(); it != cobble[cur].end(); ++it)
            dfs.push(*it);
    }
    bool no_solution = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            no_solution = 1;
    if(no_solution)
        cout << "no solution" << endl, exit(0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = concrete[i].begin(); it != concrete[i].end(); ++it)
            if(concrete_only.find_head(i) != concrete_only.find_head(*it))
                concrete_only.merge(i, *it);
    }   
    //cout << "TEST" << endl;
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = cobble[i].begin(); it != cobble[i].end(); ++it)
            if(concrete_only.find_head(i) != concrete_only.find_head(*it))
                ans.pb({0, {i, *it}}), final_graph.merge(i, *it), concrete_only.merge(i, *it);
    }
    if(ans.size() > k)
        cout << "no solution" << endl, exit(0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = cobble[i].begin(); it != cobble[i].end(); ++it)
        {
            if(ans.size() < k && final_graph.find_head(i) != final_graph.find_head(*it))
                ans.pb({0, {i, *it}}), final_graph.merge(i, *it);
        }
    }
    if(ans.size() != k)
        cout << "no solution" << endl, exit(0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = concrete[i].begin(); it != concrete[i].end(); ++it)
            if(final_graph.find_head(i) != final_graph.find_head(*it))
                ans.pb({1, {i, *it}}), final_graph.merge(i, *it);
    }
    if(ans.size() != n - 1)
        cout << "no solution" << endl, exit(0);
    for(int i = 0; i < ans.size(); ++i)
    {
        if(roads.find(ans[i]) == roads.end())
            swap(ans[i].second.first, ans[i].second.second);
        cout << ans[i].second.first << " " << ans[i].second.second << " " << (int)ans[i].first << endl;
    }
    return 0;
}
*/