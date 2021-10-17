#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int mod = 1e9 + 7;
ll fact[(int)1e6 + 1];
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
ll combinmod(ll a, ll b)
{
    if(a < b)
        return 0;
    else if(a == b)
        return 1;
    else
        return (((fact[a] * powmod(fact[b], mod - 2)) % mod) * powmod(fact[a - b], mod - 2)) % mod;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int counter[n + 1], used[n + 1], used_counter = 0;
    memset(counter, 0, sizeof(counter)); memset(used, 0, sizeof(used));
    for(int i = 0; i < n; ++i)
    {
        if(!used[a[i]])
            ++used_counter;
        ++counter[a[i]], used[a[i]] = 1;
    }
    if(n <= 20)
    {
        vector<int> num;
        for(int i = 0; i <= n; ++i)
            if(used[i])
                num.pb(i);
        // use bitmask approach
        int res = 0;
        for(int i = 0; i < (1 << num.size()); ++i)
        {
            int cur = 0;
            for(int j = 0; j < num.size(); ++j)
            {
                if(i & (1 << j))
                {
                    cur ^= counter[num[j]];
                }
            }
            if(cur == 0)
                ++res;
        }
        cout << res << endl;
    }
    else if(used_counter == 2)
    {
        // do 2 different number test case
        int first_num, second_num;
        for(int i = 0; i <= n; ++i)
            if(counter[i] > 0)
            {
                first_num = counter[i];
                break;
            }
        second_num = n - first_num;
        if((first_num ^ second_num) == 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
    else if(true)
    {
        
    }
    else
    {
        fact[0] = 1;
        for(int i = 1; i <= 1e6; ++i)
            fact[i] = (fact[i - 1] * i) % mod;
        // there is one of each, in this case we need to check whether n is even or odd and determine from there
        ll res = 0;
        if(n % 2 == 1)
        {
            // select an odd number to remove
            // use combinatorics
            for(int i = 1; i <= n; i += 2)
                res = (res + combinmod(n, i)) % mod;
        }
        else
        {
            // select an even number to remove
            for(int i = 0; i <= n; i += 2)
                res = (res + combinmod(n, i)) % mod;
        }
        cout << res << endl;
    }
}
int main()
{
    fast_io();
    solve();
    return 0;
}