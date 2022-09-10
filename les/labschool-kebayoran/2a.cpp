#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    ll pref[n + 1], dp[n + 1];
    memset(dp, 0, sizeof(dp));
    memset(pref, 0, sizeof(pref));
    vector<int> st = {0};
    a[0] = 0;
    ll stack_sum = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[i] <= a[st.back()]) {
            stack_sum -= dp[st.back()];
            st.pop_back();
        }
        int nse = st.back();
        dp[i] = pref[i - 1] - pref[nse] + stack_sum;
        if(nse == 0)
            ++dp[i];
        dp[i] %= mod;
        st.push_back(i);
        stack_sum += dp[i];
        pref[i] = pref[i - 1] + dp[i];
        pref[i] %= mod;
    }
    ll res = dp[n];
    int cur_min = a[n];
    for(int i = n - 1; i >= 1; --i) {
        cur_min = min(cur_min, a[i]);
        if(cur_min == a[i])
            res += dp[i];
    }
    cout << ((res % mod) + mod) % mod << endl;
}