#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // O(NK) sol
    ll n, k;
    cin >> n >> k;
    if(k <= 4)
    {
        // do k <= 4
        // find all prime numbers <= k
        // brute force them
        vector<lll> two, three;
        for(lll i = 0; (lll)1 << i <= n; ++i)
            two.pb((lll)1 << i);
        if(k == 2)
            cout << two.size() << endl;
        else
        {
            int res = 0;
            lll x = 1;
            while(x <= n)
                three.pb(x), x *= 3;
            // brute force 2 and 3
            for(int i = 1; i < two.size(); ++i)
                for(int j = 1; j < three.size(); ++j)
                    if(two[i] * three[j] <= n)
                        ++res;
            cout << res + two.size() + three.size() - 1 << endl;
        }
    }
    else if(n * k <= 1e10)
    {
        vector<int> primes;
        for(int i = 2; i <= k; ++i)
        {
            bool prime = 1;
            for(int j = 2; j <= sqrt(i); ++j)
                if(i % j == 0)
                    prime = 0;
            if(prime)
                primes.pb(i); 
        }
        int res = 0;
        for(int i = 1; i <= n; ++i)
        {
            int tmp = i;
            for(int j = 0; j < primes.size() && primes[j] <= i; ++j)
            {
                while(tmp % primes[j] == 0)
                    tmp /= primes[j];
            }
            if(tmp == 1)
                ++res;
        }
        cout << res << endl;
    }
    else
    {

    }
    return 0;
}