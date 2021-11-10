#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
vector<int> edges[4096];
bool vis[4096];
vector<int> dfs(int a)
{
    vis[a] = 1;
    vector<int> res = {a};
    for(int i = 0; i < edges[a].size(); ++i)
        if(!vis[edges[a][i]])
        {
            vector<int> tmp = dfs(edges[a][i]);
            for(int j = 0; j < tmp.size(); ++j)
                res.push_back(tmp[j]);
        }
    return res;
}
/*
bool edges[31][31];
bool vis[31];
vector<int> dfs(int a)
{
    vis[a] = 1;
    vector<int> res = {a};
    for(int i = 0; i < 31; ++i)
        if(edges[a][i] && !vis[i])
        {
            vector<int> tmp = dfs(i);
            for(int j = 0; j < tmp.size(); ++j)
                res.pb(tmp[j]);
        }
    return res;
}
*/
int main()
{
    fast_io();
    // start from the highest
    // group each number into their first bit
    // then we can find the relationship between the first bits
    /*
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    ll group_res[31]; memset(group_res, 0, sizeof(group_res));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 30; j >= 0; --j)
        {
            if((1 << j) & a[i])
            {
                group_res[j] += b[i];
                break;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 30; j >= 0; --j)
        {
            if((1 << j) & a[i])
            {
                // try the next lower
                for(int k = j - 1; k >= 0; --k)
                {
                    if(group_res[k] > 0 && (((1 << k) & a[i]) == 0) && !edges[j][k])
                        edges[j][k] = 1, edges[k][j] = 1;
                }
            }
        }
    }
    // dfs each edge
    bool connected[31]; memset(connected, 0, sizeof(connected));
    for(int i = 0; i < 31; ++i)
    {
        if(!vis[i] && group_res[i] > 0)
        {
            vector<int> cur = dfs(i);
            if(cur.size() > 1)
            {
                ll tmp = 0;
                for(int j = 0; j < cur.size(); ++j)
                    tmp += group_res[cur[j]];
                for(int j = 0; j < cur.size(); ++j)
                    group_res[cur[j]] = tmp, connected[cur[j]] = 1;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 30; j >= 0; --j)
        {
            if((1 << j) & a[i])
            {
                if(connected[j])
                    cout << group_res[j] << " ";
                else
                    cout << b[i] << " ";
                break;
            }
        }
    }
    cout << endl;
    */
    int n;
    cin >> n;
    ll a[n], b[n];
    ll value[(1 << 12)]; memset(value, 0, sizeof(value));
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i], value[a[i]] += b[i];
    for(int i = 1; i < (1 << 12); ++i)
    {
        for(int j = i + 1; j < (1 << 12); ++j)
            if(value[i] > 0 && value[j] > 0 && (i ^ j) > max(i, j))
                edges[i].pb(j), edges[j].pb(i);
    }
    ll res[4096]; memset(res, 0, sizeof(res));
    for(int i = 1; i < (1 << 12); ++i)
    {
        if(!vis[i] && value[i] > 0)
        {
            vector<int> cur = dfs(i);
            if(cur.size() > 1)
            {
                ll tmp = 0;
                for(int j = 0; j < cur.size(); ++j)
                    tmp += value[cur[j]];
                for(int j = 0; j < cur.size(); ++j)
                    if(value[cur[j]] > 0)
                        res[cur[j]] = tmp;
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        if(res[a[i]])
            cout << res[a[i]] << " ";
        else
            cout << b[i] << " ";
    }
    cout << endl;
    /*
    int n;
    cin >> n;
    ll a[n], b[n], c[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i], c[i] = a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(c, c + n);
    if(c[0] == c[n - 1])
    {
        for(int i = 0; i < n; ++i)
            cout << b[i] << " ";
        cout << endl;
    }
    else
    {
        ll res = 0;
        for(int i = 0; i < n; ++i)
            res += b[i];
        for(int i = 0; i < n; ++i)
            cout << res << " ";
        cout << endl;
    }
    return 0;
    */
    // O(n^2) solution
    // basically do a dfs
    // find strongly connected components
    /*
    for(int i = 0; i < n; ++i)
    {
        // if 2 indices are connected, then add an edges
        for(int j = i + 1; j < n; ++j)
            if((a[i] ^ a[j]) > max(a[i], a[j]))
                edges[i].pb(j), edges[j].pb(i);
    }
    ll res[n];
    for(int i = 0; i < n; ++i)
        if(!vis[i])
        {
            // do a dfs 
            vector<int> cur = dfs(i);
            ll tmp = 0;
            for(int j = 0; j < cur.size(); ++j)
                tmp += b[cur[j]];
            for(int j = 0; j < cur.size(); ++j)
                res[cur[j]] = tmp;
        }
    for(int i = 0; i < n; ++i)
        cout << res[i] << " ";
    cout << endl;
    */
    // 2 islands are connected directly if and only if the first '1' bit in each number is not XORed by the other number
    // we can have an array counting the first '1' bit in each number
    /*
    vector<int> indices[32];
    int next[n];
    memset(next, -1, sizeof(next));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 32; ++j)
            if((1ll << j) & a[i])
                indices[j].pb(i);
    }
    // we have all the indices
    // now we need to connect them
    for(int i = 0; i < n; ++i)
    {

    }
    */
    return 0;
}