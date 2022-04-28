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
void tc() {
    int n;
    cin >> n;
    int p[2 * n];
    for(int i = 0; i < 2 * n; ++i)
        cin >> p[i];
    // kalo unlock, nextnya boleh terserah
    // kalo ngga unlock, harus lebih dari semua yang di unlock
    // semua kemungkinan unlock/not
    // kalo ada yang bebas -> lebih besar dari semua, jadi sama aja reset section
    // setiap ada new maximum, 
    int cnt = 0, x = p[0];
    vector<int> sizes;
    for(int i = 0; i < 2 * n; ++i) {
        if(p[i] > x) {
            sizes.pb(cnt);
            x = p[i];
            cnt = 0;
        }
        ++cnt;
    }
    sizes.pb(cnt);
    bool dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i : sizes) {
        //cout << i << " ";
        for(int j = n; j - i >= 0; --j)
            dp[j] |= dp[j - i];
    }
    //cout << endl;
    if(dp[n])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}   
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}