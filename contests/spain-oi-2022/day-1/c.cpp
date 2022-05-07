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
map<pair<int, int>, bool> exists, vis;
vector<pair<int, int>> nxt = {{0, 1}, {0, -1}};
int dfs(int x, int y) {
    vis[mp(x, y)] = 1;
    int tmp = 1;
    for(auto i : nxt) {
        if(!vis[mp(x + i.fi, y + i.se)] && exists[mp(x + i.fi, y + i.se)])
            tmp += dfs(x + i.fi, y + i.se);
    }
    return tmp;
}
void tc() {
    int n;
    scanf("%d", &n);
    vis.clear();
    exists.clear();
    int f[n], c[n];
    for(int i = 0; i < n; ++i)
        scanf("%d%d", &f[i], &c[i]);
    for(int i = 0; i < n; ++i) {
        if(c[i] & 1)
            c[i] = -(c[i] / 2);
        else
            c[i] /= 2;
        exists[mp(f[i], c[i])] = 1;
    }
    // now just figure out whether they are connected
    if(dfs(f[0], c[0]) == n)
        printf("SI\n");
    else
        printf("NO\n");
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        tc();
    }
    return 0;
}