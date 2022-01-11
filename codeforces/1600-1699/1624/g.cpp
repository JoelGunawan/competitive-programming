// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
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
struct disjoint_set {
    int head[200005], size[200005];
    void reset(int s) {
        for(int i = 0; i <= s; ++i)
            head[i] = -1, size[i] = 1;
    }
    int find_head(int node) {
        while(head[node] != -1)
            node = head[node];
        return node;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        //cout << a << " " << b << endl;
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            head[y] = x, size[x] += size[y];
        }
        return x != y;
    }
};
int msb(int a) {
    int tmp = 1, x = 0;
    while(tmp * 2 <= a)
        tmp *= 2, ++x;
    return x;
}
struct disjoint_set dsu;
void tc() {
    int n, m;
    cin >> n >> m;
    int r = 31, res = 0;
    // organize by most significant bit
    vector<pair<int, pair<int, int>>> edges[31];
    vector<pair<int, int>> free;
    for(int i = 0; i < 31; ++i)
        edges[i] = vector<pair<int, pair<int, int>>>();
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[msb(w)].pb(mp(w, mp(u, v)));
    }
    for(int i = 0; i < 31; ++i) {
        dsu.reset(n);
        for(pair<int, int> x : free) {
            dsu.merge(x.fi, x.se);
        }
        if(dsu.size[dsu.find_head(1)] == n)
            break;
        for(int j = 0; j < r; ++j) {
            for(pair<int, pair<int, int>> p : edges[j])
                dsu.merge(p.se.fi, p.se.se);
            if(dsu.size[dsu.find_head(1)] == n) {
                r = j;
                res += 1 << j;
                // reorganize edges
                for(int i = 30; i > r; --i)
                    edges[i].clear();
                for(pair<int, pair<int, int>> p : edges[j]) {
                    if(p.fi - (1 << j) != 0)
                        edges[msb(p.fi - (1 << j))].pb(mp(p.fi - (1 << j), p.se));
                    else
                        free.pb(p.se);
                }
                edges[j].clear();
                break;
            }
        }
    } 
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}