#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

vector<int> sieve(int a)
{
    vector<bool> b(a + 1, 1);
    for(int i = 2; i <= a / 2; ++i)
        if(b[i])
        {
            for(int j = 2 * i; j <= a; j += i)
                b[j] = 0;
        }
    vector<int> res;
    for(int i = 2; i <= a; ++i)
        if(b[i])
            res.push_back(i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    // generate all primes from 1 to 10^5
    vector<int> primes = sieve(1e5);
    while(t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        if(k == 1)
        {
            if(a != b && (a % b == 0 || b % a == 0))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            // find amount of times it can be divided
            int res = 0;
            for(int i = 0; primes[i] <= sqrt(a); ++i)
            {
                if(a % primes[i] == 0)
                    while(a % primes[i] == 0)
                    {
                        a /= primes[i];
                        ++res;
                    }
            }
            if(a != 1)
                ++res;
            for(int i = 0; primes[i] <= sqrt(b); ++i)
            {
                if(b % primes[i] == 0)
                    while(b % primes[i] == 0)
                    {
                        b /= primes[i];
                        ++res;
                    }
            }
            if(b != 1)
                ++res;
            if(res >= k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}