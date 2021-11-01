#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define pb push_back
#define insert ins
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORN(i, a, b) for(int i = a; i > b; --i)
#define v vector
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
vector<int> sieve(int limit)
{
    bool a[limit + 1]; 
    memset(a, 1, sizeof(a));
    a[0] = 0, a[1] = 0;
    for(int i = 2; i <= limit; ++i)
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
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> primes = sieve(2 * 1e6);
    cout << primes.size() << endl;
    cout << primes[10000] << endl;
    return 0;
}