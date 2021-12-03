#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
int mod = 1e9 + 7;
ll fact[2 * (int)1e5 + 1];
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
ll combinmod(ll a, ll b)
{
    return mulmod(mulmod(fact[a], powmod(fact[a - b], mod - 2)), powmod(fact[b], mod - 2));
}
void test_case()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    fact[0] = 1;
    for(int i = 1; i <= 2 * 1e5; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    /*
    for(int i = 1; i < (1 << n); ++i)
    {
        vector<int> cur;
        for(int j = 0; j < n; ++j)
            if((1 << j) & i)
                cur.pb(a[j]);
        for(int j = 0; j < cur.size(); ++j)
            cout << cur[j] << " ";
        cout << endl;
    }
    */
    int odd = 0;
    int counter[31];
    memset(counter, 0, sizeof(counter));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < 31; ++j)
            if((1 << j) & a[i])
            {
                ++counter[j];
                break;
            }     
    }
    // each sequence can't contain 1 even_even or 1 even_odd without an odd
    ll res = powmod(2, n) - 1;
    int prefix[31];
    prefix[0] = counter[0];
    for(int i = 1; i < 31; ++i)
        prefix[i] = prefix[i - 1] + counter[i];
    for(int i = 1; i < 31; ++i)
    {
        // all subsets including an odd amount of counter[i]
        // with or without all counter[j] j > i
        // counter[i] choose 1, choose 3, choose 5, choose 7, etc
        int choose = 1;
        while(choose <= counter[i])
        {
            //cout << combinmod(counter[i], choose) << " " << powmod(2, prefix[30] - prefix[i]) << endl;
            res -= mulmod(combinmod(counter[i], choose), powmod(2, prefix[30] - prefix[i]));
            res += mod;
            res %= mod;
            choose += 2;
        }
        //cout << counter[i] << " DEB " << res << endl;
    }
    cout << ((res % mod) + mod) % mod << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    test_case();
    return 0;
}