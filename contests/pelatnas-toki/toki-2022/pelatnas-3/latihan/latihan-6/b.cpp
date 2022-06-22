// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const ll lim = 1 << 18;
struct segment_tree {
    vector<ll> a[2 * lim];
    ll size = lim;
    vector<ll> cur;
    void query(ll nd, ll cl, ll cr, ll idx) {
        for(ll i : a[nd])
            cur.pb(i);
        if(cl != cr) {
            ll mid = (cl + cr) / 2;
            if(idx <= mid)
                query(2 * nd, cl, mid, idx);
            else
                query(2 * nd + 1, mid + 1, cr, idx);
        }
    }
    void update(ll nd, ll cl, ll cr, ll l, ll r, ll val) {
        if(cl >= l && cr <= r) {
            a[nd].pb(val);
            return;
        }
        else if(cl > r || cr < l) {
            return;
        }
        else {
            ll mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
        }
    }
    void erase(ll nd, ll cl, ll cr, ll idx) {
        a[nd].clear();
        if(cl != cr) {
            ll mid = (cl + cr) / 2;
            if(idx <= mid)
                erase(2 * nd, cl, mid, idx);
            else
                erase(2 * nd + 1, mid + 1, cr, idx);
        }
    }
};
struct minimum_segtree {
    long long a[2 * lim], arr_size = lim, zero = 1e16;
    minimum_segtree() {
        fill(a, a + 2 * lim, zero);
    }
    long long merge(long long a, long long b) {
        return min(a, b);
    }
    void update(ll idx, long long val) {
        idx += arr_size;
        a[idx] = val;
        while(idx > 1) {
            idx >>= 1;
            a[idx] = merge(a[2 * idx], a[2 * idx + 1]);
        }
    }
    long long query(ll nd, ll cl, ll cr, ll l, ll r) {
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cl > r || cr < l)
            return zero;
        else {
            ll mid = (cl + cr) / 2;
            return merge(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    long long query(ll l, ll r) {
        return query(1, 0, arr_size - 1, l, r);
    }
};
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll lcost[n + 1], rcost[n + 1];
    memset(lcost, -1, sizeof(lcost));
    memset(rcost, -1, sizeof(rcost));
    pair<pair<ll, ll>, pair<ll, ll>> a[k];
    vector<pair<ll, pair<ll, ll>>> adj[n + 1];
    for(ll i = 0; i < k; ++i) {
        cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se.fi >> a[i].se.se;
        adj[a[i].fi.fi].pb(mp(a[i].fi.se, a[i].se));
    }
    // cari node dengan minimal distance, kemudian lanjutkan dari node itu
    // O(N + K log (N + K))
    segment_tree segtree;
    for(ll i = 0; i < k; ++i)
        segtree.update(1, 0, lim - 1, a[i].se.fi, a[i].se.se, i);
    priority_queue<pair<ll, ll>> pq;
    //cout << "TEST" << endl;
    pq.push(mp(0, 1));
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(pq.size()) {
        ll nd = pq.top().se;
        ll dist = -pq.top().fi;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        lcost[nd] = dist;
        segtree.query(1, 0, lim - 1, nd);
        vector<ll> &tmp = segtree.cur;
        for(ll i : tmp)
            segtree.erase(1, 0, lim - 1, nd);
        for(ll i : tmp) {
            // insert to pq
            if(!vis[a[i].fi.fi])
                pq.push(mp(-dist - a[i].fi.se, a[i].fi.fi));
        }
        segtree.cur.clear();
    }
    //cout << "TEST2" << endl;
    for(ll i = 0; i < k; ++i)
        segtree.update(1, 0, lim - 1, a[i].se.fi, a[i].se.se, i);
    pq.push(mp(0, n));
    memset(vis, 0, sizeof(vis));
    while(pq.size()) {
        ll nd = pq.top().se;
        ll dist = -pq.top().fi;
        pq.pop();
        if(vis[nd])   
            continue; 
        vis[nd] = 1;
        rcost[nd] = dist;
        segtree.query(1, 0, lim - 1, nd);
        vector<ll> &tmp = segtree.cur;
        //cout << "TEST4" << endl;
        for(ll i : tmp)
            segtree.erase(1, 0, lim - 1, nd);
        //cout << "TEST5" << endl;
        for(ll i : tmp) {
            // insert to pq
            if(!vis[a[i].fi.fi])
                pq.push(mp(-dist - a[i].fi.se, a[i].fi.fi));
        }
        segtree.cur.clear();
        //cout << "TEST6" << endl;
    }
    //cout << "TEST3" << endl;
    // get set sorted by minimum lcost + rcost
    ll ans[n + 1];
    memset(ans, -1, sizeof(ans));
    minimum_segtree minl, minr, mint;
    vector<pair<ll, ll>> final_arr;
    for(ll i = 1; i <= n; ++i) {
        if(lcost[i] != -1 && rcost[i] != -1)    
            final_arr.pb(mp(lcost[i], i));
        if(lcost[i] != -1)
            minl.update(i, lcost[i]);
        if(rcost[i] != -1)
            minr.update(i, rcost[i]);
    }
    //cout << "TEST7" << endl;
    sort(final_arr.begin(), final_arr.end());
    for(pair<ll, ll> i : final_arr) {
        ll nd = i.se;
        // consider case 1 edge dan consider case 2 edge
        // 2 edge -> tmp
        // 1 edge -> consider dari rmq
        ll tmp = lcost[nd] + rcost[nd];
        for(pair<ll, pair<ll, ll>> i : adj[nd]) {
            tmp = min(tmp, i.fi + min(minl.query(i.se.fi, i.se.se) + minr.query(i.se.fi, i.se.se), mint.query(i.se.fi, i.se.se)));
        }
        mint.update(nd, tmp);
        // tetep pake dijkstra untuk urutan
        ans[nd] = tmp;
    }
    final_arr.clear();
    for(ll i = 1; i <= n; ++i) {
        if(lcost[i] != -1 && rcost[i] != -1)    
            final_arr.pb(mp(rcost[i], i));
    }
    sort(final_arr.begin(), final_arr.end());
    //cout << "TEST8" << endl;
    for(pair<ll, ll> i : final_arr) {
        ll nd = i.se;
        // consider case 1 edge dan consider case 2 edge
        // 2 edge -> tmp
        // 1 edge -> consider dari rmq
        ll tmp = lcost[nd] + rcost[nd];
        for(pair<ll, pair<ll, ll>> i : adj[nd]) {
            tmp = min(tmp, i.fi + min(minl.query(i.se.fi, i.se.se) + minr.query(i.se.fi, i.se.se), mint.query(i.se.fi, i.se.se)));
        }
        mint.update(nd, min(ans[nd], tmp));
        // tetep pake dijkstra untuk urutan
        ans[nd] = min(ans[nd], tmp);
    }
    for(ll i = 1; i <= n; ++i) {
        for(pair<ll, pair<ll, ll>> j : adj[i]) {
            ans[i] = min(ans[i], j.fi + mint.query(j.se.fi, j.se.se));
        }
    }
    //cout << "TEST9" << endl;
    for(ll i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    return 0;
}