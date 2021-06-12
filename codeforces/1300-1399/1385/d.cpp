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

I dp(STR s, char a)
{
    if(s.size() == 1)
    {
        if(s[0] == a) return 0;
        else return 1;
    }
    I resb = 0, resc = 0, n = s.size();
    STR b = s.substr(0, n / 2);
    forp(i, n / 2, n) if(s[i] != a) ++resb;
    resb += dp(b, (char)(a + 1));
    STR c = s.substr(n / 2, n / 2);
    foro(i, n / 2) if(s[i] != a) ++resc;
    resc += dp(c, (char)(a + 1));
    return min(resb, resc);
}

void solve()
{
    I n;
    cin >> n;
    STR s;
    cin >> s;
    cout << dp(s, 'a') << nextline;
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
