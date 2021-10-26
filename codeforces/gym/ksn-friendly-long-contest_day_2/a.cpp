#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    /*
    if(n <= 1e3)
    {
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                string a = to_string(i) + to_string(j); ll b = stoll(a);
                if(b % i == 0 && b % j == 0)
                    ++res;
            }
        }
        cout << res << endl;
        return;
    }
    */
    vector<pair<ll, ll>> a;
    a.push_back({1, 0});
    ll tmp = 2; ll cnt = 1;
    while(tmp <= n && cnt / tmp <= n)
    {
        a.push_back({tmp, (ll)(cnt / tmp)});
        tmp *= 2, cnt *= 10;
    }
    tmp = 5, cnt = 1;
    while(tmp <= n && cnt / tmp <= n)
    {
        a.push_back({tmp, (ll)(cnt / tmp)});
        tmp *= 5, cnt *= 10;
    }
    ll res = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        tmp = 1;
        while(n / (tmp * a[i].first) - a[i].second > 0)
        {
            res += n / (tmp * a[i].first) - a[i].second;
            res %= mod;
            tmp *= 10;
        }
    }
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}