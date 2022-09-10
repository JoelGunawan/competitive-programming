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
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[n], b[m];
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + m);
    int b_idx = 0, res = 0;
    for(int i = 0; i < n; ++i) {
        if(b_idx == m)
            break;
        while(b_idx < m && b[b_idx] < a[i] - k)
            ++b_idx;
        if(b_idx < m && abs(b[b_idx] - a[i]) <= k)
            ++b_idx, ++res;
    }
    printf("%d\n", res);
    return 0;
}