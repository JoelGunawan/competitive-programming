    // header file
    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
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
    using namespace __gnu_pbds;
    typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
    typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    ll solve(ll a) {
        if(a < 0)
            return 0;
        // palindrome free -> yang penting 2 bilangan terakhir
        string s = to_string(a);
        // fi -> idx
        // se -> second last digit
        // ti -> last digit
        // fo -> follow s or not
        ll dp[s.size()][11][10][2];
        memset(dp, 0, sizeof(dp));
        // 10 -> case leading zero
        // handle case leading zero
        for(int i = 0; i < s.size(); ++i) {
            if(i == 0) {
                for(int j = 1; j < s[i] - '0'; ++j)
                    dp[i][10][j][0] = 1;
                dp[i][10][s[i] - '0'][1] = 1;
            }
            else if(i == 1) {
                for(int j = 1; j < 10; ++j)
                    dp[i][10][j][0] = 1;
                for(int j = 0; j < 10; ++j) {
                    // ambil dari non leadingnya terserah
                    // tidak boleh sama dengan pr
                    for(int k = 0; k < 10; ++k) {
                        if(k == j)
                            continue;
                        // j last digit
                        // k second last
                        dp[i][k][j][0] += dp[i - 1][10][k][0];
                        if(j == s[i] - '0' && k == s[i - 1] - '0')
                            dp[i][k][j][1] += dp[i - 1][10][k][1];
                        else if(j < s[i] - '0')
                            dp[i][k][j][0] += dp[i - 1][10][k][1];
                    }
                }
            }
            else {
                for(int j = 1; j < 10; ++j)
                    dp[i][10][j][0] = 1;
                for(int j = 0; j < 10; ++j) {
                    for(int k = 0; k < 10; ++k) {
                        if(j == k)
                            continue;
                        for(int l = 0; l <= 10; ++l) {
                            if(j == l || k == l)
                                continue;
                            // j last digit
                            // k second last
                            // l third last
                            dp[i][k][j][0] += dp[i - 1][l][k][0];
                            if(j == s[i] - '0' && k == s[i - 1] - '0' && l == s[i - 2] - '0')
                                dp[i][k][j][1] += dp[i - 1][l][k][1];
                            else if(j < s[i] - '0')
                                dp[i][k][j][0] += dp[i - 1][l][k][1];
                        }
                    }
                }
            }
        }
        ll ret = 0;
        for(int i = 0; i <= 10; ++i)
            for(int j = 0; j < 10; ++j) {
                if(i == 10 && j == 0)
                    continue;
                ret += dp[s.size() - 1][i][j][0] + dp[s.size() - 1][i][j][1];
            }
        //for(int i = 0; i < 3; ++i) {
        //    cout << "DIGIT " << i << endl;
        //    for(int j = 0; j <= 10; ++j) {
        //        cout << "SECOND LAST " << j << endl;
        //        for(int k = 0; k < 10; ++k) {
        //            cout << "LAST " << k << " " << dp[i][j][k][0] << " " << dp[i][j][k][1] << endl;
        //        }
        //        cout << endl;
        //    }
        //}
        return ret + 1;
    }

    int main() {
        ios_base::sync_with_stdio(0); cin.tie(NULL);
        ll a, b;
        cin >> a >> b;
        // find res for b and find res for a
        cout << solve(b) - solve(a - 1) << endl;
        return 0;
    }