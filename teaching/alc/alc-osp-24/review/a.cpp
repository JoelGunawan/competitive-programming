#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int pref[n + 1], suff[n + 2];
    pref[0] = 0, suff[n + 1] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[i] = max(pref[i - 1], a[i] + n - i);
    }
    for(int i = n; i >= 1; --i) {
        suff[i] = max(suff[i + 1], a[i] + i - 1);
    }
    int mn = 2e9;
    for(int i = 1; i <= n; ++i) {
        mn = min(mn, max(max(pref[i - 1], suff[i + 1]), a[i]));
    }
    cout << mn << endl;
}