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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
struct disjoint_set {
    vector<int> h, sz;
    vector<vector<int>> cnt;
    int lim;
    void build() {
        h.resize(lim, -1);
        sz.resize(lim, 1);
        cnt = vector<vector<int>>(lim, vector<int>(26, 0));
    }
    int fh(int nd) {
        while(h[nd] != -1)
            nd = h[nd];
        return nd;
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            for(int i = 0; i < 26; ++i)
                cnt[x][i] += cnt[y][i];
        }
    }
};
void tc() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    disjoint_set dsus, dsut;
    dsus.lim = dsut.lim = n;
    dsus.build(), dsut.build();
    for(int i = 0; i < n; ++i) {
        dsus.cnt[i][s[i] - 'a']++;
        dsut.cnt[i][t[i] - 'a']++;
    }
    for(int i = 0; i < n; ++i) {
        if(i + k < n)
            dsus.merge(i, i + k), dsut.merge(i, i + k);
        if(i + k + 1 < n)
            dsus.merge(i, i + k + 1), dsut.merge(i, i + k + 1);
    }
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i) {
        if(!vis[dsus.fh(i)]) {
            vis[dsus.fh(i)] = 1;
            if(dsus.cnt[dsus.fh(i)] != dsut.cnt[dsut.fh(i)]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}