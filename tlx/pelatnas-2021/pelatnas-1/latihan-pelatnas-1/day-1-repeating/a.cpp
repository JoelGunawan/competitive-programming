#include <bits/stdc++.h>
#define pb push_back
#define ins isnert
#define fi first
#define se second
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
ll pow(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = pow(a, b / 2);
        if(tmp >= 1e8)
            return 1e18;
        else
        {
            if(b & 1)
                if(tmp * a >= 1e8)
                    return 1e18;
                else
                    return tmp * tmp * a;
            else
                return tmp * tmp;
        }
    }
}
vector<int> sieve(int a)
{
    bool used[a + 1]; memset(used, 1, sizeof(used));
    used[1] = 0;
    for(int i = 2; i <= a / 2 + a % 2; ++i)
    {
        if(used[i])
            for(int j = 2 * i; j <= a; j += i)
                used[j] = 0;
    }
    vector<int> res;
    for(int i = 0; i <= a; ++i)
        if(used[i])
            res.pb(i);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l, r;
    cin >> l >> r;
    vector<int> primes = sieve(1e7);
    // bsta the primes
    // power starts at 3-1, 5-1, ...
    int power_index = 2;
    ll res = 0;
    while((1ll << power_index) <= r)
    {
        // search for left
        int left = 0, right = primes.size() - 1, left_index, right_index;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(pow(primes[mid], primes[power_index] - 1) < l)
                left = mid + 1, left_index = mid;
            else
                right = mid - 1;
        }
        // search for right
        left = 0, right = primes.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(pow(primes[mid], primes[power_index] - 1) <= r)
                left = mid + 1, right_index = mid;
            else
                right = mid - 1;
        }
        res += right_index - left_index;
        ++power_index;
    }
    cout << res << endl;
    return 0;
}