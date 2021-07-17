#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int mod = 1e9 + 7;
vector<ll> facts(1e6 + 1, 1), inversefacts(1e6 + 1, 1);
ll addmod(ll a, ll b)
{
    return (a + b) % mod;
}
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2);
        tmp = mulmod(tmp, tmp);
        return b & 1 ? mulmod(tmp, a) : tmp;
    }
}
ll combinmod(ll a, ll b)
{
    return mulmod(facts[a], mulmod(inversefacts[b], inversefacts[a - b]));
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    for(int i = 1; i < facts.size(); ++i)
    {
        facts[i] = mulmod(facts[i - 1], i);
        inversefacts[i] = powmod(facts[i], mod - 2);
    }
    int n, m, k; string subsoal, w;
    cin >> subsoal >> n >> m >> k >> w;
    cout << mulmod(combinmod(m, k), powmod(powmod(2, n - 1), m)) << endl;
}