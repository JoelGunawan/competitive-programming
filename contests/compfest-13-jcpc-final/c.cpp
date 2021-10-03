#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define lll __int128
#define pb push_back
#define ins insert
#define ull unsigned long long
#define ullll unsigned __int128
#define pointer(it) *it
#define lb lower_bound
#define ub upper_bound
#define deb cout << i << " " << j << endl
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    ll n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n <= 100 && m <= 100)
    {
        int b[n * m];
        for(int i = 0; i < n * m; ++i)
            b[i] = a[i % n];
        int pref[n * m];
        pref[0] = b[0] % k;
        for(int i = 1; i < n * m; ++i)
            pref[i] = (pref[i - 1] + b[i]) % k;
        // check every subsegment
        // use prefix modulo
        int res = 0; bool done = 0;
        for(int i = 0; i < n * m; ++i)
        {
            for(int j = 0; j < n * m; ++j)
            {
                if((i == j + 1 || (i == 0 && j == n * m - 1)) && done)
                    continue;
                if(i == j)
                {
                    if(b[i] % k == 0)
                        ++res;
                }
                else if(i == j + 1 || (i == 0 && j == n * m - 1))
                {
                    done = 1;
                    if(pref[n * m - 1] == 0)
                        ++res;
                }
                else if(i < j)
                {
                    if(i == 0 && pref[j] == 0)
                        ++res;
                    else if(i != 0 && ((pref[j] - pref[i - 1]) + k) % k == 0)
                        ++res;                   
                }
                else if(i > j)
                {
                    if(((pref[n * m - 1] - pref[i - 1] + pref[j]) + k) % k == 0)
                        ++res;
                } 
            }
        }
        cout << res << endl;
    }
    // nyampah k = 1
    else if(k == 1)
        cout << ((((n * m) % mod * ((n * m) % mod - 1)) + 1) + mod) % mod << endl;
    else
    {
        // n, m <= 1000
        int counter[k];
        memset(counter, 0, sizeof(counter));
        int cur = 0;
    }
    return 0;
}