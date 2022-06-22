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
const int lim = 3e5 + 5;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> even_edge, odd_edge;
    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w & 1)
            odd_edge.pb(mp(mp(u, v), i + 1));
        else
            even_edge.pb(mp(mp(u, v), i + 1));
    }
    // bagi odd_edge jadi 2:
    // odd_edge crucial
    // odd_edge optional
    disjoint_set even;
    for(auto i : even_edge) {
        even.merge(i.fi.fi, i.fi.se);
    }
    vector<pair<pair<int, int>, int>> crucial_odd, optional_odd;
    disjoint_set odd;
    for(auto i : odd_edge) {
        if(even.merge(i.fi.fi, i.fi.se))    
            crucial_odd.pb(i);
        else if(odd.merge(i.fi.fi, i.fi.se))
            optional_odd.pb(i);
        odd.merge(i.fi.fi, i.fi.se);
    }
    disjoint_set res;
    if(crucial_odd.size() % 2 == 0 || optional_odd.size()) {
        vector<int> ans;
        for(auto i : crucial_odd)
            res.merge(i.fi.fi, i.fi.se), ans.pb(i.se);
        if(crucial_odd.size() & 1)
            res.merge(optional_odd.front().fi.fi, optional_odd.front().fi.se), ans.pb(optional_odd.front().se);
        for(auto i : even_edge) {
            if(res.merge(i.fi.fi, i.fi.se))
                ans.pb(i.se);
        }
        cout << "YES" << endl;
        for(auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}