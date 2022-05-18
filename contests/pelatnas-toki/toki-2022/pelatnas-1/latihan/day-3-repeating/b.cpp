#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
ll rarr[(int)1e7], rarr_size = 1;
ll res;
vector<int> l, r;
ll n, k;
void recurse(ll cur, int idx)
{
    for(lll j = l[idx]; j * cur <= n; j *= l[idx])
    {
        res += upper_bound(rarr, rarr + rarr_size, n / (j * cur)) - rarr;
        for(int i = idx + 1; i < l.size(); ++i)
            recurse(j * cur, i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // O(NK) sol
    cin >> n >> k;
    vector<int> primes;
    for(int i = 2; i <= k; ++i)
    {
        bool prime = 1;
        for(int j = 2; j <= sqrt(i); ++j)
        {
            if(i % j == 0)
                prime = 0;
        }
        if(prime)
            primes.pb(i);
    }
    // l is always larger
    for(int i = 0; i < primes.size(); ++i)
    {
        if(i & 1)
            r.pb(primes[i]);
        else
            l.pb(primes[i]);
    }
    // generate all l subsets and all r subsets
    int prev = 1;
    rarr[0] = 1;
    for(int i = 0; i < r.size(); ++i)
    {
        for(lll j = r[i]; j <= n; j *= r[i])
        {
            for(int k = 0; k < prev; ++k)
                if(j * rarr[k] <= n)
                    rarr[rarr_size++] = j * rarr[k];
        }
        prev = rarr_size;
    }
    sort(rarr, rarr + rarr_size);
    for(int i = 0; i < l.size(); ++i)
        recurse(1, i);
    cout << res + rarr_size << endl;
    return 0;
}