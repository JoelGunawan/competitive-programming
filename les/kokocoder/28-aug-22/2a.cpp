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
    memset(pref, 0, sizeof(pref));
    memset(dp, 0, sizeof(dp));
    stack<int> st; st.push(0);
    a[0] = 0;
    ll stack_sum = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[i] <= a[st.top()]) {
            stack_sum -= dp[st.top()];
            st.pop();
        }
        int nse = st.top();
        dp[i] = stack_sum + pref[i - 1] - pref[nse];
        if(nse == 0)
            ++dp[i];
        st.push(i);
        stack_sum += dp[i];
        stack_sum %= mod;
        stack_sum += mod;
        stack_sum %= mod;
        pref[i] = (pref[i - 1] + dp[i]) % mod;
    }
    ll res = dp[n];
    int cur_min = a[n];
    for(int i = n - 1; i >= 1; --i) {
        cur_min = min(cur_min, a[i]);
        if(cur_min == a[i])
            res += dp[i];
    }
    cout << res % mod << endl;
}