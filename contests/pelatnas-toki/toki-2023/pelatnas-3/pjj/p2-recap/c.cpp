#include <bits/stdc++.h>
using namespace std;
int n, a[255], pref[255], memo[255][255];
int dp(int l, int r) {
    if(memo[l][r] != -1)
        return memo[l][r];
    else if(l >= r)
        return 0;
    else {
        int res = 1e9;
        for(int i = l; i <= r; ++i) {
            res = min(res, dp(l, i - 1) + dp(i + 1, r) + pref[r] - pref[l - 1] - a[i]);
        }
        return memo[l][r] = res;
    }
}
int main() {
    string input;
    while(getline(cin, input)) {
        stringstream sin(input);
        sin >> n;
        for(int i = 1; i <= n; ++i)
            sin >> a[i], pref[i] = pref[i - 1] + a[i];
        memset(memo, -1, sizeof(memo));
        cout << dp(1, n) << endl;
    }
}