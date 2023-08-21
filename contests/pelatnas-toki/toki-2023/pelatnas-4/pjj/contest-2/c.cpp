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
const int lim = 1 << 18;
bool used[lim];
struct segment_tree {
    vector<int> a[2 * lim];
    void query(int nd, int cl, int cr, int idx, vector<int> &v) {
        // put in a and not in b
        for(auto i : a[nd])
            v.pb(i);
        a[nd].clear();
        if(cl == cr) {
            return;
        }
        int mid = (cl + cr) / 2;
        if(idx <= mid)
            query(2 * nd, cl, mid, idx, v);
        else
            query(2 * nd + 1, mid + 1, cr, idx, v);
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        if(cl >= l && cr <= r) {
            a[nd].pb(val);
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // sub 1 -> greedy terjauh
    // sub 2, 3 -> DP[L][R], bisa go left atau go right tiap iterasi, nanti max n^2 state, tiap transisi O(1)
    // obs: mis skrg di range L, R
    // belum tentu opt ambil furthest L/R
    // bagi kasus jadi 3:
    // extend L -> consider with minimum L
    // extend R -> consider with maximum R
    // extend L dan R -> technically should consider all?
    // mst?
    // possible case: a bisa ke b, b tdk bisa ke a (this makes every origin point unique)
    // only consider 2 states, index of left and index of right
    // only issue: extend BOTH L and R
    // extend L/R -> can be done separately
    // L dan R means taking a supersegment of the current segment
    // dp memo simpan dr L, R ke 1, N itu butuh berapa
    // obs: order does not really matter (only matter for unlock)
    // jadi graph, jika a bisa ke b, maka edge a -> b
    // minimum edges to connect containing nodes yg bs ke 1 dan node yg bs ke n
    // "problem": common edges
    // precalculate dr tiap node ke 1, n tanpa common edge
    // nanti cri shortest dr sebuah node ke node lain
    // pakai segment tree instead of pq, nanti tinggal min query buat cek
    // bisa pakai vis/no vis trus di lazy prop di add param itu
    // precalculate independent
    // precalculate joint
    // nanti mulai dari least cost dihitung dr 1, n nanti di invert edgenya
    // pola: 
    // j j j j j (independent routing to 1 and to n)
    int n;
    cin >> n;
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;
    // buat segtree min query pair buat cari mana yg mau diubah
    // buat dari 1
    // fi -> cost
    // se -> node
    int from_one[n + 1], from_n[n + 1], total[n + 1];
    memset(from_one, -1, sizeof(from_one));
    memset(from_n, -1, sizeof(from_n));
    memset(total, -1, sizeof(total));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    segment_tree seg_one, seg_n, seg_all;
    for(int i = 1; i <= n; ++i) {
        if(a[i].fi == 1) {
            pq.push(mp(0, i));
        }
        else {
            seg_one.update(1, 0, lim - 1, a[i].fi, a[i].se, i);
        }
    }
    while(pq.size()) {
        int cost = pq.top().fi, nd = pq.top().se;
        from_one[nd] = cost;
        pq.pop();
        vector<int> r;
        seg_one.query(1, 0, lim - 1, nd, r);
        for(auto i : r) {
            if(used[i])
                continue;
            used[i] = 1;
            pq.push(mp(cost + 1, i));
        }
    }
    // buat dari n
    for(int i = 1; i <= n; ++i) {
        if(a[i].se == n) {
            pq.push(mp(0, i));
        }
        else
            seg_n.update(1, 0, lim - 1, a[i].fi, a[i].se, i);
    }
    memset(used, 0, sizeof(used));
    while(pq.size()) {
        int cost = pq.top().fi, nd = pq.top().se;
        from_n[nd] = cost;
        pq.pop();
        vector<int> r;
        seg_n.query(1, 0, lim - 1, nd, r);
        for(auto i : r) {
            if(used[i])
                continue;
            used[i] = 1;
            pq.push(mp(cost + 1, i));
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(from_one[i] != -1 && from_n[i] != -1) {
            total[i] = from_one[i] + from_n[i] + 1;
            pq.push(mp(from_one[i] + from_n[i], i));
            seg_all.update(1, 0, lim - 1, a[i].fi, a[i].se, i);
        }
    }
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    while(pq.size()) {
        int cost = pq.top().fi, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        total[nd] = min(total[nd], cost + 1);
        vis[nd] = 1;
        vector<int> r;
        used[nd] = 1;
        seg_all.query(1, 0, lim - 1, nd, r);
        for(auto i : r) {
            if(used[i])
                continue;
            pq.push(mp(cost + 1, i));
            used[i] = 1;
        }
    }
    //for(int i = 1; i <= n; ++i) {
    //    cout << from_one[i] << " " << from_n[i] << " " << total[i] << endl;
    //}
    // irrelevant as calculate for every n, jadi calc dulu bru input !!!
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << total[x] << endl;
    }
    return 0;
}