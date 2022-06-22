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
const int lim = 5e5 + 5;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // cari mst
    // simpan edge yang ada di mst
    int n;
    cin >> n;
    // sort by x dan sort by y
    pair<pair<ll, ll>, ll> a[n];
    for(int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = mp(mp(x, y), i + 1);
    }
    int m;
    cin >> m;
    pair<pair<ll, ll>, pair<ll, ll>> b[m];
    for(int i = 0; i < m; ++i) {
        int c, d, e, f;
        cin >> c >> d >> e >> f;
        b[i] = mp(mp(c, d), mp(e, f));
    }
    // fi.fi -> x pos
    // fi.se -> start or end
    // se.fi -> y bawah
    // se.se -> y atas
    pair<ll, pair<ll, ll>> sweep[m];
    for(int i = 0; i < m; ++i)
        sweep[i] = mp(b[i].fi.fi, mp(b[i].fi.se, b[i].se.se));
    sort(a, a + n);
    sort(sweep, sweep + m);
    ll idx1 = 0, idx2 = 0;
    // fi -> pos
    // se.fi -> prev_pos
    // se.se -> prev_idx
    set<pair<ll, pair<ll, ll>>> active;
    vector<pair<ll, pair<ll, ll>>> edges;
    while(idx1 < n || idx2 < m) {
        while(idx1 < n && (idx2 >= m || a[idx1].fi.fi <= sweep[idx2].fi)) {
            ll x = a[idx1].fi.fi, y = a[idx1].fi.se, idx = a[idx1].se;
            if(active.size() && active.lb(mp(y, mp(0ll, 0ll))) != active.end() && (*active.lb(mp(y, mp(0ll, 0ll)))).fi == y) {
                edges.pb(mp(abs(x - (*active.lb(mp(y, mp(0ll, 0ll)))).se.fi), mp((*active.lb(mp(y, mp(0ll, 0ll)))).se.se, idx)));
                active.erase(active.lb(mp(y, mp(0ll, 0ll))));
            }
            active.ins(mp(y, mp(x, idx)));
            ++idx1;
        }
        while(idx2 < m && (idx1 >= n || sweep[idx2].fi <= a[idx1].fi.fi)) {
            // hilangkan semua active index kalo di range
            // tambahkan bit ke range
            ll l = sweep[idx2].se.fi, r = sweep[idx2].se.se;
            while(active.size() && active.lower_bound(mp(l, mp(0ll, 0ll))) != active.end() && (*active.lower_bound(mp(l, mp(0ll, 0ll)))).fi <= r) {
                active.erase(active.lower_bound(mp(l, mp(0ll, 0ll))));
            }
            ++idx2;
        }
    }
    for(int i = 0; i < n; ++i)
        swap(a[i].fi.fi, a[i].fi.se);
    for(int i = 0; i < m; ++i) {
        sweep[i] = mp(b[i].fi.se, mp(b[i].fi.fi, b[i].se.fi));
    }
    sort(a, a + n);
    sort(sweep, sweep + m);
    active.clear();
    idx1 = 0, idx2 = 0;
    while(idx1 < n || idx2 < m) {
        while(idx1 < n && (idx2 >= m || a[idx1].fi.fi <= sweep[idx2].fi)) {
            ll x = a[idx1].fi.fi, y = a[idx1].fi.se, idx = a[idx1].se;
            if(active.size() && active.lb(mp(y, mp(0ll, 0ll))) != active.end() && (*active.lb(mp(y, mp(0ll, 0ll)))).fi == y) {
                edges.pb(mp(abs(x - (*active.lb(mp(y, mp(0ll, 0ll)))).se.fi), mp((*active.lb(mp(y, mp(0ll, 0ll)))).se.se, idx)));
                active.erase(active.lb(mp(y, mp(0ll, 0ll))));
            }
            active.ins(mp(y, mp(x, idx)));
            ++idx1;
        }
        while(idx2 < m && (idx1 >= n || sweep[idx2].fi <= a[idx1].fi.fi)) {
            // hilangkan semua active index kalo di range
            // tambahkan bit ke range
            ll l = sweep[idx2].se.fi, r = sweep[idx2].se.se;
            while(active.size() && active.lower_bound(mp(l, mp(0ll, 0ll))) != active.end() && (*active.lower_bound(mp(l, mp(0ll, 0ll)))).fi <= r) {
                active.erase(active.lower_bound(mp(l, mp(0ll, 0ll))));
            }
            ++idx2;
        }
    }
    sort(edges.begin(), edges.end());
    int cc = n;
    vector<ll> used = {};
    disjoint_set dsu;
    for(auto i : edges) {
        if(dsu.merge(i.se.fi, i.se.se))
            used.pb(i.fi), --cc;
    }
    ll pref[used.size() + 100];
    memset(pref, 0, sizeof(pref));
    if(used.size())
        pref[0] = used[0];
    for(int i = 1; i < used.size(); ++i)
        pref[i] = pref[i - 1] + used[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        ll p, k;
        cin >> p >> k;
        // do mandatory
        ll res = 0;
        res += 1ll * k * cc;
        p -= cc;
        if(p < 0)
            cout << -1 << endl;
        // find first instance of used that is ge
        else {
            if(used.size() == 0) {
                cout << res << endl;
            }
            else {
                ll take = used.end() - lower_bound(used.begin(), used.end(), k);
                take = min(take, p);
                take = max(take, 0ll);
                res += 1ll * take * k;
                if((int)used.size() - take - 1 >= 0 && used.size() - take - 1 < used.size())
                    res += pref[used.size() - take - 1];
                cout << res << endl;
            }
        }
    }
    return 0;
}