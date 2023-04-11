#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define endl "\n"
using namespace std;
vector<int> zeropos = {0};
ll dp[2][50005], pref_inv[50005], suff_inv[50005];
int k;
ll output = 0;
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
void dnc(int depth, int l, int r, int optl, int optr) {
    if(l > r)
        return;
    // try optl dan optr untuk tiap indeks, hasil inversinya bakal brp
    // cek inversi dr depan dan inversi dr belakang
    // semakin kanan r, semakin kanan prev yg diambil
    int mid = (l + r) / 2;
    ll mx = -1, mx_idx = min(mid - 1, optr);
    ll tmp = 0;
    bool cur = depth & 1;
    //cout << "CURRENT STATE" << endl;
    //cout << depth << " " << mid << endl;
    for(ll i = min(mid - 1, optr); i >= min(mid - 1, optl); --i) {
        // dia ambil dr antara optl ke mid
        // tambah yg static
        tmp += pref_inv[zeropos[i + 1]] + suff_inv[zeropos[i + 1]];
        // ditambah mid, karena yang diambil sebelumnya
        // atau kita tambah yang diambil setelahnya aja?
        //cout << pref_inv[zeropos[i + 1]] << " " << suff_inv[zeropos[i + 1]] << " " << (mid - i) * i << " " << dp[cur ^ 1][i] << endl;
        ll cur_ans = tmp + dp[cur ^ 1][i];
        if(depth != k)
            cur_ans += (mid - i) * i;
        if(cur_ans >= mx) {
            mx_idx = i;
            mx = cur_ans;
        }
    }
    //cout << mx << endl;
    dp[cur][mid] = max({mx, dp[cur][mid], dp[cur ^ 1][mid]});
    output = max(output, mx);
    dnc(depth, l, mid - 1, optl, mx_idx);
    dnc(depth, mid + 1, r, mx_idx, optr);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // definitely dp dnc :))
    // posisi optimal naruh decreasing ke kanan
    // optl optr l r
    // forgot gmn cara impl dp dnc tp harusnya bisa dilogika lah dp dnc :"D
    int n;
    cin >> n >> k;
    int h[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
        if(h[i] == 0)
            zeropos.pb(i);
    }
    fenwick bit;
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
        dnc(i, 1, zeropos.size() - 1, 0, zeropos.size() - 2);
        //for(int j = 0; j < zeropos.size(); ++j) 
        //    cout << dp[i & 1][j] << " ";
        //cout << endl;
    }
    memset(bit.a, 0, sizeof(bit.a));
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        if(h[i] > 0) {
            res += bit.query(100) - bit.query(h[i]);
            bit.upd(h[i], 1);
        }
    }
    cout << res + output << endl;
    // precalculate suffix and prefix inversion
    // define dp[n][k] = optimal isi sampai n posisi dengan last filling itu pakai k
    // based on zero positions, di dp dnc
    // buat bit posisi aja nanti di depan sm belakangnya
}