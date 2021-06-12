#include <bits/stdc++.h>

#define LL long long
#define DBL double
#define LDBL long double
#define V vector
#define I int
#define forp(i, a, b) for(I i = a; i < b; ++i)
#define forn(i, a, b) for(I i = a; i > b; --i)
#define foro(i, a) for(I i = 0; i < a; ++i)
#define vi vector<int>
#define vs vector<string>
#define STR string
#define pb push_back
#define ULL unsigned long long
#define nextline "\n"
#define TEST cout << "TEST" << endl;

using namespace std;

I mod = 1e9 + 7;

void solve()
{
    I n, m;
    cin >> n >> m;
    vi a(n), b(m);
    foro(i, n) cin >> a[i];
    foro(i, m) cin >> b[i];
    sort(a.begin(), a.end());
    foro(i, m)
    {
        if(binary_search(a.begin(), a.end(), b[i]))
        {
            cout << "YES" << nextline;
            cout << 1 << " " << b[i] << nextline;
            return;
        }
    }
    cout << "NO" << nextline;
}

I main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    I t;
    cin >> t;
    while(t--) solve();
    return 0;
}
