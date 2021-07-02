#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
const int mod = 1e9 + 7;
vector<ll> fact(1e5 + 2, 0);
ll sub(ll a, ll b)
{
    ll res = a - b;
    res %= mod;
    if(res < 0)
        res += mod;
    return res;
}
ll mul(ll a, ll b)
{
    return (a * b) % mod;
}
ll add(ll a, ll b)
{
    return (a + b) % mod;
}
ll generateFact(ll a)
{
    if(fact[a])
        return fact[a];
    if(a == 0)
        fact[a] = 1;
    else
        fact[a] = mul(generateFact(a - 1), a);
    return fact[a];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    generateFact(1e5 + 1);
    string s; int n, k;
    cin >> s >> n >> k;
    vector<int> a(n), b(n), h(k + 1, 0);
    vector<vector<int>> lama(k + 1), baru(k + 1);
    for(int i = 1; i <= k; ++i)
        cin >> h[i];
    int in;
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        lama[in].push_back(i + 1);
    }
    for(int i = 0; i < n; ++i)
    {
        cin >> in;
        baru[in].push_back(i + 1);
    }
    // basically we check for each bridge and check if it is possible, and multiply it to the end result
    ll res = 1;
    for(int i = 1; i <= k; ++i)
    {
        // calculate the amount for each bridge
        // if the bridge has a baru at the exact same height, it can be filled by any variable
        // check lama that is lower and lama that is higher
        int lamalower = 0, lamahigher = 0, barulower = 0, baruhigher = 0;
        bool lamasame = 0, barusame = 0;
        // fill in the values
        for(int j = 0; j < lama[i].size(); ++j)
        {
            if(lama[i][j] < h[i])
                ++lamalower;
            else if(lama[i][j] > h[i])
                ++lamahigher;
            else lamasame = 1;
        }
        for(int j = 0; j < baru[i].size(); ++j)
        {
            if(baru[i][j] < h[i])
                ++barulower;
            else if(baru[i][j] > h[i])
                ++baruhigher;
            else
                barusame = 1;
        }
        if(lamasame && barusame)
        {
            if(abs(lamalower - baruhigher) > 1 || abs(lamahigher - barulower) > 1)
            {
                res = 0;
                break;
            }
            else if(lamahigher == barulower)
                // tengah ke atas + tengah ke bawah - tengah
                res = mul(res, add(mul(fact[baruhigher + 1], fact[barulower]), sub(mul(fact[baruhigher], fact[barulower + 1]), mul(fact[baruhigher], fact[barulower]))));
            else
            {
                if(lamalower > baruhigher)
                    res = mul(res, mul(fact[baruhigher + 1], fact[barulower]));
                else
                    res = mul(res, mul(fact[baruhigher], fact[barulower + 1]));
            }
        }
        else if(barusame)
        {
            if(abs(lamalower - baruhigher) > 1 || abs(lamahigher - barulower) > 1)
            {
                res = 0;
                break;
            }
            else
                res = mul(res, mul(fact[lamahigher], fact[lamalower]));
        }
        else if(lamasame)
        {
            if(abs(lamalower - baruhigher) > 1 || abs(lamahigher - barulower) > 1)
            {
                res = 0;
                break;
            }
            else
                res = mul(res, mul(fact[baruhigher], fact[barulower]));
        }
        else
        {
            if(lamalower != baruhigher)
            {
                res = 0;
                break;
            }
            else
                res = mul(res, mul(fact[lamalower], fact[lamahigher]));
        }
    }
    cout << res << endl;
    return 0;
}