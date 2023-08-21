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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // make into sizes of sums?
    // buat dp, simpan all possible size kelebihan '(' di kondisi sekarang
    // tiap n, transisi O(n)
    vector<int> segments;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> segments;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                ++cnt;
                continue;
            }
            if(s[i] != s[i - 1]) {
                segments.pb(cnt);
                cnt = 0;
            }
            ++cnt;
        }
        segments.pb(cnt);
        int sum = n;
        n = segments.size();
        bool dp[n][sum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][segments[0]] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j <= sum; ++j) {
                if(j - segments[i] >= 0)
                    dp[i][j] |= dp[i - 1][j - segments[i]];
                if(j + segments[i] <= sum)
                    dp[i][j] |= dp[i - 1][j + segments[i]];
            }
        }
        if(dp[n - 1][0]) {
            cout << "YES" << endl;
            string x = ""; 
            bool state = 1;
            int cur = 0;
            for(int i = n - 1; i >= 0; --i) {
                if(i == 0)
                    state = 0;
                else if(cur - segments[i] >= 0 && dp[i - 1][cur - segments[i]])
                    state = 0, cur -= segments[i];
                else
                    state = 1, cur += segments[i];
                if(state) {
                    for(int j = 0; j < segments[i]; ++j)
                        x += ')';
                }
                else {
                    for(int j = 0; j < segments[i]; ++j)   
                        x += '(';
                }
            }
            reverse(x.begin(), x.end());
            cout << x << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}