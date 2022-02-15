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
    int n, q;
    cin >> n >> q;
    int x[n + 1], in;
    memset(x, 0, sizeof(x));
    for(int i = 1; i <= n; ++i) {
        cin >> in;
        x[i] = x[i - 1] ^ in;
    }
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << (x[r] ^ x[l - 1]) << endl;
    }
    return 0;
}