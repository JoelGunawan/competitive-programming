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
void tc() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    // if count is even or cannot move
    // if n == 3 special case
    // n == 4 is always possible if can move
    if(n == 3 && a[1] & 1) {
        cout << -1 << endl;
        return;
    }
    else if(n == 3) {
        cout << a[1] / 2 << endl;
        return;
    }
    ll ans = 0;
    bool allone = 1;
    for(int i = 1; i < n - 1; ++i) {
        if(a[i] != 1)
            allone = 0;
    }
    for(int i = 1; i < n - 1; ++i) {
        ans += a[i] / 2 + a[i] % 2;
    }
    if(allone)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}