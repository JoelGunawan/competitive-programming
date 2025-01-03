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
#define nextline "\n"
#define TEST cout << "TEST" << endl;

using namespace std;

I mod = 1e9 + 7;

void solve()
{
    I n, maximum = 0;
    cin >> n;
    vi a(n);
    foro(i, n)
    {
        cin >> a[i];
        maximum = max(a[i], maximum);
    }
    STR base = "";
    foro(i, maximum + 1) base += 'a';
    cout << base << nextline;
    foro(i, n)
    {
        ++base[a[i]];
        if(base[a[i]] > 'z')
        {
            base[a[i]] = 'a';
        }
        cout << base << nextline;
    }
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
