#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[3], h[3], c[3];
    for(int i = 0; i < 3; ++i)
        cin >> a[i];
    for(int i = 0; i < 3; ++i)
        cin >> h[i];
    for(int i = 0; i < 3; ++i)
        cin >> c[i];
    for(int i = 0; i < 3; ++i)
        h[i] -= c[i];
    // pakai nilai a dan h saja
    // paling banyak n
    int l = 0, r = n, ans;
    while(l <= r) {
        int m = (l + r) / 2;
        // cek apakah bisa atau tidak kalo tanaman xitrus sebanayak m
        int required = 0;
        for(int i = 0; i < 3; ++i) {
            // bulatkan ke atas
            required += ceil(m * a[i] / (double)h[i]);
        }
        // turunkan jumlah tanaman xitrus
        if(required + m > n) {
            r = m - 1;
        }
        else {
            // cari yg lebih maksimal
            ans = m;
            l = m + 1;
        }
    }
    if(ans == 0) {
        cout << -1 << endl;
    }
    else {
        cout << ans << " ";
        n -= ans;
        for(int i = 0; i < 3; ++i) {
            if(i == 2)
                cout << n << endl;
            else {
                cout << ceil(ans * a[i] / (double)h[i]) << " ";
                n -= ceil(ans * a[i] / (double)h[i]);
            }
        }
        cout << endl;
    }
}