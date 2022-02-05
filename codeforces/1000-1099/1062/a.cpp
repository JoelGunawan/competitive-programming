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
    a[0] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // amount of consecutive elements
    int res = 0, cur = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == a[i - 1] + 1)
            ++cur;
        else
            res = max(res, cur - 1), cur = 0;
    }
    if(a[n] == 1000)
        res = max(res, cur);
    else
        res = max(res, cur - 1);
    cout << res << endl;
    return 0;
}