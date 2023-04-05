// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define ll __int128
#define fi first
#define se second
using namespace std;
const int lim = 5e4 + 5;
vector<int> edges[lim];
int sb[lim];
ll d[lim], q[lim];
bool vis[lim];
void get_vals(int nd = 1) {
    vis[nd] = 1;
    sb[nd] = 1;
    d[nd] = 0, q[nd] = 0;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            get_vals(i);
            d[nd] += d[i] + sb[i];
            q[nd] += q[i] + d[i] * 2 + sb[i];
            sb[nd] += sb[i];
        }
    }
    // tiap vals -> sum cnt, sum dist, sum q
}
const ll is_query = -(1e25);
struct Line {
    ll m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        // **** May need long double typecasting here
        return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
    }
    void insert_line(ll m, ll b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};
ll rd[lim], rq[lim];
void reroot(int nd = 1, ll pard = 0, ll parq = 0) {
    parq += pard * 2 + sb[1] - sb[nd];
    pard += sb[1] - sb[nd];
    // masukkan reroot ke dyn cht lgsg aja
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            reroot(i, pard + d[nd] - d[i] - sb[i], parq + q[nd] - q[i] - 2 * d[i] - sb[i]);
        }
    }
    rd[nd] = pard + d[nd], rq[nd] = parq + q[nd];
    // parq sama parnd masukkan ke cht
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // reroot, try to find minimum cost at every node
    // eh tapi bermasalah waktu merging (karena total cost kiri dikali total cost kanan)
    // total 1e5
    // coba cari internal cost dari sebuah tree berapa?
    // dp reroot pake sifat persamaan kuadrat
    // simpan length kuadrat
    // simpan length yg ga dikuadratkan
    // hitung manual 1 per satu rerootnya berapa
    // sumnya tambahin ke internal
    // nanti terakhirnya cari minimal sum setelah ditambah sama 1
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    get_vals();
    memset(vis, 0, sizeof(vis));
    reroot();
    ll dmemo[lim], qmemo[lim];
    ll intern = 0;
    int m;
    cin >> m;
    HullDynamic dyn_cht;
    for(int i = 1; i <= n; ++i) {
        dmemo[i] = rd[i] + sb[1];
        qmemo[i] = rq[i] + 2 * rd[i] + sb[1];
        qmemo[i] *= m;
        dyn_cht.insert_line(-2 * dmemo[i], -qmemo[i]);
        //cout << dmemo[i] << " " << qmemo[i] << endl;
        intern += rq[i];
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= m; ++i)
        edges[i].clear();
    for(int i = 1; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    get_vals();
    memset(vis, 0, sizeof(vis));
    reroot();
    ll res = 1e25;
    for(int i = 1; i <= m; ++i)
        intern += rq[i];
    intern /= 2;
    for(int j = 1; j <= m; ++j) {
        res = min(res, n * rq[j] - (dyn_cht.eval(rd[j])));
        //cout << res << endl;
    }
    cout << (long long)res + (long long)intern << endl;
    // cari total internal dulu

    return 0;
}