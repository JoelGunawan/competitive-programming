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
    int n; str s;
    cin >> s;
    n = s.size();
    vi a(n, 0);
    if(s[0] == '+') a[0] = 1;
    else a[0] = -1;
    forp(i, 1, n)
    {
        if(s[i] == '+') a[i] = max(a[i - 1], 0) + 1;
        else a[i] = max(a[i - 1], 0) - 1;
    }
    ll res = 0;
    forpo(i, n) if(a[i] < 0) res += (i + 1);
    cout << res + n << nextline;
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
