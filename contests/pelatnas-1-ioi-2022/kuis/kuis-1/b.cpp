#include <bits/stdc++.h>
//#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define ll long long
#define mem memset
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
ll inv(ll a)
{
    return powmod(a, mod - 2);
}
ll submod(ll a, ll b)
{
    return (((a - b) % mod) + mod) % mod;
}
vector<vector<int>> edges[301];
vector<vector<int>> res;
vector<int> cur;
void gen(vector<int> a, int depth = 0)
{
    if(depth == 0)
        res.clear();
    for(int i = 0; i < edges[depth + 1][a[depth]].size(); ++i)
    {
        cur.pb(edges[depth + 1][a[depth]][i]);
        if(depth == a.size() - 1)
            res.pb(cur);
        else
            gen(a, depth + 1);
        cur.pop_back();
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    int n[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> n[i];
    int m;
    cin >> m;
    for(int i = 1; i <= k; ++i)
        edges[i] = vector<vector<int>>(n[i] + 1, vector<int>());
    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b].pb(c);
        edges[a][c].pb(b);
    }
    // do a bfs using unordered_map<vector<int>, int>
    map<vector<int>, bool> vis;
    queue<pair<vector<int>, int>> bfs;
    vector<int> start = {};
    int result = 0;
    for(int i = 0; i < k; ++i)
        start.pb(1);
    bfs.push(make_pair(start, 0));
    while(bfs.size() > 0)
    {
        pair<vector<int>, int> cur = bfs.front();
        bfs.pop();
        if(vis[cur.fi])
            continue;
        else
            result += cur.se, vis[cur.fi] = 1;
        // for all next edges
        gen(cur.fi);
        vector<vector<int>> generate = res;
        for(int i = 0; i < generate.size(); ++i)
            if(!vis[generate[i]])
                bfs.push(make_pair(generate[i], cur.se + 1));
    }
    cout << result << endl;
    // do a special bfs
    // multiply by other possible numbers
    // maintain the total, so we can just simply divide the total by the current and multiply by newly added
    // use inverse mod to divide
    // maintain a pair<int, pair<int, int>>
    // first is time, second is dimension, third is quantity
    /*
    vector<pair<int, pair<int, int>>> arr;
    // if the node has already been visited before, don't bother going to that node
    // just add it to the mul
    for(int i = 1; i <= k; ++i)
    {
        // first is node, second is dist
        if(edges[i].size() == 0)
            cout << 0 << endl, exit(0);
        queue<pair<int, int>> bfs;
        int dist[2][n[i] + 1];
        mem(dist, -1, sizeof(dist));
        bfs.push({1, 0});
        multiset<int> count;
        while(bfs.size() > 0)
        {
            pair<int, int> cur = bfs.front();
            bfs.pop();
            if(dist[cur.se % 2][cur.fi] != -1)
                continue;
            else
            {
                dist[cur.se % 2][cur.fi] = cur.se;
                count.insert(cur.se);
            }
            for(int j = 0; j < edges[i][cur.fi].size(); ++j)
                if(dist[(cur.se + 1) % 2][edges[i][cur.fi][j]] == -1)
                    bfs.push({edges[i][cur.fi][j], cur.se + 1});
        }
        while(count.size() > 0)
        {
            arr.pb({*count.begin(), {i, count.count(*count.begin())}});
            count.erase(*count.begin());
        }
    }
    sort(arr.begin(), arr.end());
    int idx = 0;
    ll res = 0;
    ll mul[2];
    mul[0] = 0, mul[1] = 0;
    ll cnt[2][k + 1];
    mem(cnt, 0, sizeof(cnt));
    while(idx < arr.size())
    {
        int cur = arr[idx].fi;
        // dimension, quantity
        vector<pair<int, int>> tmp;
        while(idx < arr.size() && arr[idx].fi == cur)
            tmp.pb({arr[idx].se.fi, arr[idx].se.se}), ++idx;
        ll cur_mul = max(1ll, mul[cur % 2]);
        for(auto pr : tmp)
        {
            // divide
            if(cnt[cur % 2][pr.fi] != 0)
                cur_mul = mulmod(cur_mul, inv(cnt[cur % 2][pr.fi]));
            // multiply
            cur_mul = mulmod(cur_mul, cnt[cur % 2][pr.fi] + pr.se);
            cnt[cur % 2][pr.fi] += pr.se;
        }
        res = (res + mulmod(cur, submod(cur_mul, mul[cur % 2])));
        mul[cur % 2] = cur_mul;
    }
    cout << res << endl;
    */
    return 0;
}