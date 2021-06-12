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
const I num = 10;

void solve()
{
    STR s;
    cin >> s;
    I result = 2, alt = 1, same = 1, start = 0;
    V<vi> a(num, vi(num, 0));
    foro(i, s.size())
    {
        I x = s[i] - '0';
        foro(j, num) a[x][j] = a[j][x] + 1;
    }
    I maximum = 0;
    foro(i, num)
    {
        foro(j, num)
        {
            if(i != j) maximum = max(a[i][j] - (a[i][j] % 2), maximum);
            else maximum = max(a[i][j], maximum);
        }
    }
    cout << s.size() - maximum << nextline;
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
