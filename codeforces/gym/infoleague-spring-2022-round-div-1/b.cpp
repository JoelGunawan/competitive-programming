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
    int n, m, mod;
    cin >> n >> m >> mod;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // for each pair of unique values, kita simpen minimum xornya jadi berapa
    // untuk tiap pair, cari xornya, tambahkan ke semua subset
    sort(a, a + n);
    
    return 0;
}