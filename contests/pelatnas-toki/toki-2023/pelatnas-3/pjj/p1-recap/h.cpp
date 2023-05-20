#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    if(n & 1 && m & 1) {
        cout << 0 << endl;
        return 0;
    }
    if(n == 1 || m == 1) {
        cout << 1 << endl;
        return 0;
    }
    long long dp[(1 << n)][2];
    memset(dp, 0, sizeof(dp));
    dp[(1 << n) - 1][0] = 1;
    int tmp = 0;
    for(int i = 0; i < m; ++i) {
        // boleh ambil dr last pos as 2x1
        // boleh ambil dr first pos as 1x2
        for(int j = 0; j < n; ++j) {
            // dp
            // boleh ga ambil juga, yg penting last itu harus diambil
            ++tmp;
            int idx = tmp & 1;
            for(int k = 0; k < (1 << n); ++k) {
                // jika last pos 0, maka harus diambil
                // jika tidak boleh ambil previous pos atau boleh kosongin aja
                if(k < (1 << (n - 1))) {
                    // berarti last pos 0, harus diambil
                    dp[(k << 1) + 1][idx] += dp[k][idx ^ 1];
                }
                else {
                    // boleh ambil previous pos
                    // atau boleh kosongin aja
                    dp[(k << 1) % (1 << n)][idx] += dp[k][idx ^ 1];
                    // bisa ambil previous
                    if((k & 1) == 0 && j != 0) {
                        // ambil previous bs pake (horizontal)
                        // bisa dilakuin kalo j bukan 0
                        //cout << "TEST" << " " << i << " " << j << " " << k << " " << (k << 1) + 3 << endl;
                        dp[((k << 1) + 3) % (1 << n)][idx] += dp[k][idx ^ 1];
                    }
                }
            }
            for(int k = 0; k < (1 << n); ++k) {
                dp[k][idx ^ 1] = 0;
                dp[k][idx] %= mod;
                //cout << i << " " << j << " " << k << " " << dp[k][idx] << endl;
            }
        }
    }    
    cout << dp[(1 << n) - 1][tmp & 1] << endl;
}