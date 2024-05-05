#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int b[k + 1];
    for(int i = 1; i <= k; ++i) {
        cin >> b[i];
    }
    // setiap bebek mau tau paling jauhnya
    int pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= k; ++i) {
        // mau cari yg <= 
        int idx = upper_bound(pref + 1, pref + n + 1, b[i]) - pref - 1;
        cout << idx << endl;
    }
}