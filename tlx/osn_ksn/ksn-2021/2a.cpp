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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 2];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = 0, a[n + 1] = 0;
    vector<int> st;
    ll pref[n + 1], dp[n + 1];
    memset(pref, 0, sizeof(pref));
    memset(dp, 0, sizeof(dp));
    int left[n + 2], right[n + 2];
    memset(left, 0, sizeof(left));
    st.pb(0);
    pref[0] = 1;
    dp[0] = 1;
    // nilai dp ditambah semua yang ada di stack
    // karena yang di stack itu minimum antara x, y
    ll stack_res = 0;
    for(int i = 1; i <= n; ++i) {
        while(a[st.back()] > a[i])
            stack_res -= dp[st.back()], st.pop_back();
        left[i] = st.back();
        if(left[i] == 0)
            dp[i] = pref[i - 1] - pref[left[i]] + stack_res + 1;
        else
            dp[i] = pref[i - 1] - pref[left[i]] + stack_res;
        dp[i] %= mod;
        pref[i] = pref[i - 1] + dp[i];
        pref[i] %= mod;
        st.pb(i);
        stack_res += dp[i];
        stack_res %= mod;
        stack_res += mod;
        stack_res %= mod;
    }
    ll res = 0;
    st.clear();
    st.pb(n + 1);
    for(int i = n; i >= 1; --i) {
        while(a[st.back()] > a[i])
            st.pop_back();
        right[i] = st.back();
        st.pb(i);
    }
    for(int i = 1; i <= n; ++i) {
        if(right[i] == n + 1)
            res += dp[i];
    }
    cout << ((res % mod) + mod) % mod << endl;
    return 0;
}