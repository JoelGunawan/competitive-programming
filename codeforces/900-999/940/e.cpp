// header file
#include <bits/stdc++.h>
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
struct sparse_table {
    int a[17][100001];
    int log[100001];
    sparse_table() {
        for(int i = 0; i < 17; ++i)
            for(int j = 0; j < 100001; ++j)
                a[i][j] = INT_MAX;
        log[1] = 0;
        for(int i = 2; i <= 100001; ++i)
            log[i] = log[i / 2] + 1;
    }
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            a[0][i] = arr[i];
        for(int i = 1; i < 17; ++i) {
            for(int j = 0; j < 100001; ++j) {
                a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int tmp = log[r - l + 1];
        // find msb
        return min(a[tmp][l], a[tmp][r - (1 << tmp) + 1]);
    }
};
sparse_table sp;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        arr[i] = a[i];
    sp.build(arr);
    // segments of length c
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if(i >= c) {
            dp[i] = max(dp[i - c] + sp.query(i - c, i - 1), dp[i]);
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; ++i)
        sum += a[i];
    cout << sum - dp[n] << endl;
    return 0;
}