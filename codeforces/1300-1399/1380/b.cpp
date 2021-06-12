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
    STR t;
    cin >> t;
    I r = 0, s = 0, p = 0, n = t.size();
    forn(i, n - 1, -1)
    {
        if(t[i] == 'P') ++s;
        else if(t[i] == 'R') ++p;
        else ++r;
    }
    STR res;
    if(r >= s && r >= p) res = "R";
    else if(s >= p) res = "S";
    else res = "P";
    foro(i, n - 1) res += res[0];
    cout << res << nextline;
}

I main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    I t;
    cin >> t;
    cout << fixed << setprecision(15);
    while(t--) solve();
    return 0;
}
