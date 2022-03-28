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
int mod[3] = {1e9 + 7, 1e9 + 9, 998244353};
int key[2] = {1770173, 176303};
// use poly hash
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // hashing a 2d array
    // finding value of polynomial hash in 2d array
    int n1, m1, n2, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    if(n1 < n2 || m1 < m2) {
        cout << 0 << endl;
        return;
    }
    int a[n1][m1], b[n2][m2];
    ll hash[n1][m1], hash2[n2][m2];
    for(int i = 0; i < n1; ++i)
        for(int j = 0; j < m1; ++j)
            cin >> a[i][j];
    // divide by first instance
    // untuk pattern matching harus per baris bedanya m1
    for(int i = 0; i < n1; ++i) {

    }
    for(int i = 0; i < n2; ++i)
        for(int j = 0; j < m2; ++j)
            cin >> b[i][j];
    return 0;
}