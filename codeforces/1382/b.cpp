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
    LL sum = 0;
    bool allisone = 1;
    foro(i, n)
    {
        cin >> a[i];
        if(a[i] != 1) allisone = 0;
    }
    if(allisone)
    {
        if(n % 2 == 1) cout << "First";
        else cout << "Second";
        cout << nextline;
    }
    else
    {
        I res = 0;
        while(a[res] == 1) ++res;
        if(res % 2 == 1) cout << "Second" << nextline;
        else cout << "First" << nextline;
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
