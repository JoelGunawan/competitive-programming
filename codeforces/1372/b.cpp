#include <bits/stdc++.h>

#define ll long long
#define dbl double
#define ldbl long double
#define v vector
#define forp(i, a, b) for(int i = a; i < b; ++i)
#define forn(i, a, b) for(int i = a; i > b; --i)
#define forpo(i, a) for(int i = 0; i < a; ++i)
#define forno(i, a) for(int i = a; i > -1; --i)
#define inputarr(a, n) forpo(i, n) cin >> a[i];
#define vi vector<int>
#define vs vector<string>
#define str string
#define pb push_back
#define ull unsigned long long
#define nextline "\n"
#define TEST cout << "TEST" << endl;

using namespace std;

int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vi factors;
    int b = n;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
                factors.pb(i);
            }
        }
    }
    if(n > 1) factors.pb(n);
    int res = 1;
    forp(i, 1, factors.size()) res *= factors[i];
    cout << b - res << " " << res << nextline;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    cout << fixed << setprecision(15);
    while(t--) solve();
    return 0;
}
