#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll memo[1000005];
int mod = 1e9 + 7;
ll f(int n) {
    if(n < 0)
        return 0;
    if(memo[n] != -1)
        return memo[n];
    if(n == 0)
        return 1;
    else {
        memo[n] = (f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)) % mod;
        return memo[n];
    }
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    cout << f(n) << endl;
}