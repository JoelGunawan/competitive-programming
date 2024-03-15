#include <bits/stdc++.h>
using namespace std;
int main() {
    // observasi: prefix/suffix -> min/max/sum
    // bisa xor, and, gcd
    int n, k;
    cin >> n >> k;
    int a[n + 2];
    a[0] = a[n + 1] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int pref[n + 1], suff[n + 2];
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    for(int i = 1; i <= n; ++i) {
        pref[i] = __gcd(pref[i - 1], a[i]);
    }
    for(int i = n; i >= 1; --i) {
        suff[i] = __gcd(suff[i + 1], a[i]);
    }
    if(k == 1) {
        int res = 0;
        for(int i = 1; i <= n; ++i) {
            res = max(res, __gcd(pref[i - 1], suff[i + 1]));
        }
        cout << res << endl;
    }
    else {
        int res = 0;
        for(int i = 1; i <= n; ++i) {
            int mid_gcd = 0;
            // hilangkan elemen i, j
            // 1...i-1 -> pref[i - 1]
            // j+1...n -> suff[j + 1]
            // i + 1...j-1 -> mid_gcd
            // 2 3 mid_gcd = 3...3
            // 2 4 mid_gcd = 3...4
            // 2 5 mid_gcd = 3...5
            // 2 6 mid_gcd = 3...6
            for(int j = i + 1; j <= n; ++j) {
                res = max(res, __gcd(pref[i - 1], __gcd(suff[j + 1], mid_gcd)));
                mid_gcd = __gcd(mid_gcd, a[j]);
            }
        }
        cout << res << endl;
    }
}