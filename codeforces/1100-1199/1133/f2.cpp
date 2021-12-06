#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
struct dsu
{
    int head[2 * (int)1e5 + 1], size[2 * (int)1e5 + 1];
    dsu()
    {
        memset(head, -1, sizeof(head));
        fill(size, size + 2 * (int)1e5 + 1, 1);
    }
    bool merge(int a, int b)
    {
        int x = find_head(a), y = find_head(b);
        if(x != y)
        {
            if(size[x] < size[y])
                size[y] += size[x], head[x] = y;
            else
                size[x] += size[y], head[y] = x;       
        }
        return x != y;
    }
    int find_head(int node)
    {
        while(head[node] != -1)
            node = head[node];
        return node;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> one, not_one;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        if(u == 1 || v == 1)
            one.pb(mp(u, v));
        else
            not_one.pb(mp(u, v));
    }
    dsu init, res;
    for(int i = 0; i < not_one.size(); ++i)
        init.merge(not_one[i].fi, not_one[i].se);
    vector<int> required_index;
    for(int i = 0; i < one.size(); ++i)
        if(init.merge(one[i].fi, one[i].se))
            required_index.pb(i);
    if(required_index.size() > d || one.size() < d)
        cout << "NO" << endl, exit(0);
    vector<pair<int, int>> output;
    for(int i = 0; i < required_index.size(); ++i)
        output.pb(one[required_index[i]]), res.merge(one[required_index[i]].fi, one[required_index[i]].se);
    d -= required_index.size();
    for(int i = 0; i < one.size(); ++i)
    {
        if(d > 0 && res.merge(one[i].fi, one[i].se))
            --d, output.pb(one[i]);
    }
    for(int i = 0; i < not_one.size(); ++i)
    {
        if(res.merge(not_one[i].fi, not_one[i].se))
            output.pb(not_one[i]);
    }
    cout << "YES" << endl;
    for(int i = 0; i < output.size(); ++i)
        cout << output[i].fi << " " << output[i].se << endl;
    return 0;
}