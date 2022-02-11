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
    int x[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x, x + n);
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        cout << upper_bound(x, x + n, m) - x << endl;
    }
    return 0;
}