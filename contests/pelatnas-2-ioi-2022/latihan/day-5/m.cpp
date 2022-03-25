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
    // the i-th dish appears as a common dish of 2 pairs i - 1 times
    // 2 -> 3
    // 3 -> 7
    // 4 -> 13
    // how to construct?
    // cnt = n * (n - 1) + 1
    // transisi pair confusing
    // cari pair yang sebelumnya belum muncul
    int n;
    cin >> n;
    cout << n * (n - 1) + 1 << endl;
    for(int i = 0; i < n; ++i) {
        cout << "1 ";
        for(int j = 2; j <= n; ++j) {
            cout << i * (n - 1) + j << " ";
        }
        cout << endl;
    }
    for(int i = 2; i <= n; ++i) {
        // consider all previous pairs
        // kita gaboleh buat pair yang sebelumnya udah ke visit
    }
    return 0;
}