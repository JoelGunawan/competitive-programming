#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int subtrees[100001], height[100001], level = 0;
vector<int> edges[100001], ancestor[100001], ancestor_memo;
int dfs(int node)
{
    subtrees[node] = 1;
    height[node] = level;
    ++level;
    for(int i = 1; i <= ancestor_memo.size(); i *= 2)
        ancestor[node].pb(ancestor_memo[ancestor_memo.size() - i]);
    ancestor_memo.pb(node);
    for(int i = 0; i < edges[node].size(); ++i)
    {
        if(!subtrees[edges[node][i]])
            subtrees[node] += dfs(edges[node][i]);
    }
    ancestor_memo.pop_back();
    --level;
    return subtrees[node];
}
int find_node(int cur_node, int jump)
{
    while(jump > 0)
    {
        int x = 1, y = 0;
        while(2 * x <= jump)
            x *= 2, ++y;
        jump -= x;
        cur_node = ancestor[cur_node][y];
    }
    return cur_node;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // rooted tree
    // use something to find equal distance
    // we can use distance
    // by finding distance from lca
    // after finding distance from lca
    // we can determine size of which node is midpoint
    // and find subtree count of that node
    // subtracted by subtree count of the node with larger height
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    dfs(1);
    //for(int i = 0; i < idx; ++i)
    //    cout << order[i] << " ";
    //cout << endl;
    //cout << endl;
    //cout << endl;
    //for(int i = 1; i <= n; ++i)
    //    cout << height[i] << " ";
    //cout << endl;
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if(x == y)
            cout << n << endl;
        else
        {
            // check for LCA
            // use binary search
            // try to equalize height first
            if(height[x] < height[y])
                swap(x, y);
            int tmp = x;
            if(height[x] > height[y])
                tmp = find_node(x, height[x] - height[y]);
            int lca_height = 0, left = 0, right = height[y];
            while(left <= right)
            {
                
                int mid = (left + right) / 2;
                if(find_node(tmp, mid) == find_node(y, mid))
                    lca_height = height[y] - mid, right = mid - 1;
                else
                    left = mid + 1;
            }
            //cout << lca_height << " " << find_index[x] << " " << find_index[y] << " " << height[x] << " " << height[y] << endl;
            if(height[x] == height[y])
            {
                int height_diff = height[x] - lca_height;
                --height_diff;
                int a = find_node(x, height_diff), b = find_node(y, height_diff);
                cout << n - subtrees[a] - subtrees[b] << endl;
            }
            else
            {
                // basically x always has larger height
                if((height[x] - lca_height + height[y] - lca_height) % 2 == 1)
                    cout << 0 << endl;
                else
                {
                    int half = (height[x] - lca_height + height[y] - lca_height) / 2;
                    --half;
                    int a = find_node(x, half), b = find_node(a, 1);
                    //cout << a << " " << b << endl;
                    cout << subtrees[b] - subtrees[a] << endl;
                }
            }
        }
    }
    return 0;
}