#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
using namespace std;
vector<int> zeropos = {0};
ll dp[2][50005], pref_inv[50005], suff_inv[50005];
struct fenwick {
    int a[105];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < 105) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    int query(int idx) {
        int res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
};
ll eval(pair<ll, ll> a, ll x) {
    return a.fi * x + a.se;
}
ll inter(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.fi == b.fi)
        return 0;
    return (b.se - a.se) / (a.fi - b.fi);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // definitely dp dnc :))
    // posisi optimal naruh decreasing ke kanan
    // optl optr l r
    // forgot gmn cara impl dp dnc tp harusnya bisa dilogika lah dp dnc :"D
    int n, k;
    cin >> n >> k;
    int h[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        if(h[i] == 0)
            zeropos.pb(i);
    }
    fenwick bit;
    // masukkan dr belakang, nanti yang maksimal bakal di depan?
    // tapi spam pop front di depan dulu :3
    ll res = 0;
    for(int i = k; i >= 1; --i) {
        memset(bit.a, 0, sizeof(bit.a));
        for(int j = 1; j <= n; ++j) {
            pref_inv[j] = bit.query(100) - bit.query(i);
            if(h[j] > 0) {
                bit.upd(h[j], 1);
            }
        }
        memset(bit.a, 0, sizeof(bit.a));
        for(int j = n; j >= 1; --j) {
            suff_inv[j] = bit.query(i - 1);
            if(h[j] > 0)
                bit.upd(h[j], 1);
        }
        // nanti sblum push back determine perlu ngga duluan
        ll pref[n + 1], suff[n + 1];
        pref[0] = suff[0] = 0;
        int cur = i & 1;
        deque<pair<ll, ll>> cht;
        for(int j = 1; j < zeropos.size(); ++j) {
            pref[j] = pref[j - 1] + pref_inv[zeropos[j]];
            suff[j] = suff[j - 1] + suff_inv[zeropos[j]];
            pair<ll, ll> nl = mp(j - 1, 1ll * -(j - 1) * (j - 1) - pref[j - 1] - suff[j - 1] + dp[cur ^ 1][j - 1]);
            if(i == k)
                nl.fi = 0, nl.se += 1ll * -(j - 1) * (j - 1);
            // selama back ga optimal, kita hilangin back aja
            while(cht.size() >= 2 && inter(cht[cht.size() - 2], cht.back()) >= inter(cht[cht.size() - 2], nl))
                cht.pop_back();
            cht.pb(nl);
        }
        for(int j = 1; j < zeropos.size(); ++j) {
            dp[cur][j] = max(dp[cur][j], dp[cur ^ 1][j]);
            while(cht.size() >= 2 && cht[1].fi < j && eval(cht[0], j) <= eval(cht[1], j))
                cht.pop_front();
            // pilih depan
            dp[cur][j] = max(dp[cur][j], eval(cht[0], j) + pref[j] + suff[j]);
            res = max(res, dp[cur][j]);
            //cout << cht[0].fi << " " << dp[cur][j] << " ";
            //cout << dp[cur][j] << " ";
        }
        //cout << endl;
    }
    memset(bit.a, 0, sizeof(bit.a));
    for(int i = 1; i <= n; ++i) {
        if(h[i] > 0) {
            res += bit.query(100) - bit.query(h[i]);
            bit.upd(h[i], 1);
        }
    }
    cout << res << endl;
    // precalculate suffix and prefix inversion
    // define dp[n][k] = optimal isi sampai n posisi dengan last filling itu pakai k
    // based on zero positions, di dp dnc
    // buat bit posisi aja nanti di depan sm belakangnya
}