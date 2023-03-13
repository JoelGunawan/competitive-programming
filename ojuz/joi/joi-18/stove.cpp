#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int main() {
    // alien trick
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = a[1];
    // consider cost as dp[i]
    // maintain the minimum amount to achieve the desired minimum cost
    // dp[i] = min(dp[j] + cost(j, i) - penalty)
    int lb = 0, rb = 1e9, ans = -1;
    while(lb <= rb) {
        int mb = (lb + rb) / 2;
        // maintain rolling aja harusnya bs, tapi agk tricky karena ada shiftnya
        // actually tinggal maintain posisi T aja as negative
        pair<ll, int> curm = {-a[1], 0};
        pair<ll, int> dp[n + 1];
        //cout << mb << endl;
        for(int i = 1; i <= n; ++i) {
            dp[i] = {curm.fi + a[i] + mb + 1, curm.se + 1};
            //cout << "OUTPUT" << endl;
            //cout << curm.fi << " "<< a[i] << " " << mb << endl;
            //cout << curm.fi << " " << curm.se << " " << dp[i].fi - a[i] << " " << dp[i].se << endl;
            curm = min(curm, {dp[i].fi - a[i + 1], dp[i].se});
        }
        if(dp[n].se <= k) {
            // tambah penalti -> less k
            ans = mb;
            rb = mb - 1;
        }
        else
            lb = mb + 1;
    }
    pair<ll, int> curm = {-a[1], 0};
    pair<ll, int> dp[n + 1];
    //cout << ans << endl;
    for(int i = 1; i <= n; ++i) {
        dp[i] = {curm.fi + a[i] + ans + 1, curm.se + 1};
        //cout << i << endl;
        //cout << i << " " << dp[i].fi << " " << dp[i].se << endl;
        //cout << curm.fi << " " << curm.se << " " << dp[i].fi - a[i] << " " << dp[i].se << endl;
        curm = min(curm, {dp[i].fi - a[i + 1], dp[i].se});
    }
    ll res = dp[n].fi;
    //cout << res << " ";
    res -= 1ll * k * ans;
    cout << res << endl;
}