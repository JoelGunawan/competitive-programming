#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    // 1...n
    // baris, col
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            // cout << "DEBUG " << i << " " << j << " " << a[i][j] << endl;
        }
    }
    // i yg mana, j yg mana?
    // i -> column
    for(int i = 1; i <= m; ++i) {
        // j -> baris
        for(int j = n; j >= 1; --j) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }
}