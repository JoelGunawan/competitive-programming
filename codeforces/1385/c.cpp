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
    I n;
    cin >> n;
    vi a(n);
    foro(i, n) cin >> a[i];
    bool hasdown = 0;
    int last = -1;
    forn(i, n - 2, -1)
    {
        if(a[i] < a[i + 1]) hasdown = 1;
        else if(hasdown && a[i] > a[i + 1])
        {
            last = i;
            break;
        }
    }
    cout << last + 1 << nextline;
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
