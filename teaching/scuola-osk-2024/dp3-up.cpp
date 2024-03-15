// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
int memo[12];
int dp(int n) {
    if(n < 0)
        // return infinity
        return 1e9;
    else if(n == 0)
        // base case
        return 0;
    else if(memo[n] != -1)
        // sudah dihitung
        return memo[n];
    else {
        // hitung nilai memo
        memo[n] = min({dp(n - 1), dp(n - 3), dp(n - 5)}) + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n = 11;
    // initialize array memoisasi
    memset(memo, -1, sizeof(memo));
    cout << dp(11) << endl;
    return 0;
}