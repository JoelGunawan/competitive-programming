#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            // __gcd(1, 4) == 1 TRUE
            // __gcd(2, 4) == 2
            // __gcd(3, 4) == 1 TRUE
            // __gcd(4, 4) == 4
            if(__gcd(i, j) == 1) {
                if(i == 4) {
                    // waktu i = 4, ini terjadi 2x.
                    // waktu j = 1 dan j = 3
                    cout << "TEST" << endl;
                    cout << i << " " << j << endl;
                    // n = 4, i = 4
                    // n = 4, i = 4
                    ans += n / i;
                }
            }
        }
    }
    // semua untuk i = 4
    // (n / i) * phi(i)
    // n / i * phi(i)
    // (n / i) * i * (1-1/p_1) * ... * (1-1/p_x)
    cout << ans << endl;
}