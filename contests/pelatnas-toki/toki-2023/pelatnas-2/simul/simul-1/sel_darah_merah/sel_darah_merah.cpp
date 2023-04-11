#include "sel_darah_merah.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 19;
struct segment_tree {
    multiset<int> a[2 * lim];
    void update(int nd, int cl, int cr, int idx, int val) {
        a[nd].insert(val);
        if(cl == cr)
            return;
        int mid = (cl + cr) / 2;
        if(idx <= mid)
            update(2 * nd, cl, mid, idx, val);
        else
            update(2 * nd + 1, mid + 1, cr, idx, val);
    }
    void erase(int nd, int cl, int cr, int idx, int val) {
        a[nd].erase(a[nd].find(val));
        if(cl == cr)
            return;
        int mid = (cl + cr) / 2;
        if(idx <= mid)
            erase(2 * nd, cl, mid, idx, val);
        else    
            erase(2 * nd + 1, mid + 1, cr, idx, val);
    }
    // cari r terkecil such that minimum is leq x
    int query(int nd, int cl, int cr, int x) {
        //cout << cl << " " << cr << " " << (*a[nd].begin()) << endl;
        if(cr < x || a[nd].size() == 0 || (*a[nd].begin()) > x)
            return 2e9;
        if(cl == cr && (*a[nd].begin()) <= x)
            return cl;
        int mid = (cl + cr) / 2;
        // cek kiri kanan
        // kalo bisa ke kiri, ya ambil yg kiri aja tapi masalahnya blum tntu bs karena bs jadi
        int tmp = query(2 * nd, cl, mid, x);
        if(tmp == 2e9)
            return query(2 * nd + 1, mid + 1, cr, x);
        else
            return tmp;
    }
};
segment_tree seg;
void initialize(int N, vector<int> L, vector<int> R) {
    // sort s[i]
    // sort by l[i], pilih r[i] terkecil -> q = 1
    // cari yg dr terkecil?
    // sum of s[i] <= 200000 -> sqrt/log/block?
    // small s[i] -> just check manually for each s[i]
    // process pake lazy segtree, depan ke belakang sm belakang ke depan dua"nya harus bisa
    // yang depan ke belakang proses by lazy kurangin tiap posisi, buat yang belakang ke depan lakuin yg sama tp kebalik
    // depan ke belakang -> only consider r[i]
    // belakang ke depan -> only consider l[i]
    // fakesolve: s n s
    // forward to back -> ambil segment
    // back to forward -> ambil segment
    // cuman 1 point, determine count in one point, pilih yg r terkecil sebanyak s[i]
    // buat global set yg nanti bakal di refill setelah dipake, observasinya itu bs pake semacam persistent nanti di reset ke previous state sebelum di modif
    // remove all s[i] segments manually by maintaining inside a segment tree the active segment ids in each node using lazy
    // find segment with smallest R such that L <= S <= R
    // use dyn 2d seg?
    // use pers seg?
    // seg method: for every index R maintain minimum L
    // binser minimum R that has L less than S
    // O(logn)
    // update -> update the minimum L at posistion R
    // every query -> reset by undo operations (just simply insert back)
    // bisa pakai pq di node segment tree
    // pq -> only bottom aja, sisanya pake normal
    // O(Nlog^2N) time O(NlogN) memory
    for(int i = 0; i < N; ++i)
        seg.update(1, 0, lim - 1, R[i], L[i]);
}

bool configurationExists(int M, vector<int> S) { 
    sort(S.begin(), S.end());
    vector<pair<int, int>> del;
    bool ans = 1;
    // per query maks 100000
    // di tiap node simpan yang count <= x
    // pake pbds? tapi itu terlalu lemot juga...
    // nanti harus erase semua terus re insert
    // fukkkkkk gmn pbds gw lupa WKWKWK
    // eh tp pbds multiset broken deh
    // buat sparse segment tree di dalam tiap node dimana bs update O(log)
    // implement nanti
    // jadi 2d sparse seg
    // cari quanitity yg kurang pake query semua antara L kurang dari dan R lebih dari
    // nanti ditambah ulang
    for(auto i : S) {
        for(int j = 0; j < i; ++j) {
            if(seg.query(1, 0, lim - 1, i) == 2e9) {
                ans = 0;
                break;
            }
            else {
                int idx = seg.query(1, 0, lim - 1, i);
                // remove
                int val = *seg.a[lim + idx].begin();
                seg.erase(1, 0, lim - 1, idx, val);
                del.push_back({idx, val});
            }
        }
        if(!ans)
            break;
    }
    for(auto i : del)
        seg.update(1, 0, lim - 1, i.first, i.second);
    return ans;
}