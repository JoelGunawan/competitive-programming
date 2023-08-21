#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // __gcd(a, b)
    int pref[n + 2], suff[n + 2];
    suff[n + 1] = 0;
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[i] = __gcd(pref[i - 1], a[i]);   
    }
    for(int i = n; i >= 1; --i) {
        suff[i] = __gcd(suff[i + 1], a[i]);
    }
    // gcd, min, max
    // sum
    int p[n + 1];
    for(int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
    cout << p[r] - p[l - 1] << endl;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, __gcd(suff[i + 1], pref[i - 1]) + a[i]);
    }
    cout << ans << endl;
}