// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,avx2,mmx,tune=native")
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
// simpan 5 largest values in every segment, simpan yg angka terkecil
// kalo ada banyak yg tied for 5th place? 
// obs: harus lebih dr n / 5 di at least 1 segment
// jadi cuma perlu simpan 5 aja gapapa harusnya...
// klo mau lebih cepet harusnya bs sparse table?
const int lim = 1 << 19;
vector<int> a[lim];
struct segment_tree {
    vector<int> arr[2 * lim];
    void build(int nd, int cl, int cr) {
        if(cl == cr)
            return;
        else {
            // merge antara 2 child
            int mid = (cl + cr) / 2;
            build(2 * nd, cl, mid);
            build(2 * nd + 1, mid + 1, cr);
            int cnt = 0;
            for(auto i : arr[2 * nd])
                if(upper_bound(a[i].begin(), a[i].end(), cr) - lower_bound(a[i].begin(), a[i].end(), cl) >= (cr - cl + 1) / 5)
                    arr[nd].pb(i), ++cnt;
            for(auto i : arr[2 * nd + 1])
                if(upper_bound(a[i].begin(), a[i].end(), cr) - lower_bound(a[i].begin(), a[i].end(), cl) >= (cr - cl + 1) / 5)
                    arr[nd].pb(i);
            inplace_merge(arr[nd].begin(), arr[nd].begin() + cnt, arr[nd].end());
            arr[nd].resize(unique(arr[nd].begin(), arr[nd].end()) - arr[nd].begin());
        }
    }
    void query(int nd, int cl, int cr, int l, int r, vector<int> &v) {
        if(cl >= l && cr <= r) {
            //cout << "NODE " << nd << " " << cl << " " << cr << " " << l << " " << r << endl;
            for(auto i : arr[nd])
                v.pb(i);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            query(2 * nd, cl, mid, l, r, v);
            query(2 * nd + 1, mid + 1, cr, l, r, v);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    // push 0 dan n + 1 biar g ngebug di a
    // a query cari antara range l ke r ada berapa okurens
    int val[n + 1];
    segment_tree seg;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        val[i] = x;
        seg.arr[i + lim].pb(x);
        a[x].pb(i);
    }
    seg.build(1, 0, lim - 1);
    // sparse table?
    // NlogN noes
    // build tiap node butuh O(log^2)
    // same shit lah haiya
    for(int qe = 0; qe < q; ++qe) {
        int l, r, k;
        cin >> l >> r >> k;
        // yang salah kemungkinan besar pos
        // segtree salah
        if(k == 0) {
            cout << 1 << endl;
            continue;
        }
        vector<int> pos;
        seg.query(1, 0, lim - 1, l, r, pos);
        int ans = -1;
        // gimana kalo proses query terpisah?
        // harusnya ttp 
        for(auto i : pos) {
            // buat tanpa query harusnya bisa
            // jangan lower_bound queries, instead buat ke precompute aja
            // bisa jadi lebih cepet?
            if(lower_bound(a[i].begin(), a[i].end(), r + 1) - lower_bound(a[i].begin(), a[i].end(), l) >= k) {
                if(ans == -1)
                    ans = i;
                else
                    ans = min(ans, i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}