#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string subsoal;
    cin >> subsoal;
    int v, e;
    cin >> v >> e;
    ll c_d, m_d, c_p, m_p, a, b;
    cin >> c_d >> m_d >> c_p >> m_p >> a >> b;
    ll min_dist[v + 1][v + 1];
    vector<pair<int, pair<int, int>>> edges[v + 1];
    for(int i = 0; i < e; ++i)
    {
        int x, y, k, q;
        cin >> x >> y >> k >> q;
        edges[x].pb({y, {k, q}});
        edges[y].pb({x, {k, q}});
    }
    bool vis[v + 1];
    for(int i = 0; i < v + 1; ++i)
        for(int j = 0; j < v + 1; ++j)
            min_dist[i][j] = LLONG_MAX;
    // find min dist for each n, klo pake ojek online edgenya, kita stop di kotanya, kalo pake ojek yg pangkalan kalo ada lebhinya, kita lanjutin
    for(int i = 1; i <= v; ++i)
    {
        // start with ojek online or pangkalan
        // if ojek online, just go to each edge and set it to minimum
        // if ojek pangkalan, it is more special
        memset(vis, 0, sizeof(vis));
        // first is dist from start, second is the current node, third is the remainder
        priority_queue<pair<int, pair<int, int>>> pq;
        for(int j = 0; j < edges[i].size(); ++j)
        {
            // daring dulu
            // pangkalan dulu nih bos 
            if(edges[i][j].second.second == 1)
            {
                // awal pangkalan lanjut daring
                // kalo jaraknya pangkalan melebihi
                if(m_p > edges[i][j].second.first)
                    pq.push({-c_p, {j, m_p - edges[i][j].second.first}}), min_dist[i][j] = min(min_dist[i][j], c_p);
                // kalo jaraknya pangkalan kurang dari sama dengan
                else
                    min_dist[i][j] = min(min_dist[i][j], c_p + c_d * (edges[i][j].second.first - m_p));
                // daring semua
                min_dist[i][j] = min(min_dist[i][j], c_d * edges[i][j].second.first);
            }
            // pangkalan
            else
            {
                // awal daring

                // pangkalan semua

            }
        }
    }
}