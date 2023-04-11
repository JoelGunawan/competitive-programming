#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll dp[100005][2];
int pr[100005][205];
ll pref[100005];
int n;
void dnc(int depth, int l, int r, int optl, int optr) {
    if(l > r)
        return;
    int optc = 0, mid = (l + r) / 2;
    ll optres = 0;
    for(int i = min(optl, mid - 1); i <= min(optr, mid - 1); ++i) {
        ll cur = (pref[mid] - pref[i]) * (pref[n] - pref[mid]) + dp[i][(depth & 1) ^ 1];
        if(cur >= optres)
            optc = i, optres = cur;
    }
    dp[mid][depth & 1] = optres;
    pr[mid][depth] = optc;
    dnc(depth, l, mid - 1, optl, optc);
    dnc(depth, mid + 1, r, optc, optr);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i], pref[i] = pref[i - 1] + a[i];
    for(int i = 1; i <= n; ++i)
        dp[i][1] = pref[i] * (pref[n] - pref[i]);
    for(int i = 2; i <= k; ++i)
        dnc(i, i, n - 1, i - 1, n - 1);
    ll res = 0;
    int res_idx = 0;
    for(int i = 1; i <= n - 1; ++i) {
        if(dp[i][k & 1] >= res)
            res_idx = i, res = dp[i][k & 1];
    }
    cout << res << endl;
    vector<int> ans;
    int idx2 = k;
    while(idx2) {
        ans.push_back(res_idx);
        res_idx = pr[res_idx][idx2];
        --idx2;
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    // splittingnya terurut dr awal sampai akhir
    // pake alien trick terus dp cht?
    // dp O(NKlogN)
}