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
// min query segment tree with pair
const int lim = 1 << 18;
struct segment_tree {
    pair<int, int> a[2 * lim];
    segment_tree() {
        fill(a, a + 2 * lim, mp(1e9, 1e9));
    }
    pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
        return min(a, b);
    }
    void update(int idx, int val) {
        int tmp = idx;
        idx += lim;
        a[idx] = mp(val, tmp);
        while(idx) {
            idx /= 2;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        } 
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cr < l || cl > r)
            return mp(1e9, 1e9);
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    pair<int, int> query(int l, int r) {
        return query(1, 0, lim - 1, l, r);
    }
};
segment_tree seg[2];
int a[lim];
// vals edges max n / 2
vector<int> edges[lim];
pair<int, int> vals[lim];
int seg_cnt = 1;
void solve(int l, int r) {
    // query in l, r what is the minimum
    // get the position of the minimum then find the minimum to the right of that minimum
    // what am i even talking about :D
    // query min in (l, r - 1)
    // note, we can only choose positions with dist even from l (which might be odd)
    if(l >= r)
        return;
    int idx, target, cur = seg_cnt;
    // find minimum except smallest element di range l, r
    // gampangnya sih gtu ajah :D
    // cari last element di range l, r posisinya dmn
    // harus cari di segment yg parity sama l nya itu sama tapi keep in mind bs ada penghapusan -> doesn't matter
    // cari idx -> boleh di l, asal parity sama dengna l, instead of l, do lower_bound(l)
    idx = seg[l & 1].query(l, r).se, target = seg[(l & 1) ^ 1].query(idx + 1, r).se;
    // hapus idx dan target
    // solve gni aja gapapa, tapi nanti memo aja buat jadi bentuk graf trus nanti kita harus cari lexico min yg mana
    // keren sih asli :O
    // how to memo
    seg[idx & 1].update(idx, 1e9), seg[target & 1].update(target, 1e9);
    // segmentnya di pq !!!
    vals[cur] = mp(a[idx], a[target]);
    //cout << "DEC " << seg_cnt << " " << l << " " << r << " " << a[idx] << " " << a[target] << endl;
    if(idx + 1 < target - 1) {
        ++seg_cnt;
        edges[cur].pb(seg_cnt);
        solve(idx + 1, target - 1);
    }
    if(l < idx - 1) {
        ++seg_cnt;
        edges[cur].pb(seg_cnt);
        solve(l, idx - 1);
    }
    if(target + 1 < r) {
        ++seg_cnt;
        edges[cur].pb(seg_cnt);
        solve(target + 1, r);
    }
    // untuk tiap solve, kita merge sort aja?
    // observasi: harus solve dari parity yang sama kan???
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // pilih yang awalnya 1, pilih yang awalnya dua
    // buat tandain duplikat bs pake dsu atau apa gtu
    // set jg bs
    // klo paling kanan, ignore
    // selain paling kanan, bs dipake?
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], seg[i & 1].update(i, a[i]);
    fill(vals, vals + lim, mp(1e9, 1e9));
    // how to solve inside a range? find smallest inside a range, then recursively solve
    // O(NlogN) using segment trees to maintain minimum in a range
    // create 2 rmq segment trees and we're good
    // fi -> yg mau di output ke ans, se -> nd
    solve(1, n);
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push(mp(mp(0, 0), 1));
    vector<int> ans;
    while(pq.size()) {
        pair<int, int> cr = pq.top().fi;
        int nd = pq.top().se;
        if(vals[nd] != mp(0, 0) && vals[nd] != mp((int)1e9, (int)1e9))
            ans.pb(vals[nd].fi), ans.pb(vals[nd].se);
        //cout << nd << " " << cr.fi << " " << cr.se << endl;
        pq.pop();
        for(auto i : edges[nd]) {
            //cout << "GET " << i << " " << vals[i].fi << " " << vals[i].se << endl;
            pq.push(mp(vals[i], i));
        }
    }
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    // kasih segmentnya angka nanti di dijkstra segmentnya
    return 0;
}