#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
/*
ll helper(ll n, int onbit) {
    // dengan onbit, 
    ll tmp = 1ll << onbit;
    // tiap onbit, bakal switch
    ll tmp2 = (n + 1) / (2 * tmp), rem = (n + 1) % (2 * tmp);
    rem = max(rem - tmp, 0ll);
    return tmp2 * tmp + rem;
}
ll solve(ll n, ll x) {
    // mulai dari paling kecil
    // everything disitu, tiap berapa aja, kita simpan
    bool inv;
    vector<int> pr;
    ll ret = 0;
    for(int i = 0; i < 45; ++i) {
        if((1ll << i) & x) {
            // bit on / tiap 1
            pr.push_back(i);
        }
        // go through every pr, try and find correct res
        bool inv = 0;
        ll cur = 0, tmp = n;
        for(int j = pr.size() - 1; j >= 0; --j) {
            // cari dist antara pr[j] dan sekarang
            // pasti paling depan paling jauh
            // cek blok paling jauh ada berapa
            cout << "in1 " << pr[j] << " " << cur << " " << tmp << endl;
            ll blk = (tmp + 1) / (1ll << (i - pr[j] + 1)); 
            tmp = tmp % (1ll << (i - pr[j] + 1));
            cur += (blk % mod) * ((1ll << (i - pr[j])) % mod);
            if(pr[j] == pr.front()) {
                // solve
                if(inv)
                    cur += tmp - helper(tmp, i - pr[j]);
                else
                    cur += helper(tmp, i - pr[j]);
            }
            if(blk & 1)
                inv = !inv;
            cout << "in2 " << (int)inv < " " << blk << " " << pr[j] << " " << cur << " " << tmp << endl;
            cur %= mod;
        }
        if((1 << i) & x)
            cur = n - cur;
        // ijin ke toilet
        cout << i << " " << cur << endl;
        ret += ((1ll << i) % mod) * cur;
        ret %= mod;
    }
    return ret % mod;
}
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll tmp = 1, tmp2 = 0;
    while(tmp <= m)
        tmp *= 2, ++tmp2;
    // 1 -> skip 2, arit 3
    // 3 -> skip 4, arit 5
    // ini arit
    // buat minus hitung sendiri
    --n;
    ll res = (((tmp + 1) % mod) * ((n % mod) * ((n + 1) % mod)) % mod) * powmod(2, mod - 2);
    res %= mod;
    // hitung ada berapa blok
    // di blok terakhir itu valuenya -2 * tmp
    // skipnya 4 * tmp per blok ukuran tmp
    ll blk = (n + 1) / tmp, rem = (n + 1) % tmp;
    --blk;
    blk %= mod;
    ll sub = ((blk * (blk + 1)) % mod) * powmod(2, mod - 2);
    sub %= mod;
    sub *= ((tmp * tmp) % mod);
    sub %= mod;
    sub *= 2;
    sub %= mod;
    // rem dihitung manual
    // minus itu blk * 2 * tmp
    ll neg = (((blk + 1) * rem) % mod) * ((2 * tmp) % mod);
    neg %= mod;
    cout << res << " " << sub << " " << neg << endl;
    // rem dihitung manual
    // current itu banyak blok prev
    res -= sub + neg;
    res %= mod;
    res = (res + mod) % mod;
    cout << res << endl;
    return 0;
}