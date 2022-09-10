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
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b[n + 1];
    for(int i = 1; i <= n; ++i) {
        b[a[i]].pb(i);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << lower_bound(b[x].begin(), b[x].end(), r + 1) - lower_bound(b[x].begin(), b[x].end(), l) << endl;
    }
    return 0;
}