#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    int a[n + 2];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = 0, a[n + 1] = 0;
    stack<int> st;
    long long stack_sum = 0;
    long long pref[n + 5], dp[n + 5];
    memset(pref, 0, sizeof(pref));
    memset(dp, 0, sizeof(dp));
    int left[n + 5], right[n + 5];
    memset(left, 0, sizeof(left));
    st.push(0);
    dp[0] = 1;
    pref[0] = dp[0];
    for(int i = 1; i <= n; ++i) {
        while(a[st.top()] > a[i])
            stack_sum -= dp[st.top()], st.pop();
        if(stack_sum < 0)
            stack_sum %= mod, stack_sum += mod;
        left[i] = st.top();
        dp[i] = pref[i - 1] - pref[left[i]] + stack_sum;
        if(left[i] == 0) 
            dp[i] += 1;
        dp[i] %= mod;
        pref[i] = pref[i - 1] + dp[i];
        pref[i] %= mod;
        st.push(i);
        stack_sum += dp[i];
        stack_sum %= mod;
    }
    while(!st.empty())
        st.pop();
    st.push(n + 1);
    for(int i = n; i >= 1; --i) {
        while(a[st.top()] > a[i])
            st.pop();
        right[i] = st.top();
        st.push(i);
    }
    long long res = 0;
    for(int i = 1; i <= n; ++i) {
        if(right[i] == n + 1)
            res += dp[i];
    }
    cout << res % mod << endl;
}