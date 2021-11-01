#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> sieve(int limit)
{
    bool a[limit + 1]; memset(a, 1, sizeof(a));
    a[0] = 0, a[1] = 0;
    for(int i = 0; i <= limit; ++i)
        if(a[i])
            for(int j = 2 * i; j <= limit; j += i)
                a[j] = 0;
    vector<int> res;
    for(int i = 0; i <= limit; ++i)
        if(a[i])
            res.push_back(i);
    return res;
}
int main()
{
    vector<int> primes = sieve(2 * 1e6);
    ll res = 0;
    cout << primes.size() << endl;
    for(int i = 0; i < primes.size(); ++i)
        res += primes[i];
    cout << res << endl;
    return 0;
}