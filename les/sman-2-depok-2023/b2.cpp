#include <bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin >> k;
    // first -> harga
    // second -> kapasitas
    pair<long long, long long> a[k];
    // a[0].first (pertama)
    // a[0].second (kedua)
    // a[0] = make_pair(x, y); -> recommended
    // a[0] = {x, y}; -> rawan error
    // sifat pair -> selalu sorting yg awal dulu
    for(int i = 0; i < k; ++i)
        cin >> a[i].second;
    for(int i = 0; i < k; ++i)
        cin >> a[i].first;
    // a -> variable array
    // k -> ukuran array
    sort(a, a + k);
    // sorting ini -> rendah ke tinggi
    int n;
    cin >> n;
    long long b[n];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    // sort tinggi ke rendah
    // cara 1;
    sort(b, b + n);
    reverse(b, b + n);
    // cara 2:
    sort(b, b + n, greater<int>());
    // pasang tiap bebek ke kandang mana?
    int idx = 0;
    long long res = 0;
    for(int i = 0; i < n; ++i) {
        if(a[idx].second == 0) {
            ++idx;
        }
        // tambahkan ke hasil akhir
        // int * int -> int
        res += a[idx].first * b[i];
        // kurangi kapasitas yg udah digunakan
        a[idx].second -= 1;
        // alternatif:
        // --a[idx].second;
        // a[idx].second--;
    }
    cout << res << endl;
}