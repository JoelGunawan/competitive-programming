#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
map<ll, bool> memo;
vector<ll> power_of_five = {1}, prefix = {0, 1};
void test_case()
{
    ll n;
    cin >> n;
    while(power_of_five.back() < n)
        power_of_five.pb(power_of_five.back() * 5), prefix.pb(prefix.back() + power_of_five.back());
    bool ans = 0;
    while(true)
    {
        if(binary_search(power_of_five.begin(), power_of_five.end(), n))
        {
            ans = 1;
            break;
        }
        else
        {
            auto it_1 = --lower_bound(power_of_five.begin(), power_of_five.end(), n);
            auto it_2 = lower_bound(power_of_five.begin(), power_of_five.end(), n);
            ll closest_lower = *it_1; 
            ll closest_higher = *it_2;
            if(n - closest_lower > prefix[it_1 - power_of_five.begin()])
            {
                if(closest_higher - n > prefix[it_2 - power_of_five.begin()])
                    break;
                else
                    n = closest_higher - n;
            }
            else
                n -= closest_lower;
        }
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}