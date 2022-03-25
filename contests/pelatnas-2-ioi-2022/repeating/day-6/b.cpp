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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int l[n + 1], r[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> l[i];
        if(i != n)
            cin >> r[i];
    }
    r[n] = INT_MAX;
    pair<int, int> dp[n + 1];
    // harus maintain -> transisi dari kiri, maksimum transisi yang bisa diterima, max_count
    // dp[pos][nilai l[j]][nilai r[i] sebelumnya]
    // paling tinggi count of people currentnya
    // 
    int dp[n + 1][201][201];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        // kita cukup perlu cek buat tiap state yang mungkin
    }
    return 0;
}