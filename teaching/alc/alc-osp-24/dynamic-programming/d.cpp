#include <bits/stdc++.h>
using namespace std;
int h[1005], s[1005];
int memo[1005][100005];
int dp(int x, int y) {
    if(memo[x][y] != -1)
        return memo[x][y];
    // belum beli buku/lihat buku -> 0 halaman
    if(x == 0 || y == 0)
        return 0;
    else {
        // 2 kemungkinan
        // beli buku/tidak beli
        int var;
        // tidak beli
        var = dp(x - 1, y);
        // beli
        if(y >= h[x]) {
            var = max(var, dp(x - 1, y - h[x]) + s[x]);
        }
        return var;
    }
}
int main() {
    memset(memo, -1, sizeof(memo));
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
    cout << dp(n, x) << endl; // mempertimbangkan n buku dan harga x, berapa maksimal halaman yg bisa didapat?
}