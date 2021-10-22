#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // first is the prime, second is the power
    vector<pair<int, int>> primes;
    for(int i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            int counter = 0;
            while(n % i == 0)
                n /= i, ++counter;
            primes.push_back({i, counter});
        }
    }
    if(n > 1)
        primes.push_back({n, 1});
    for(int i = 0; i < primes.size(); ++i)
    {
        cout << primes[i].first;
        if(primes[i].second > 1)
            cout << "^" << primes[i].second;
        if(i == primes.size() - 1)
            cout << endl;
        else
            cout << " x ";
    }
}