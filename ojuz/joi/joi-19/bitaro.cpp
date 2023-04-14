#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    // find count o di kanan dan count i di bawah
    int x[n + 2][m + 2], y[n + 2][m + 2];
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 1; --j) {
            x[i][j] = x[i][j + 1] + (a[i][j] == 'O');
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= m; ++j) {
            y[i][j] = y[i + 1][j] + (a[i][j] == 'I');
        }
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'J')
                ans += 1ll * x[i][j] * y[i][j];
        }
    }
    cout << ans << endl;
}