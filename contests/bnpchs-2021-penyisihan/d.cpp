#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ulll unsigned __int128
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int mod;
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
int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int phi(int a)
{
    int res = 0;
    for(int i = 1; i < a; ++i)
        if(gcd(i, a) == 1)
            ++res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b, x, k;
        cin >> a >> b >> mod >> x >> k;
        // the first state recorded is k = 1. The 0th k state is not recorded, as i
        if(k <= 150)
        {
            ll curval = x;
            for(int i = 0; i < k; ++i)
                curval = abs(a * curval + b) % mod;
            cout << curval << endl;
            continue;
        }
        vector<int> path;
        ll curval = abs(a * x + b) % mod;
        --k;
        while(find(path.begin(), path.end(), curval) == path.end())
        {
            path.push_back(curval);
            curval = abs(a * curval + b) % mod;
        }
        int start;
        for(int i = 0; i < path.size(); ++i)
            if(curval == path[i])
            {
                start = i;
                break;
            }
        k -= start;
        vector<int> vals;
        for(int i = start; i < path.size(); ++i)
            vals.push_back(path[i]);
        cout << vals[(k % vals.size() + vals.size()) % vals.size()] << endl;
    }
    return 0;
}