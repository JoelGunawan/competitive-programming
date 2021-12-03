#include <bits/stdc++.h>
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pf push_front
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    int b[n], p[n], root;
    for(int i = 0; i < n; ++i)
    {
        cin >> b[i];
        --b[i];
        if(b[i] == i)
            root = i;
    }
    for(int i = 0; i < n; ++i)
        cin >> p[i], --p[i];
    vector<int> children[n + 1];
    for(int i = 0; i < n; ++i)
        if(i != root)
            children[b[i]].pb(i);
    int dist[n], cur_dist = 0; memset(dist, -1, sizeof(dist));
    dist[root] = 0;
    int vertex[n]; 
    memset(vertex, -1, sizeof(vertex));
    bool available[n]; 
    memset(available, 0, sizeof(available));
    available[root] = 1;
    for(int i = 0; i < n; ++i)
    {
        if(!available[p[i]])
        {
            cout << -1 << endl;
            return;
        }
        else
        {
            dist[p[i]] = cur_dist;
            vertex[p[i]] = cur_dist - dist[b[p[i]]];
            ++cur_dist;
            for(int j = 0; j < children[p[i]].size(); ++j)
                available[children[p[i]][j]] = 1;
        }
    }
    for(int i = 0; i < n; ++i)
        cout << vertex[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}