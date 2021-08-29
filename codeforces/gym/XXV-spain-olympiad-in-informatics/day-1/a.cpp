#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> generatePrimes(int limit)
{
    bool arr[limit + 1];
    memset(arr, 1, sizeof(bool) * (limit + 1));
    arr[0] = 0, arr[1] = 0;
    for(int i = 2; i <= limit; ++i)
        if(arr[i])
            for(int j = 2 * i; j <= limit; j += i)
                arr[j] = 0;
    vector<int> res;
    for(int i = 0; i <= limit; ++i)
        if(arr[i])
            res.push_back(i);
    return res;
}
int main()
{
    vector<int> primes = generatePrimes(100000);
    // this is partial solve, 30 points
    /*
    vector<ll> fact(101, 1);
    for(int i = 1; i <= 100; ++i)
        fact[i] = (fact[i - 1] * i) % primes[primes.size() - 1];
    for(int i = 1; i <= 100; ++i)
    {
        cout << '?' << " " <<  primes[primes.size() - 1] - fact[i] << " " << primes[primes.size() - 1] << endl;
        string ans;
        cin >> ans;
        if(ans == "SI")
            cout << '!' << " " << i << endl;
    }
    */
    
    return 0;
}