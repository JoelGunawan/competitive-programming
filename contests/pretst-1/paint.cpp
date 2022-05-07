#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    // get semua node yang distancenya <= d dari node cur yang sudah di vis (di belakang)
    // terus get invalid count
    ll loc[n + 1];
    loc[1] = 0;
    pair<int, int> edges[n - 1];
    for(int i = 1; i <= n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if(u > v)
            swap(u, v);
        edges[i - 1] = mp(u, w);
    }
    sort(edges, edges + n - 1);
    for(int i = 0; i < n - 1; ++i) {
        loc[i + 2] = loc[i + 1] + edges[i].se;
    }
    while(q--) {
        int d, k;
        cin >> d >> k;
        queue<int> qu;
        ll invalid = 0;
        for(int i = 1; i <= n; ++i) {
            while(qu.size() && loc[i] - qu.front() > d)
                qu.pop();
            // ada qu.size() cara
            ll tmp = powmod(k, i - 1) - invalid;
            tmp += mod;
            tmp %= mod;
            tmp *= qu.size();
            tmp %= mod;
            invalid *= k;
            invalid %= mod;
            invalid += tmp;
            invalid %= mod;
            qu.push(loc[i]);
        }
        ll res = powmod(k, n) - invalid;
        res %= mod;
        res += mod;
        res %= mod;
        cout << res << endl;
    }
    return 0;
}