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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    // observasi: hanya ada K level maks perubahan
    // brute force tiap kemungkinan K dari 1 hingga i
    // cek boundarynya di mana
    // pakai two pointers bisa
    // maintain K two pointers algorithms
    // find minimum in range (range query?)
    // O(NK^2)
    int left[n + 1][k + 1], cnt[(int)5e4 + 1][k + 1], violation[k + 1];
    memset(cnt, 0, sizeof(cnt));
    memset(left, 0, sizeof(left));
    memset(violation, 0, sizeof(violation));
    for(int i = 0; i <= k; ++i)
        left[0][i] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            left[i][j] = left[i - 1][j];
            if(cnt[h[i]][j] >= m)
                ++violation[j];
            ++cnt[h[i]][j];
            while(violation[j] > j) {
                // perpendek left
                if(cnt[h[left[i][j]]][j] > m)
                    --violation[j];
                --cnt[h[left[i][j]]][j];
                ++left[i][j];
            }
            //cout << i << " " << j << " " << left[i][j] << endl;
        }
    }
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= min(i - 1, k); ++j) {
            dp[i][j] = 1e9;
            for(int l = 0; l <= j; ++l) {
                dp[i][j] = min(dp[i][j], dp[left[i][l] - 1][j - l] + 1);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}