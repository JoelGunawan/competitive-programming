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
    int a[3][4];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j) {
            scanf("%d", &a[i][j]);
        }
    int common[4];
    for(int i = 0; i < 4; ++i) {
        common[i] = a[0][i];
        for(int j = 1; j < 3; ++j)
            common[i] = min(common[i], a[j][i]);
    }
    int total = 0;
    for(int i = 0; i < 4; ++i)
        total += common[i];
    if(total < 1e6)
        printf("IMPOSSIBLE\n");
    else {
        // find common config
        int sum = 0;
        for(int i = 0; i < 4; ++i) {
            sum += common[i];
            if(sum > 1e6) {
                common[i] -= (sum - 1e6);
                sum = 1e6;
            }
        }
        for(int i = 0; i < 4; ++i)
            printf("%d ", common[i]);
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}