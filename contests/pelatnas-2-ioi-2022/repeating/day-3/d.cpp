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
    int n, m;
    cin >> n >> m;
    int a[n + m - 1], b[n + m - 1];
    for(int i = 0; i < n + m - 1; ++i)
        cin >> a[i];
    for(int i = 0; i < n + m - 1; ++i)
        cin >> b[i];
    ll res = 0;
    for(int i = 0; i < n + m - 1; ++i)
        res += min(a[i], b[n + m - 2 - i]);
    cout << res << endl;
    return 0;
}