#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t;
    cin >> n >> t;
    int w[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    long long l = 1, r = 1e18, ans = -1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long produk = 0;
        for(int i = 1; i <= n; ++i) {
            produk += mid / w[i];
            if(produk >= t)
                break;
        }
        if(produk >= t) {
            // sudah ketemu bisa, tapi coba cari yg lebih kecil
            r = mid - 1, ans = mid;
        }
        else {
            // terlalu kecil waktunya
            l = mid + 1;
        }
    }
    cout << ans << endl;
}