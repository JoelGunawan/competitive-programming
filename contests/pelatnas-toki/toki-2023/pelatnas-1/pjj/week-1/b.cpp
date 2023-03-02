// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
// do both online and offline solution
// online solution using pers segment tree smh
// offline solution
const int lim = 1e6 + 5;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        if(idx == 0)
            return;
        while(idx < lim) {
            if(idx == 0)
                return;
            a[idx] += val;
            idx += idx&-idx;
        }
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
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int last_index[lim];
    memset(last_index, 0, sizeof(last_index));
    int q;
    cin >> q;
    pair<pair<int, int>, int> query[q];
    for(int i = 0; i < q; ++i) {
        cin >> query[i].fi.se >> query[i].fi.fi;
        query[i].se = i;
    }
    int ans[q];
    sort(query, query + q);
    int cur_idx = 0;
    fenwick bit;
    for(auto i : query) {
        while(cur_idx < i.fi.fi) {
            ++cur_idx;
            if(last_index != 0)
                bit.upd(last_index[a[cur_idx]], -1);
            last_index[a[cur_idx]] = cur_idx;
            bit.upd(cur_idx, 1);
        }
        ans[i.se] = bit.query(i.fi.se, i.fi.fi);
    }
    for(auto i : ans)
        cout << i << endl;
    return 0;
}