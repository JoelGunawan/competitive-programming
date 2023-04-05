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
int mod = 1e9 + 7;
struct items {
    int dim, nd, dist, is_first;
};
const int lim = 1 << 17;
struct segment_tree {
    // replace zero with LLONG_MIN for max query
    // replace zero with LLONG_MAX for min query
    long long a[2 * lim], arr_size = lim, zero = 0;
    segment_tree() {
        fill(a, a + 2 * lim, zero);
    }
    long long merge(long long a, long long b) {
        return (a * b) % mod;
    }
    void update(int idx, long long val) {
        idx += arr_size;
        a[idx] += val;
        while(idx > 1) {
            idx >>= 1;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    long long query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return 1;
        else {
            int mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(int l, int r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
bool cmp(items a, items b) {
    return a.dist < b.dist;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // buat dijkstra yang ada odd/evennya
    // dijkstra first odd occur and first even occur everything
    // nanti di akhirnya tinggal hitung aja, possible first di posisi tertentu ada berapa, observasinya itu ga mungkin lebih dari 2n aja?
    // nanti sisanya masukkin variable yg maintain odd/even sementara yg sudah terlihat ada berapa
    int k;
    cin >> k;
    int n[k + 1];
    vector<vector<int>> edges[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> n[i], edges[i] = vector<vector<int>>(n[i] + 1);
    int m;
    cin >> m;
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a][b].pb(c);
        edges[a][c].pb(b);
    }
    // tiap dimensi di dijkstra
    // find path length odd sm even
    vector<items> v;
    for(int i = 1; i <= k; ++i) {
        // do dijkstra
        // fi dist
        // se.fi node
        // se.se odd/even
        priority_queue<pair<int, pair<int, bool>>, vector<pair<int, pair<int, bool>>>, greater<pair<int, pair<int, bool>>>> pq;
        // buat min_dist
        int min_dist[n[i] + 1][2];
        memset(min_dist, -1, sizeof(min_dist));
        // initialnya selalu 1
        if(edges[i][1].size() == 0) {
            cout << 0 << endl, exit(0);
        }
        pq.push(mp(0, mp(1, 0)));
        // dist, nd, par, i
        // cek dia sebelumnya udh ada odd atau belum
        // nanti cek tiap odd sendiri (gabisa karena harus dikali distance)
        // dikurangi sebelumnya
        while(pq.size()) {
            int dist = pq.top().fi, nd = pq.top().se.fi, par = pq.top().se.se;
            pq.pop();
            if(min_dist[nd][par] != -1)
                continue;
            min_dist[nd][par] = dist;
            for(auto j : edges[i][nd]) {
                if(min_dist[j][par ^ 1] == -1)
                    pq.push(mp(dist + 1, mp(j, par ^ 1)));
            }
        }
        for(int j = 1; j <= n[i]; ++j) {
            if(min_dist[j][0] != -1 && min_dist[j][1] != -1) {
                if(min_dist[j][0] < min_dist[j][1]) {
                    items tmp;
                    tmp.dim = i, tmp.dist = min_dist[j][0], tmp.nd = j, tmp.is_first = 1;    
                    v.pb(tmp);
                    tmp.dim = i, tmp.dist = min_dist[j][1], tmp.nd = j, tmp.is_first = 0;
                    v.pb(tmp);
                }
                else {
                    items tmp;
                    tmp.dim = i, tmp.dist = min_dist[j][1], tmp.nd = j, tmp.is_first = 1;
                    v.pb(tmp);
                    tmp.dim = i, tmp.dist = min_dist[j][0], tmp.nd = j, tmp.is_first = 0;    
                    v.pb(tmp);
                }
            }
            else if(min_dist[j][0] != -1) {
                items tmp;
                tmp.dim = i, tmp.dist = min_dist[j][0], tmp.nd = j, tmp.is_first = 1; 
                v.pb(tmp);
            }
            else {
                items tmp;
                tmp.dim = i, tmp.dist = min_dist[j][1], tmp.nd = j, tmp.is_first = 1;
                v.pb(tmp);
            }
        }
        // cek tiap min dist brp yg bs
    }
    // sort, nanti di tiap minimum distance coba cari ada berapa?
    // waktu update even, kalo udah ada di odd dikurangi dulu yg di even
    // bisa maintain segtree kalo mau lebih simple sih?
    // karena bisa handle case mul by 0 dengan mudah
    // maintain 4 segtrees
    // murni even
    // murni odd
    // even all
    // odd all
    sort(v.begin(), v.end(), cmp);
    segment_tree ev, od, forev, forod;
    ll res = 0;
    for(auto i : v) {
        if(i.is_first) {
            // ini jauh lebih simple
            // tinggal tambahin ke even/odd semua
            // kalikan sm segtree yg all
            if(i.dist & 1) {
                res +=  i.dist * od.query(1, i.dim - 1) % mod * od.query(i.dim + 1, k);
                res %= mod;
                od.update(i.dim, 1);
            }
            else {
                res += i.dist * ev.query(1, i.dim - 1) % mod * ev.query(i.dim + 1, k);
                res %= mod;
                ev.update(i.dim, 1);
            }
        }
        else {
            if(i.dist & 1) {
                // pakai dr od jgn od
                res += i.dist * (od.query(1, i.dim - 1) * od.query(i.dim + 1, k) % mod - forod.query(1, i.dim - 1) * forod.query(i.dim + 1, k) % mod);
                res %= mod;
                od.update(i.dim, 1);
                forev.update(i.dim, 1);
                forod.update(i.dim, 1);
            }
            else {
                res += i.dist * (ev.query(1, i.dim - 1)  * ev.query(i.dim + 1, k) % mod - forev.query(1, i.dim - 1) * forev.query(i.dim + 1, k) % mod);
                res %= mod;
                ev.update(i.dim, 1);
                forev.update(i.dim, 1);
                forod.update(i.dim, 1);
            }
        }
        //cout << res << " " << i.dist << " " << i.dim << " " << i.nd << endl;
    }
    res += mod;
    res %= mod;
    cout << res << endl;
    return 0;
}