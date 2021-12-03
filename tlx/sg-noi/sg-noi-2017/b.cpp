#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pb push_back
#define ld long double
using namespace std;
struct sparse_table
{
    pair<int, int> a[18][(int)1 << 16];
    int f(int a)
    {
        return a < 0 ? 0 : 1 << a;
    }
    void build(vector<int> input)
    {
        for(int i = 0; i < input.size(); ++i)
            a[0][i] = {input[i], i};
        for(int i = 1; i < 18; ++i)
            for(int j = 0; j + f(i - 1) < (1 << 16); ++j)
                a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
    }
    // returns index
    int query_index(int left, int right)
    {
        if(left > right)
            swap(left, right);
        int x_dist = right - left + 1;
        int x = 1, msb = 0;
        while(2 * x <= x_dist)
            x *= 2, ++msb;
        return min(a[msb][left], a[msb][right - (1 << msb) + 1]).se;
    }
    int query_height(int left, int right)
    {
        if(left > right)
            swap(left, right);
        int x_dist = right - left + 1;
        int x = 1, msb = 0;
        while(2 * x <= x_dist)
            x *= 2, ++msb;
        return min(a[msb][left], a[msb][right - (1 << msb) + 1]).fi;
    }
};
vector<pair<int, int>> edges[(int)1e4 * 5 + 1];
bool vis[(int)1e4 * 5 + 1];
// node index keeps track of the index of a node inside the euler tour
int level = 0, node_index[(int)1e4 * 5 + 1], dist[(int)1e4 * 5 + 1], height[(int)1e4 * 5 + 1], cur_dist = 0;
vector<int> euler_tour, euler_tour_node;
sparse_table sp;
void dfs(int node)
{
    dist[node] = cur_dist;
    height[node] = level;
    vis[node] = 1;
    node_index[node] = euler_tour.size();
    euler_tour.pb(level);
    euler_tour_node.pb(node);
    for(auto i : edges[node])
        if(!vis[i.fi])
        {
            ++level;    
            cur_dist += i.se;
            dfs(i.fi);
            --level;
            cur_dist -= i.se;
            euler_tour.pb(level);
            euler_tour_node.pb(node);
        }
}
int lca_node(int a, int b)
{
    if(node_index[a] > node_index[b])
        swap(a, b);
    //cout << a << " " << b << " " << node_index[a] << " " << node_index[b] << " " << euler_tour_node[sp.query_index(node_index[a], node_index[b])] << " " << lca_height(a, b) << endl;
    return euler_tour_node[sp.query_index(node_index[a], node_index[b])];
}
int lca_height(int a, int b)
{
    //cout << a << " " << b << " " << sp.query_height(node_index[a], node_index[b]) << endl;
    if(node_index[a] > node_index[b])
        swap(a, b);
    return sp.query_height(node_index[a], node_index[b]);
}
int get_height(int node)
{
    return height[node];
}
int get_res(vector<int> a)
{
    int total_lca = a[0];
    for(int i = 1; i < a.size(); ++i)
        total_lca = lca_node(total_lca, a[i]);
    //cout << total_lca << " " << get_height(total_lca) << endl;
    //cout << "ARR" << endl;
    //for(int i = 0; i < a.size(); ++i)
    //    cout << a[i] << " ";
    //cout << endl;
    int largest_height = get_height(total_lca);
    int x, y;
    for(int i = 0; i < a.size(); ++i)
        for(int j = i + 1; j < a.size(); ++j)
        {
            if(lca_height(a[i], a[j]) > largest_height)
                largest_height = lca_height(a[i], a[j]), x = a[i], y = a[j];
        }
    //cout << total_lca << " " << largest_height << endl;
    if(largest_height == get_height(total_lca))
    {
        // calculate weights from each node to lca
        int res = 0;
        for(int i = 0; i < a.size(); ++i)
            res += dist[a[i]] - dist[total_lca];
        return res;
    }
    else
    {
        // merge x and y
        int tmp_lca = lca_node(x, y);
        a.erase(find(a.begin(), a.end(), x));
        a.erase(find(a.begin(), a.end(), y));
        a.pb(tmp_lca);
        int res = dist[x] + dist[y] - 2 * dist[tmp_lca];
        return res + get_res(a);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v;
    cin >> v;
    for(int i = 0; i < v - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb({v, w});
        edges[v].pb({u, w});
    }
    memset(node_index, -1, sizeof(node_index));
    dfs(0);
    //for(int i = 0; i < euler_tour.size(); ++i)
    //    cout << euler_tour_node[i] << " ";
    //cout << endl;
    //for(int i = 0; i < euler_tour.size(); ++i)
    //    cout << euler_tour[i] << " ";
    //cout << endl;
    //for(int i = 0; i < v; ++i)
    //    cout << node_index[i] << " ";
    //cout << endl;
    //for(int i = 0; i < v; ++i)
    //    cout << dist[i] << " ";
    //cout << endl;
    sp.build(euler_tour);
    int q;
    cin >> q;
    while(q--)
    {
        vector<int> tmp(5);
        for(int i = 0; i < 5; ++i)
            cin >> tmp[i];
        cout << get_res(tmp) << endl;
    }
    return 0;
}
// for each query go through each pair of the lcas
// we will merge the lca of 2 nodes if their lca is not equal to the total lca
// this process could probably be done using a few helper functions
// 1. find lca
// 2. find road weight to lca
// 3. find res (for query)
// and do an euler tour + sparse table
// to find lca :)
// theoretically worst time would be x log v * q
// where x is needed lca operations