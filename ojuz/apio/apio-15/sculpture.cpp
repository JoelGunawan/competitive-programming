    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    int main() {
        int n, a, b;
        cin >> n >> a >> b;
        // antara a ke b, berarti harus maintain berapa aja sums yg mgkn
        // coba buat dp[n][k]?
        int y[n + 1];
        ll pref[n + 1];
        pref[0] = 0;
        for(int i = 1; i <= n; ++i)
            cin >> y[i], pref[i] = pref[i - 1] + y[i];;
        // a = 1 -> size only from 1...b
        // else -> brute force every size
        if(a == 1) {
            ll notchosen = 0, chosen = 0;
            for(int i = 62; i >= 0; --i) {
                // create partition where sum of everything does not have ith bit on and still conforms to previous selected
                // try create partition without 1 << i, in
                int dp[n + 1];
                fill(dp, dp + n + 1, 1e9);
                dp[0] = 0;
                for(int j = 1; j <= n; ++j) {
                    for(int k = 1; k <= j; ++k) {
                        if(!((pref[j] - pref[k - 1]) & (notchosen | (1ll << i)))) {
                            dp[j] = min(dp[j], dp[k - 1] + 1);
                        }
                    }
                }
                if(dp[n] <= b)
                    notchosen += 1ll << i;
                else
                    chosen += 1ll << i;
            }
            cout << chosen << endl;
        }
        else {
            ll chosen = 0, notchosen = 0;
            for(int i = 62; i >= 0; --i) {
                // make dp size of n, k
                bool dp[n + 1][b + 1];
                memset(dp, 0, sizeof(dp));
                dp[0][0] = 1;
                for(int j = 1; j <= n; ++j) {
                    for(int k = 1; k <= j; ++k) {
                        if(!((pref[j] - pref[k - 1]) & (notchosen | (1ll << i)))) {
                            for(int l = 1; l <= b; ++l) {
                                dp[j][l] |= dp[k - 1][l - 1];
                            }
                        }
                    }
                }
                bool ans = 0;
                for(int j = a; j <= b; ++j)
                    ans |= dp[n][j];
                if(ans)
                    notchosen += 1ll << i;
                else
                    chosen += 1ll << i;
            }
            cout << chosen << endl;
        }
    }