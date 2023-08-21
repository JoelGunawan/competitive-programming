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
const int lim = 2e5 + 5;
struct fenwick {
    vector<int> a;
    void update(int idx, int val) {
        ++idx;
        while(idx < a.size()) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int query(int idx) {
        ++idx;
        int ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;
    pair<int, int> b[m + 1];
    for(int i = 1; i <= m; ++i) {
        cin >> b[i].fi >> b[i].se;
    }
    vector<int> op[n + 1];
    for(int i = 1; i <= m; ++i) {
        op[b[i].se].pb(i);
    }
    // buat fenwick yg isinya klo kurang dr blok, dia cek tiap cycle size itu, cek jumlah train yg maintainence ada brp
    // klo yg lbh dr blok, tambah tiap bloknya manual di difference array
    const int blk = 300;
    int small[blk + 1][blk + 2], sum[blk + 1];
    int diff[m + 5], cur = 0;
    memset(diff, 0, sizeof(diff));
    memset(small, 0, sizeof(small));
    memset(sum, 0, sizeof(sum));
    for(int i = 1; i <= m; ++i) {
        // coba add or decrease based on a
        int x = b[i].se;
        int t = b[i].fi;
        if(t == 1) {
            // langsung tambahin aja
            if(a[x].fi + a[x].se > blk) {
                // langsung tambahin manual ke next nya
                // cari next x
                int nxt;
                if(ub(op[x].begin(), op[x].end(), i) != op[x].end())
                    nxt = *ub(op[x].begin(), op[x].end(), i);
                else
                    nxt = m + 1;
                for(int l = i + a[x].fi, r = i + a[x].fi + a[x].se - 1; l <= nxt; l += a[x].fi + a[x].se, r += a[x].fi + a[x].se) {
                    ++diff[l];
                    --diff[min(r + 1, nxt)];
                }
            }
            else {
                // ke small nya tambahin lgsg aja
                int sz = a[x].fi + a[x].se;
                int l = i + a[x].fi, r = i + a[x].fi + a[x].se - 1;
                l %= sz, r %= sz;
                //cout << "DEB " << l << " " << r << endl;
                if(l > r) {
                    ++small[sz][l];
                    ++small[sz][0];
                    --small[sz][r + 1];
                    ++sum[sz];
                    ++cur;
                }
                else {
                    ++small[sz][l];
                    --small[sz][r + 1];
                    ++cur;
                }
            }
        }
        else {
            if(a[x].fi + a[x].se <= blk) {
                // berarti kurangin for this cycle
                int pr = *--lb(op[x].begin(), op[x].end(), i);
                int l = pr + a[x].fi, r = pr + a[x].fi + a[x].se - 1;
                int sz = a[x].fi + a[x].se;
                l %= sz, r %= sz;
                if(l > r) {
                    --small[sz][l];
                    --small[sz][0];
                    ++small[sz][r + 1];
                    --sum[sz];
                    if((i - 1) % sz >= l || (i - 1) % sz <= r) {
                        --cur;
                    }
                }
                else {
                    --small[sz][l];
                    ++small[sz][r + 1];
                    if((i - 1) % sz >= l && (i - 1) % sz <= r)
                        --cur;
                }
            }
        }
        //cout << "BEFORE DIFF " << cur << endl;
        cur += diff[i];
        for(int j = 2; j <= blk; ++j) {
            if(i % j == 0)
                cur -= sum[j] - small[j][j];
            cur += small[j][i % j];
        }
        cout << cur << endl;
    }
    return 0;
}