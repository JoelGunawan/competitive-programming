#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 998244353;
ll mul(ll a, ll b) {
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
ll divide(ll a, ll b) {
    return mul(a, powmod(b, mod - 2));
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll sub(ll a, ll b) {
    a -= b;
    a %= mod;
    if(a < 0)
        a += mod;
    return a;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // tidak ada bnyk kemungkinan
    // kemungkinan 1 -> ttp 0
    // kemungkinan 2 -> jadi angka baru
    // kemungkinan 3 -> jadi angka lama (tp affected by angka baru)
    sort(a + 1, a + n + 1);
    // kalo di posisi a[k + 1] itu 0, berarti pasti posisi k itu 0
    // satu-satunya kemungkinan case pertama
    // klo a[k] = 0, berarti kemungkinan angka baru dibawah angka lama atau diatas
    // expected value dihitung dari situ
    // kalo a[k] != 0, berarti angka baru cmn bs jadi klo dia di antara a[k - 1] dan a[k]
    int zero = 0;
    int cnt[m + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i)
        if(a[i] == 0)
            ++zero;
        else    
            ++cnt[a[i]];
    //cout << "TEST" << endl;
    int larger = n - zero, smaller = 0;
    int res = 0;
    for(int i = 1; i <= m; ++i) {
        // cek count of smaller dan larger
        //cout << i << endl;
        //cout << "GET CNT" << endl;
        larger -= cnt[i];
        // calculate possibility
        if(smaller >= k || larger > n - k)
            res += 0;
        else {
            // berarti pasti ada valid configuration?
            // bisa pakai zero atau bisa pake eq
            // intinya -> zero ga boleh dipakai ke smaller atau larger sampai melebihi batas
            int sslot = k - smaller - 1, lslot = (n - k) - larger;
            //cout << "CALC 1 DONE" << endl;
            // lslot dan sslot harus add up ke zero

        }
        //cout << "ADD SMALLER" << endl;
        smaller += cnt[i];
        //cout << "DONE" << endl;
    }
    cout << res << endl;
    cout << divide(res, powmod(m, zero));
}