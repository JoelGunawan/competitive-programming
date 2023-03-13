#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    // dp[i] = min(dp[0...i-2]) + a[i] - c
    // nanti add c klo chosen kurang
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    ll dist[n];
    for(ll i = 1; i < n; ++i)
        dist[i] = a[i + 1] - a[i];
    // using alien trick try different penalties to find min final ans
    // choose as little as possible
    ll lb = 0, rb = 1e9, ans;
    while(lb <= rb) {
        ll mb = (lb + rb) / 2;
        pair<long long, ll> dp[n];
        dp[0] = {0, 0};
        pair<long long, ll> curm = {0, 0};
        //cout << "DP" << endl;
        for(ll i = 1; i < n; ++i) {
            dp[i] = {curm.first + dist[i] - mb, curm.second + 1};
            //cout << dp[i].first << " " << dp[i].second << endl;
            curm = min(curm, dp[i - 1]);
        }
        curm = min(curm, dp[n - 1]);
        // curm -> result
        if(curm.second <= k) {
            // penalti terlalu sedikit
            //cout << curm.first << " " << curm.second << " " << mb << endl;
            lb = mb + 1, ans = mb;
        }
        else {
            // penalti terlalu banyak
            rb = mb - 1;
        }
    }
    pair<long long, ll> dp[n];
    dp[0] = {0, 0};
    pair<long long, ll> curm = {0, 0};
    for(ll i = 1; i < n; ++i) {
        dp[i] = {curm.first + dist[i] - ans, curm.second};
        curm = min(curm, dp[i - 1]);
    }
    curm = min(curm, dp[n - 1]);
    curm.first += 1ll * curm.second * ans;
    while(curm.second < k) {
        ++curm.second;
        curm.first += ans;
    }
    cout << curm.first << endl;
}