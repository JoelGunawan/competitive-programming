#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    long long pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << endl;
    }
}