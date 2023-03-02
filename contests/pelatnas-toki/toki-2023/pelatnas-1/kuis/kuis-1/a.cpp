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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // fi -> tingkat keindahan, se -> panjang
    // cari --lower_bound
    set<pair<int, int>> s[n + 1];
    for(int i = 1; i <= n; ++i) {
        s[i].ins(mp(-1, 0));
    }
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // cari longest paths
        // longest paths jadi seperti LIS (cuma simpan tingkat keindahan)
        // v ngambil dari u
        pair<int, int> tmp = *--s[u].lower_bound(mp(w, 0));
        if((*--s[v].lower_bound(mp(w + 1, 0))).se < tmp.se + 1) {
            while(s[v].lower_bound(mp(w, 0)) != s[v].end() && (*s[v].lower_bound(mp(w, 0))).se <= tmp.se + 1) {
                s[v].erase(s[v].lower_bound(mp(w, 0)));
            }
            s[v].ins(mp(w, tmp.se + 1));
        }
        // cout << v << " " << (*--s[v].end()).se << endl;
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        res = max(res, (*--s[i].end()).se);
    }
    cout << res << endl;
    return 0;
}