#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int lim)
{
    bool a[lim + 1]; memset(a, 1, sizeof(a));
    a[0] = 0, a[1] = 0;
    for(int i = 2; i <= lim / 2; ++i)
    {
        if(a[i])
            for(int j = i * 2; j <= lim; j += i)
                a[j] = 0;
    }
    vector<int> res;
    for(int i = 0; i <= lim; ++i)
        if(a[i])
            res.push_back(i);
    cout << endl;
    return res;
}
int main()
{
    int t;
    cin >> t;
    vector<int> primes = sieve(1e6);
    while(t--)
    {
        int q;
        cin >> q;
        cout << primes[q - 1] << endl;
    }
    return 0;
}