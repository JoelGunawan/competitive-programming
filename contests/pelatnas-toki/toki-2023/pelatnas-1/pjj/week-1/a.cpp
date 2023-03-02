// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O2")
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
// offline solution
const int lim = 250005;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    int query(int idx) {
        int res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    map<int, int> comp1, comp2;
    for(int i = 1; i <= n; ++i)
        ++comp1[a[i]];
    int q;
    cin >> q;
    vector<int> b[q];
    pair<int, pair<int, int>> query[2 * q];
    for(int i = 0; i < q; ++i) {
        int x, y, k;
        cin >> x >> y >> k;
        query[2 * i] = mp(x - 1, mp(k, i));
        query[2 * i + 1] = mp(y, mp(k, i));
        ++comp1[k];
    }
    int cur = 0;
    for(auto i : comp1) {
        comp2[i.fi] = ++cur;
    }
    for(int i = 1; i <= n; ++i)
        a[i] = comp2[a[i]];
    for(int i = 0; i < 2 * q; ++i)
        query[i].se.fi = comp2[query[i].se.fi];
    fenwick bit;
    sort(query, query + 2 * q);
    int cur_idx = 0;
    for(auto i : query) {
        while(cur_idx < i.fi) {
            ++cur_idx;
            bit.upd(a[cur_idx], 1);
        }
        b[i.se.se].pb(cur_idx - bit.query(i.se.fi));
    }
    for(int i = 0; i < q; ++i) {
        cout << abs(b[i].back() - b[i].front()) << endl;
    }
    return 0;
}