#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define ll long long
using namespace std;
const int lim = 5005;
struct bit {
    int a[lim];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) 
            a[idx] += val, idx += (idx&-idx);
    }
    int q(int idx) {
        int res = 0;
        while(idx > 0)
            res += a[idx], idx -= (idx&-idx);
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // O(n^2)
    // pake dp
    // terus kita lakuin transisi in O(n)
    // kita cari sorted array yang mungkin di mana aja
    // kita harus cari apakah x elemen ke belakang indeks berapa aja yang bisa kita tambah
    // untuk sebuah subarray apakah bisa dicari dalam O(n)?
    // asuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu\

    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        int pref[n + 1];
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        memset(pref, 0, sizeof(pref));
        bit bit;
        for(int j = i; j <= n; ++j) {
            // cek banyak yang kurang dari max(cur) di all
            // kalo misal banyak kurang dari max(cur) di all adalah 0
            // maka tambah kualitas dengan 1
            // pake max query ds
            // buat cari di dalam all
            // indeks maksimum
            // cari posisi j dalam subarray i, j yang sorted dengan BIT
            // ada cara O(1) buat cari posisi i, j?
            bit.upd(a[j], 1);
            pref[j] = max(a[j], pref[j - 1]);
            //cout << pref[j] << " ";
            // cari paling kanan
            // yang memenuhi
            // prefix range tertentu
            // tapi bisa jadi
            // tidak monotonic
            // kita bisa cari
            // pos
            // dengan precompute
            // kita cari dari belakang ke depan
            // array ke kiri terjauh dimana l, r merupakan maksimum
            // untuk depan ke belakang
            // array ke kanan terjauh dimana l, r merupakan minimum
            int pos;
            //cout << prev_elem << " " << pref[pos - 1] << endl;
            dp[j] = dp[pos] + 1;
            cout << i << " " << j << " " << pos << " " << dp[j] << endl;
            res += dp[j];
            // n^2 log n
        }
        //cout << endl;
    }
    cout << res << endl;
    return 0;
}