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
    // overkill solution: lazy dynamic seg
    // other solution -> use binser
    int n, m;
    cin >> n >> m;
    int a[n], b[n], c[n], d[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        c[i] = a[i], d[i] = b[i];
    }
    sort(c, c + n);
    sort(d, d + n);
    /*
    for(auto i : c)
        cout << i << " ";
    cout << endl;
    for(auto i : d)
        cout << i << " ";
    cout << endl;
    */
    for(int i = 0; i < n; ++i) {
        // find d yang kurang dari a[i]
        // find c yang lebih dari b[i]
        //cout << (lower_bound(d, d + n, a[i]) - d) << " " << ((c + n) - lower_bound(c, c + n, b[i] + 1)) << endl;
        cout << n - (lower_bound(d, d + n, a[i]) - d) - ((c + n) - lower_bound(c, c + n, b[i] + 1)) - 1 << endl;
    }
    return 0;
}