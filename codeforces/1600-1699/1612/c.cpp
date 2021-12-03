#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
ll natural_sum(ll n)
{
    return n * (n + 1) / 2;
}
ll calc(ll cur_num, ll k)
{
    if(cur_num <= k)
        return natural_sum(cur_num);
    else
    {
        cur_num -= k;
        return natural_sum(k) + natural_sum(k - 1) - natural_sum(k - cur_num - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll k, x;
        cin >> k >> x;
        ll left = 1, right = 2 * k - 1;
        ll res = 1; 
        x = min(x, natural_sum(k) + natural_sum(k - 1));
        while(left <= right)
        {
            ll mid = (left + right) / 2;
            //cout << mid << " "<< calc(mid, k) << " " << x << endl;
            if(calc(mid, k) < x)
                res = mid + 1, left = mid + 1;
            else
                right = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}