// aku nyalain do not disturb :D
#include <bits/stdc++.h>
#define endl "\n"
#define ins insert
using namespace std;
const int lim = 1 << 19;
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
    }
};
struct segment_tree {
    int a[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        cout << "UPD " << idx << " " << val << endl;
        idx += lim;
        a[idx] = val;
        while(idx) {
            idx >>= 1;
            a[idx] = min(a[2 * idx], a[2 * idx + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int x) {
        if(a[nd] >= x)
            return 1e9;
        else if(cr < l)
            return 1e9;
        else if(cl == cr) {
            cout << cl << " " << a[nd] << endl;
            return cl;
        }
        else {
            // coba query kiri dan kanan
            int mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, x), query(2 * nd + 1, mid + 1, cr, l, x));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // ideas:
    // use persistent ds (hampir pasti pakai)
    // masalah: gmn cara determine closest active sekarang
    // ide 1: pakai segment tree, karena stack tidak bisa
    // observasi: cari maximum closest that is active
    // transisi active ribet karena bisa transisi n / 2 element
    // 
    // coba pahami soal by sampah sub 1, 2
    // sub 1, find closest active manually, nanti ubah activenya jg manual
    int n, sub;
    cin >> n >> sub;
    int val[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    int nxt[n + 1];
    memset(nxt, -1, sizeof(nxt));
    int a[n + 1];
    disjoint_set dsu;
    segment_tree seg;
    for(int i = n; i >= 1; --i) {
        if(val[i] > 0) {
            // berarti 
            // cari closest undo yang memenuhi
            // closest di kanan < 0
            // bisa pakai binser on segtree
            // try to find closest undo to the right
            // kalo ga ada, berarti elemen ini berdiri sendiri di dsunya
            int nx = seg.query(1, 0, lim - 1, i + 1, 0);
            if(nx != 1e9) {
                cout << "MERGE " << nx << " " << i << endl;
                dsu.merge(nx, i);
                seg.upd(nx, 0);
            }
            a[dsu.fh(i)] = val[i];
        }
        else {
            // berarti
            // cari closest di kanan yang < val[i]
            // kalo ada dsunya berarti nanti remove aja
            // find smallest r such that seg.q(i + 1, r) < val[i]
            // kalo gada berarti undo ini berdiri sendiri di dsunya
            // kalo ada, di merging sm previous dsu, terus hapus yg lama
            int nx = seg.query(1, 0, lim - 1, i + 1, val[i]);
            if(nx != 1e9) {
                cout << "MERGE " << nx << " " << i << endl;
                dsu.merge(nx, i);
                seg.upd(nx, 0);
            }
            seg.upd(i, val[i]);
        }
        // obs:
        // cari index ter depan yang bs
        // nanti index ter depan di update jadi 0
    }
}