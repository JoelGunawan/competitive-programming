#include <bits/stdc++.h>
#define ll long long
#define lll __int128_t
#define mp make_pair
using namespace std;
const int lim = 1e5 + 5;
int mod = 1e9 + 7;
ll res = 0;
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
lll mul(lll a, lll b) {
    a %= mod;
    b %= mod;
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
lll sum(lll x) {
    if(x % 2 == 0)
        return mul(x / 2, x + 1);
    else
        return mul(x, (x + 1) / 2);
}
ll sum(ll l, ll r) {
    //cout << "QUERY " << l << " " << r << endl;
    if(l > r)
        return 0;
    lll ret = sum(r) - sum(l - 1);
    ret %= mod;
    if(ret < 0)
        ret += mod;
    //cout << l << " " << r << " " << ret << endl;
    return ret;
}
struct disjoint_set {
    int h[lim], sz[lim];
    ll a[lim], lh[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        memset(a, 0, sizeof(a));
        fill(sz, sz + lim, 1);
        // lh diisi manual
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    void merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            int nh = min(lh[x], lh[y]);
            res += mul(sum(nh + 1, lh[x]), sum(1, a[x])) + mul(sum(nh + 1, lh[y]), sum(1, a[y]));
            h[y] = x;
            sz[x] += sz[y];
            a[x] += a[y];
            lh[x] = nh;
        }
    }
};
int main() {
    // use dsu, merging segments get count
    // tiap segment simpan l, r, last_height
    // nanti di calculate internal last_heightnya berapa
    // di calculate merge last_heightnya berapa
    int n;
    cin >> n;
    int h[n + 1], w[n + 1];
    disjoint_set dsu;
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        dsu.lh[i] = h[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
        dsu.a[i] = w[i];
    }
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= n; ++i) {
        if(i != 1 && h[i - 1] >= h[i]) {
            pq.push(mp(h[i], i));
        }
        if(i != n && h[i + 1] >= h[i]) {
            pq.push(mp(h[i], i + 1));
        }
    }
    // merge dr large to small
    // dr height tertinggi ke height terendah?
    while(pq.size()) {
        int mg = pq.top().second;
        pq.pop();
        dsu.merge(mg, mg - 1);
    }
    ll a = dsu.a[dsu.fh(1)], lh = dsu.lh[dsu.fh(1)];
    //cout << a << " " << lh << endl;
    res += mul(sum(1, lh), sum(1, a));
    res %= mod;
    cout << res << endl;
}