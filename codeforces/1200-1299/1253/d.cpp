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
    int head[200001], size[200001];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + 200001, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[y] > size[x])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
disjoint_set dsu;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int merge_cnt = 0;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    int prev[n + 1], res = 0;
    memset(prev, -1, sizeof(prev));
    for(int i = 1; i <= n; ++i) {
        if(prev[dsu.find_head(i)] != i - 1 && prev[dsu.find_head(i)] != -1) {
            for(int j = prev[dsu.find_head(i)] + 1; j < i; ++j) {
                if(dsu.merge(i, j)) {
                    ++res;
                }
            }
        }
        prev[dsu.find_head(i)] = i;
    }
    cout << res << endl;
    return 0;
}