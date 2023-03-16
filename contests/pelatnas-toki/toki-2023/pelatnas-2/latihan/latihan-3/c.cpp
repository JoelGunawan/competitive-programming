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
struct node {
    // jangan lupa clear obj habis di naikin ke parnya :D
    int l = -1, r = -1, cnt = 0, mindiff = 2e9;
};
ll res = 0;
struct trie_obj {
    vector<node> nd = {node()};
    void update(int num, int depth, int idx) {
        ++nd[idx].cnt;
        //cout << "UPDATE " << num << " " << depth << " " << idx << endl;
        if(depth == -1) {
            return;
        }
        if((1 << depth) & num) {
            // go right
            if(nd[idx].r == -1)
                nd[idx].r = nd.size(), nd.pb(node());
            update(num, depth - 1, nd[idx].r);
        }
        else {
            // go left
            if(nd[idx].l == -1)
                nd[idx].l = nd.size(), nd.pb(node());
            update(num, depth - 1, nd[idx].l);
        }
    }
    void dfs(int idx, int depth) {
        //cout << idx << " " << nd[idx].l << " " << nd[idx].r << endl;
        if(nd[idx].l != -1)
            dfs(nd[idx].l, depth - 1);
        if(nd[idx].r != -1)
            dfs(nd[idx].r, depth - 1);
        if(nd[idx].l != -1 && nd[idx].r != -1 && depth != -1) {
            // cari diff left dan right
            res += get_res(nd[idx].l, nd[idx].r, depth - 1);
            res += 1 << depth;
        }
    }
    int get_res(int idx1, int idx2, int depth) {
        if(depth == -1)
            return 0;
        else {
            int ret = 2e9;
            if(nd[idx1].l != -1 && nd[idx2].l != -1)
                ret = min(ret, get_res(nd[idx1].l, nd[idx2].l, depth - 1));
            if(nd[idx1].r != -1 && nd[idx2].r != -1)
                ret = min(ret, get_res(nd[idx1].r, nd[idx2].r, depth - 1));
            if(ret == 2e9) {
                // antara l ke r, atau r ke l
                if(nd[idx1].l != -1 && nd[idx2].r != -1)
                    ret = min(ret, (1 << depth) + get_res(nd[idx1].l, nd[idx2].r, depth - 1));
                if(nd[idx1].r != -1 && nd[idx2].l != -1)
                    ret = min(ret, (1 << depth) + get_res(nd[idx1].r, nd[idx2].l, depth - 1));
            }
            return ret;
        }
    }
    // dari situ pergi ke par, terus nanti di tiap index, kita merge semuanya pairwise? -> no, we find closest to a certain object :D
};
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    // buat trie structure, mulai dari 29, kalo satunya kosong, berarti gaperlu tambahin ke cost, kali satunya ga kosong, berarti tambahin cur ke cost
    // ntar di bawahnya juga dilakuin sama lagi
    // cost buat sambungin kiri dan kanan itu berapa? cari serendah mungkin dari 2 itu yang sama
    // nanti kita bakal pake cost itu buat gabung keduanya
    // bisa pakai set biar gampang, ntar observasinya tiap objek di cek maks log kali -> wrong, nanti dia bisa cek lebih dari log kali
    // soal trie :D
    // ksn 2021 2b???
    // pake xor??
    // pakai dsu, pakai xor? cari dari gap yang paling kecil?
    // gabisa, karena di ksn 2021 1b klo g salah dia ada edge klo xor = 0 dan cmn ditanya connectivity, bkn min cost
    // minimize, start from smallest xors
    // go to larger ones
    // pakai konsep small to large, nanti maks logn
    // nlog^2n atau nlogn
    int n;
    cin >> n;
    trie_obj tri;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        tri.update(x, 29, 0);
    }
    tri.dfs(0, 29);
    cout << res << endl;
    return 0;
}