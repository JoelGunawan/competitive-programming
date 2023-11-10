// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("O3")
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
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    int a[n + 1];
    s = "0" + s;
    for(int i = 0; i <= n; ++i)
        a[i] = s[i] - '0';
    int tmp1 = 1, tmp2 = 1;
    while(tmp1 <= n)
        tmp1 *= 2, ++tmp2;
    //cout << tmp1 << " " << tmp2 << endl;
    ++tmp2;
    int dp[n + 1][9 * tmp2 + 10][2];
    memset(dp, -1, sizeof(dp));
    //cout << "TEST" << endl;
    //cout.flush();
    for(int i = 1; i <= n; ++i) {
        //cout << "TEST" << endl;
        dp[i][a[i]][1] = i;
        dp[i][a[i] + a[dp[i][a[i]][1] - 1]][0] = dp[i][a[i]][1] - 1;
        if(i != 1)
            dp[i][a[i] + a[i - 1]][1] = i - 1;
        // dp[n][c][0] = furthest L dengan posisi n cost c dimana posisi pengambilan pertama di n
        // dp[n][c][1] = furthest L dengan posisi n cost c dimana posisi pengambilan 
        // transisi, gunakan state 0 sebagai memo
        int curx = 1e9;
        //cout << "ENTER LOOP" << endl;
        // tc salah -> 9213875632165 (5 lebih dari seharusnya)
        for(int j = a[i] + 1; j <= 9 * tmp2; ++j) {
            //cout << "PROC " << j << endl;
            if(dp[i][j][0] != -1)
                curx = min(curx, dp[i][j][0]);
            dp[i][j][1] = dp[i][j - 1][1];
            //cout << curx << endl;
            if(curx == 1e9)
                continue;
            //cout << "HERE" << endl;
            //cout << i << " " << j << endl;
            //cout << curx - 1 << " " << j - a[curx] << " " << dp[curx - 1][j - a[curx]][1] << endl;
            if(curx <= 1)
                dp[i][j][1] = 1;
            else if(dp[curx - 1][j - a[curx]][1] != -1 && (dp[i][j][1] == -1 || dp[curx - 1][j - a[curx]][1] < dp[i][j][1]))
                dp[i][j][1] = dp[curx - 1][j - a[curx]][1];
            dp[i][j][1] = min(dp[i][j][1], max(1, curx));
            //cout << "MID LOOP" << endl;
            //cout << i << " " << j << " " << 1 << endl;
            //cout << dp[i][j][1] << endl;
            if(dp[i][j][1] >= 1 && j + a[dp[i][j][1] - 1] <= 9 * tmp2) {
                //cout << "INSIDE IF" << endl;
                if(dp[i][j + a[dp[i][j][1] - 1]][0] == -1 || dp[i][j][1] - 1 < dp[i][j + a[dp[i][j][1] - 1]][0])
                    dp[i][j + a[dp[i][j][1] - 1]][0] = dp[i][j][1] - 1;
            }
            //cout << "ONE LOOP" << endl;
        }
        for(int j = 1; j <= 20; ++j)
            cout << dp[i][j][1] << " ";
        cout << endl;
    }
    for(int j = 0; j <= 9 * tmp2; ++j) {
        //cout << dp[n][j][1] << " ";
        if(dp[n][j][1] == 1 || dp[n][j][1] == 0) {
            cout << j << endl;
            break;
        }
    }
    //cout << endl;
    return 0;
}