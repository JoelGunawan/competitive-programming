#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, x;
    cin >> n >> k >> x;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    int r = 0;
    long long jumlah_nilai = 0, hasil = 0;
    for(int i = 1; i <= n; ++i) {
        while(r < i) {
            ++r;
            jumlah_nilai += b[r];
        }
        // abs(x) -> nilai mutlak dari x
        while(r < n && min(abs(x - a[i]), abs(a[r + 1] - x)) + a[r + 1] - a[i] <= k) {
            ++r;
            jumlah_nilai += b[r];
        }
        //cout << i << " " << r << " " << min(abs(x - a[i]), abs(a[r] - x)) + a[r] - a[i] << endl;
        if(min(abs(x - a[i]), abs(a[r] - x)) + a[r] - a[i] <= k)
            hasil = max(hasil, jumlah_nilai);
        jumlah_nilai -= b[i];
    }
    // jumlah kiri dan jumlah kanan
    long long jumlah_kiri = 0, jumlah_kanan = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] <= x && x - a[i] <= k) {
            jumlah_kiri += b[i];
        }
        if(a[i] >= x && a[i] - x <= k) {
            jumlah_kanan += b[i];
        }
    }
    cout << max(jumlah_kiri, max(jumlah_kanan, hasil)) << endl;
}