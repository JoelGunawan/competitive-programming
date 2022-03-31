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
    ll res = 0;
    for(int i = 1; i < n; ++i) {
        if(x[i] < x[i - 1])
            res += x[i - 1] - x[i], x[i] = x[i - 1];
    }
    cout << res << endl;
    return 0;
}