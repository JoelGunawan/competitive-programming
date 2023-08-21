#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
ll mod = 1e6 + 3;   
const ll lim = 1 << 20;
struct segment_tree {
    ll a[2 * lim];
    segment_tree() {
        fill(a, a + 2 * lim, 1e9);
    }
    void update(ll idx, ll val) {
        idx += lim;
        a[idx] = val;
        while(idx) {
            idx /= 2;
            a[idx] = min(a[2 * idx], a[2 * idx + 1]);
        }
    }
    ll query(ll nd, ll cl, ll cr, ll l, ll r) {
        if(cl >= l && cr <= r)
            return a[nd];
        else if(cl > r || cr < l)
            return 1e9;
        else {
            ll mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
ll get_sum(ll n) {
    return n * (n + 1) / 2;
}
ll get_sum(ll l, ll r) {
    return (get_sum(r) - get_sum(l - 1)) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // coba satu per satu mana yg jadi mx height
    // cara tambah paling optimal?
    // coba dari tengah dulu
    // sub 1 -> cari mid poll, terus nanti di jadiin straight line (obv)
    // sub 2 -> bisa pakai pq, choose by min cost?
    // query di kanan, cari first yg lebih dari cur
    // query di kiri, cari first yg lebih dari cur
    ll n;
    cin >> n;
    ll h[n + 1];
    for(ll i = 1; i <= n; ++i)
        cin >> h[i];
    ll pref_mx[n + 1], suff_mx[n + 2];
    memset(pref_mx, 0, sizeof(pref_mx));
    memset(suff_mx, 0, sizeof(suff_mx));
    for(ll i = 1; i <= n; ++i)
        pref_mx[i] = max(pref_mx[i - 1], h[i]);
    for(ll i = n; i >= 1; --i)
        suff_mx[i] = max(suff_mx[i + 1], h[i]);
    ll target[n + 1];
    for(ll i = 1; i <= n; ++i) {
        target[i] = min(pref_mx[i], suff_mx[i]);
    }
    // simpan vector cur height itu apa aja
    // coba sub 2, 3
    long long res = 0;
    set<ll> cur;
    segment_tree seg;
    //cout << "TEST" << endl;
    for(ll i = 1; i <= n; ++i)
        seg.update(i, h[i]);
    vector<ll> heights;
    for(ll i = 1; i <= n; ++i)
        heights.push_back(h[i]);
    sort(heights.begin(), heights.end());
    heights.resize(unique(heights.begin(), heights.end()) - heights.begin());
    vector<ll> stop[n + 5], start[n + 5];
    for(ll i = 1; i <= n; ++i)
        stop[lower_bound(heights.begin(), heights.end(), target[i]) - heights.begin()].push_back(i);
    for(ll i = 1; i <= n; ++i)
        start[lower_bound(heights.begin(), heights.end(), h[i]) - heights.begin()].push_back(i);
    for(auto j : start[0])
        cur.insert(j), seg.update(j, 1e9);
    for(auto j : stop[0])
        cur.erase(cur.find(j));
    for(ll i = 1; i < heights.size(); ++i) {
        //cout << i << endl;
        //cout << "PROC 1 " << endl;
        if(cur.empty()) {

        }
        else if(cur.size() == 1) {
            ll el = *cur.begin();
            // heights[i - 1] to heights[i] - 1
            res += ((heights[i] - heights[i - 1]) % mod) * (seg.query(1, 0, lim - 1, 1, el - 1) + seg.query(1, 0, lim - 1, el + 1, n));
            res %= mod;
            res += get_sum(heights[i - 1], heights[i] - 1);
            res %= mod;
        }
        else {
            ll cl = *cur.begin(), cr = *--cur.end();
            res += ((3 * get_sum(heights[i - 1], heights[i] - 1)) % mod) * (cur.size() - 1);
            res %= mod;
            res += ((heights[i] - heights[i - 1]) % mod) * (1 + 2 * (cur.size() - 2)); 
            res %= mod;
            res += ((heights[i] - heights[i - 1]) % mod) * ((seg.query(1, 0, lim - 1, 1, cl - 1) + seg.query(1, 0, lim - 1, cr + 1, n) + seg.query(1, 0, lim - 1, 1, n)) % mod);
            res %= mod;
        }
        for(auto j : start[i])
            cur.insert(j), seg.update(j, 1e9);
        for(auto j : stop[i])
            cur.erase(cur.find(j));
    }
    cout << res << endl;
}