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
    STR a, b;
    cin >> n >> a >> b;
    vi ops;
    foro(i, n)
    {
        if(a[i] != b[i])
        {
            if(i == 0) ops.pb(1);
            else
            {
                ops.pb(i + 1);
                ops.pb(1);
                ops.pb(i + 1);
            }
        }
    }
    cout << ops.size() << " ";
    foro(i, ops.size()) cout << ops[i] << " ";
    cout << nextline;
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
