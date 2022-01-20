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
vector<int> edges[100001];
int arr[17][100001], depth[100001];
bool vis[100001];
vector<int> anc;
void dfs(int nd, int d) {
    vis[nd] = 1;
    depth[nd] = d;
    int tmp1 = 1, tmp2 = 0;
    while(tmp1 <= anc.size()) {
        arr[tmp2][nd] = anc[anc.size() - tmp1];
        tmp1 *= 2, ++tmp2; 
    }
    anc.pb(nd);
    for(auto i : edges[nd]) {
        if(!vis[i])
            dfs(i, d + 1);
    }
    anc.pop_back();
}
int lca(int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    for(int i = 16; i >= 0; --i) {
        if(depth[a] - (1 << i) >= depth[b]) {
            a = arr[i][a];
        }
    }
    if(a == b)
        return a;
    for(int i = 16; i >= 0; --i) {
        if(arr[i][a] != arr[i][b]) {
            a = arr[i][a], b = arr[i][b];
        }
    }
    return arr[0][a];
}
int get_dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}
int solve(int s, int f, int t) {
    // get distance between 2 nodes
    // check distance between s to f, t to f and s to t
    return (get_dist(s, f) + get_dist(t, f) - get_dist(s, t)) / 2 + 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(arr, -1, sizeof(arr));
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; ++i) {
        int p;
        cin >> p;
        edges[i + 2].pb(p);
        edges[p].pb(i + 2);
    }
    dfs(1, 0);
    for(int i = 0; i < q; ++i) {
        vector<int> x(3);
        for(int j = 0; j < 3; ++j)
            cin >> x[j];
        sort(x.begin(), x.end());
        int res = 0;
        do {
            //cout << x[0] << " " << x[1] << " " << x[2] << " " << solve(x[0], x[1], x[2]) << endl;
            res = max(res, solve(x[0], x[1], x[2]));
        } while(next_permutation(x.begin(), x.end()));
        cout << res << endl;
    }
    return 0;
}