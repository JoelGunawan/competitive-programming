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
    scanf("%d%d", &n, &m);
    int b[n];
    map<int, int> a;
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]), b[i] %= m, ++a[b[i]];
    int res = 0;
    for(auto i : a) {
        if(i.fi == 0 || 2 * i.fi == m) {
            res = max(res, i.se);
        }
        else {
            //cout << a[m - i.fi] << " " << i.se << endl;
            res = max(res, min(i.se, a[m - i.fi]) + 1);
        }
    }
    if(res > n / 2)
        cout << -1 << endl;
    else
        cout << res << endl;
    return 0;
}