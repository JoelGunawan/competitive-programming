#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
#define fi first
#define se second
using namespace std;
int previous[(int)1e5 + 1];
vector<int> e[(int)1e5 + 1];
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << fixed << setprecision(9);
    vector<pair<int, int>> e[n + 1];
    for(int i = 0; i < n + 1; ++i)
        e[i] = vector<pair<int, int>>();
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, w}), e[v].pb({u, w});
    }
    int md1[n + 1], md2[n + 1], cnt1[n + 1], cnt2[n + 1]; bool v[n + 1];
    for(int i = 0; i <= n; ++i)
        md1[i] = INT_MAX, md2[i] = INT_MAX;
    memset(cnt1, 0, sizeof(cnt1)); cnt1[0] = 1;
    memset(v, 0, sizeof(v)); 
    md1[a] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, a}});
    while(pq.size() > 0)
    {
        int w = -pq.top().fi, prev =  pq.top().se.fi, cur = pq.top().se.se;
        pq.pop();
        if(w > md1[cur])
            continue;
        cnt1[cur] += cnt1[prev];
        if(!v[cur])
        {
            v[cur] = 1;
            for(int i = 0; i < e[cur].size(); ++i)
                if(w + e[cur][i].se <= md1[e[cur][i].fi])
                    pq.push({-(w + e[cur][i].se), {cur, e[cur][i].fi}}), md1[e[cur][i].fi] = w + e[cur][i].se;
        }
    }
    memset(cnt2, 0, sizeof(cnt2)); cnt2[0] = 1;
    memset(v, 0, sizeof(v));
    md2[b] = 0;
    pq.push({0, {0, b}});
    while(pq.size() > 0)
    {
        int w = -pq.top().fi, prev = pq.top().se.fi, cur = pq.top().se.se;
        pq.pop();
        if(w > md2[cur])
            continue;
        cnt2[cur] += cnt2[prev];
        if(!v[cur])
        {
            v[cur] = 1;
            for(int i = 0; i < e[cur].size(); ++i)
                if(w + e[cur][i].se <= md2[e[cur][i].fi])
                    pq.push({-(w + e[cur][i].se), {cur, e[cur][i].fi}}), md2[e[cur][i].fi] = w + e[cur][i].se;
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(md1[i] + md2[i] == md1[b])
            cout << ((long double)((ll)cnt1[i] * cnt2[i]) / (long double)cnt1[b]) * (long double)2 << endl;
        else
            cout << (long double)0 << endl;
    }
    return 0;
}