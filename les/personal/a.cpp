// include semua
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    int a[n + 1][m + 1], b[m + 1][p + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= p; ++j) {
            cin >> b[i][j];
        }
    }
    int c[n + 1][p + 1];
    memset(c, 0, sizeof(c));
    // memset -> 0 atau -1 di array integer
    // di array bool -> 0 atau 1
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= p; ++j) {
            for(int k = 1; k <= m; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= p; ++j)
            cout << c[i][j] << " ";
        cout << endl;
    }
}