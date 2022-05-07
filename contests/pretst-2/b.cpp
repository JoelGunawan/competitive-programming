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
void solve(int x, int n) {
    if(x <= n) {
        // buat sendiri
        // lis brute force
        for(int i = 0; i < x; ++i) {
            cout << "0 ";
        }
        for(int i = 0; i )
    }
    else {

    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int l, r, n;
    cin >> l >> r >> n;
    for(int i = l; i <= r; ++i) {
        solve(i, n);
    }
    return 0;
}