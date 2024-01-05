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
int memo[16];
int dp(int n) {
    // base case
    if(n < 0)
        return 0;
    else if(n == 0)
        return 1;
    // base case berakhir
    // nilai ini sudah dihitung
    // udah dihitung, langsung return value memo yg sudah dihitung
    else if(memo[n] != -1)
        return memo[n];
    else {
        // nilai belum dihitung
        // hitung nilainya, terus simpan ke memo
        memo[n] = dp(n - 1) + dp(n - 2);
        return memo[n];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n = 15;
    // initialisasi array memoisasi
    memset(memo, -1, sizeof(memo));
    // mulai dari jawaban akhir
    cout << dp(15) << endl;
    return 0;
}