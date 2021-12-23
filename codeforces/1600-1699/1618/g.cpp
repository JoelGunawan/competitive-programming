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
ll res = 0;
const int lim = 400005;
struct disjoint_set {
    int head[lim], size[lim], item_cnt[lim];
    ll value[lim];
    multiset<int> active[lim], inactive[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        memset(item_cnt, 0, sizeof(item_cnt));
        memset(value, 0, sizeof(value));
        for(int i = 0; i < lim; ++i)
            size[i] = 1;
    }
    int find_head(int node) {
        while(head[node] != -1) {
            node = head[node];
        }
        return node;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[x] > size[y])
                swap(x, y);
            size[y] += size[x], item_cnt[y] += item_cnt[x], value[y] += value[x], head[x] = y;
            for(auto i : active[x])
                active[y].insert(i);
            for(auto i : inactive[x])
                inactive[y].insert(i);
            while(active[y].size() > 0 && inactive[y].size() > 0 && *--inactive[y].end() > *active[y].begin()) {
                int tmp1 = *--inactive[y].end(), tmp2 = *active[y].begin();
                value[y] += tmp1 - tmp2;
                res += tmp1 - tmp2;
                inactive[y].erase(--inactive[y].end());
                active[y].erase(active[y].begin());
                inactive[y].insert(tmp2);
                active[y].insert(tmp1);
            }
        }
        return x != y;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // make a dsu
    // and consider the case
    // such that we will have a few things to maintain in a dsu
    // the node will maintain:
    // amount of active/selected items in set, the items that are part of the set but incative/not selected, size of set
    disjoint_set dsu;
    int n, m, q, in;
    cin >> n >> m >> q;
    // fi -> val
    // se -> false: trader's item, true: monocarp's item 
    pair<int, bool> a[n + m];
    for(int i = 0; i < n; ++i) {
        cin >> in;
        a[i] = mp(in, 1);
    }
    for(int i = 0; i < m; ++i) {
        cin >> in;
        a[n + i] = mp(in, 0);
    }
    sort(a, a + n + m);
    for(int i = 0; i < n + m; ++i) {
        if(a[i].se) {
            dsu.value[i] = a[i].fi;
            res += a[i].fi;
            ++dsu.item_cnt[i];
            dsu.active[i].insert(a[i].fi);
        }
        else
            dsu.inactive[i].insert(a[i].fi);
    }
    pair<int, int> mergers[n + m - 1];
    for(int i = 0; i < n + m - 1; ++i)
        mergers[i] = mp(a[i + 1].fi - a[i].fi, i);
    sort(mergers, mergers + n + m - 1);
    pair<int, int> queries[q];
    for(int i = 0; i < q; ++i) {
        int k;
        cin >> k;
        queries[i] = mp(k, i);
    }
    sort(queries, queries + q);
    ll ans[q], idx = 0;
    for(int i = 0; i < q; ++i) {
        while(idx < n + m - 1 && mergers[idx].fi <= queries[i].fi) {
            // merge
            dsu.merge(mergers[idx].se, mergers[idx].se + 1);
            ++idx;
        }
        ans[queries[i].se] = res;
    }
    for(int i = 0; i < q; ++i)
        cout << ans[i] << endl;
    return 0;
}