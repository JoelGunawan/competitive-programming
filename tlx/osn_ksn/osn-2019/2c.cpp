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
const int lim = 2e5 + 5;
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
    int n, s, q;
    cin >> n >> s >> q;
    disjoint_set dsu;
    int sum = 0;
    vector<pair<pair<int, bool>, int>> sweep;
    for(int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        sum += t;
        for(int j = 0; j < t; ++j) {
            int a, b;
            cin >> a >> b;
            sweep.pb(mp(mp(a, 0), i));
            sweep.pb(mp(mp(b, 1), i));
        }
    }
    int cur_component, cnt = 0;
    sort(sweep.begin(), sweep.end());
    for(auto i : sweep) {
        int person = i.se, type = i.fi.se;
        if(type)
            --cnt;
        else {
            if(cnt)
                dsu.merge(cur_component, person);
            ++cnt;
            cur_component = dsu.find_head(person);
        }
    }
    for(int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        cout << dsu.size[dsu.find_head(x)] << endl;
    }
    return 0;
}