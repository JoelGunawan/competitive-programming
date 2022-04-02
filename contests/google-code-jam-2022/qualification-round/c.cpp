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
void solve() {
    int n;
    scanf("%d", &n);
    int a[n];
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int cnt = 0;
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        if(a[i] > cnt)
            ++cnt;
    }
    printf("%d\n", cnt);
}
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}