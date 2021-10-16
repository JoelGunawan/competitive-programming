#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define pf push_front
#define pq priority_queue
#define ll long long
#define lll long long long
#define lb lower_bound
#define ub upper_bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp *= tmp; tmp %= mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
void test_case()
{
    string s;
    cin >> s;
    ll dp[s.size() + 1];
    dp[0] = 0;
    ll zero_ending = 0, one_ending = 0;
    for(int i = 1; i <= s.size(); ++i)
    {
        if(s[i - 1] == '0')
        {
            dp[i] = (2 * dp[i - 1] + one_ending) % mod;
            zero_ending += powmod(2, i - 1);
            zero_ending %= mod;
        }
        else
        {
            dp[i] = (2 * dp[i - 1] + zero_ending) % mod;
            one_ending += powmod(2, i - 1);
            one_ending %= mod;
        }
    }
    cout << dp[s.size()] << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}