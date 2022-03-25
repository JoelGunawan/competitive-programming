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
    ll a[4 * n];
    for(int i = 0; i < 4 * n; ++i)
        cin >> a[i];
    sort(a, a + 4 * n);
    bool ans = 1;
    for(int i = 0; i < 2 * n; ++i)
        if(a[2 * i] != a[2 * i + 1])
            ans = 0;
    ll l = 0, r = 4 * n - 1, actual = a[0] * a[4 * n - 1];
    while(l < r) {
        if(a[l] * a[r] != actual)
            ans = 0;
        l += 2, r -= 2;
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}