#include <bits/stdc++.h>
using namespace std;
int memo[50005];
int a[505];
int n;
// Kompleksitas Waktu: O(NK)
int f(int x) {
    if(x < 0) {
        return 1e9 + 5; // (infinity)
    }
    if(memo[x] != -1)
        return memo[x];
    if(x == 0)
        return 0;
    else {
        int mn = 1e9 + 5;
        for(int i = 1; i <= n; ++i) {
            mn = min(mn, f(x - a[i]) + 1);
        }     
        memo[x] = mn;
        return memo[x];
    }
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int x;
    cin >> x;
    int res = f(x);
    if(res >= 1e9)
        cout << -1 << endl;
    else
        cout << res << endl;
}