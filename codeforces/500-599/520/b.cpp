// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    bool vis[20005];
    queue<pair<int, int>> bfs;
    while(bfs.size()) {
        int nd = bfs.front().fi, depth = bfs.front().se;
        bfs.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        if(nd == m) {
            cout << depth << endl;
            return 0;
        }
        if(2 * n <= 20000 && !vis[2 * n])
            bfs.push({2 * n, depth + 1});
        if(n - 1 > 0 && !vis[n - 1])
            bfs.push({n - 1, depth + 1});
    }
    return 0;
}