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
const int lim = 1 << 20;
struct segment_tree {
    pair<int, int> a[2 * lim];
    set<pair<int, int>> b[lim];
    segment_tree() {
        for(int i = 0; i < 2 * lim; ++i)
            a[i] = mp(1e9, 1e9);
    };
    void upd(int idx, pair<int, int> c) {
        idx += lim;
        b[idx - lim].ins(c);
        a[idx] = min(a[idx], c);  
        idx >>= 1;
        while(idx) {
            a[idx] = min(a[2 * idx], a[2 * idx + 1]);
            idx >>= 1;
        }
    }
    void erase(int idx, pair<int, int> c) {
        //cout << "DEL " << idx << " " << c.fi << " " << c.se << endl;
        idx += lim;
        b[idx - lim].erase(b[idx - lim].find(c));
        if(b[idx - lim].size() == 0)
            a[idx] = mp(1e9, 1e9);
        else
            a[idx] = *b[idx - lim].begin();  
        idx >>= 1;
        while(idx) {
            a[idx] = min(a[2 * idx], a[2 * idx + 1]);
            idx >>= 1;
        }
    }
    pair<int, int> query(int idx, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r)
            return a[idx];
        else if(cl > r || cr < l) {
            return mp(1e9, 1e9);
        }
        else {
            int mid = (cl + cr) >> 1;
            return min(query(2 * idx, cl, mid, l, r), query(2 * idx + 1, mid + 1, cr, l, r));
        }
    }
};
struct disjoint_set {
    set<int> elems[lim];
    int sz[lim], h[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        while(h[nd] != -1) {
            nd = h[nd];
        }
        return nd;
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            for(auto i : elems[y])
                elems[x].ins(i);
            elems[y].clear();
            //cout << "MERGE " << x << " " << y << endl;  
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    segment_tree seg;
    disjoint_set dsu;
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        dsu.elems[i].ins(a[i]);
        seg.upd(1, mp(a[i], i));
    }
    // this is a dsu
    // save indices and numbers in the dsu
    // in the end, sort every dsu
    // process from position 1 to n, put the smallest element as far forward as possible
    // cek, di posisi skrg size berapa
    // cari posisi lain dengan angka terkecil yang sizenya memenuhi
    // sz <= k - cur
    // buat segment tree rmq
    // find minimum elem
    int ans[n + 1];
    for(int i = 1; i <= n; ++i) {
        int tmp2 = dsu.fh(i);
        pair<int, int> tmp = seg.query(1, 0, lim - 1, 1, k - dsu.sz[tmp2]);
        //cout << "QUERY " << tmp.fi << " " << tmp.se << endl;
        if(*dsu.elems[tmp2].begin() < tmp.fi || tmp.se == tmp2) {
            seg.erase(dsu.sz[tmp2], mp(*dsu.elems[tmp2].begin(), tmp2));
            ans[i] = *dsu.elems[tmp2].begin();
            dsu.elems[tmp2].erase(dsu.elems[tmp2].begin());
            if(dsu.elems[tmp2].size()) {
                seg.upd(dsu.sz[tmp2], mp(*dsu.elems[tmp2].begin(), tmp2));
            }
            continue;
        }
        ans[i] = tmp.fi;
        seg.erase(dsu.sz[tmp.se], tmp);
        seg.erase(dsu.sz[tmp2], mp(*dsu.elems[tmp2].begin(), tmp2));
        dsu.elems[tmp.se].erase(dsu.elems[tmp.se].begin());
        dsu.merge(tmp.se, tmp2);
        if(dsu.elems[dsu.fh(tmp.se)].size()) {
            seg.upd(dsu.sz[dsu.fh(tmp.se)], mp(*dsu.elems[dsu.fh(tmp.se)].begin(), dsu.fh(tmp.se)));
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}