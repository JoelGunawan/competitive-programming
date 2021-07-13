#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#define pb push_back
#define insert ins
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORN(i, a, b) for(int i = a; i > b; --i)
#define v vector
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
bool palindrome(int a)
{
    string s = to_string(a), t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int res = 0;
    for(int i = 999; i > 100; --i)
    {
        for(int j = i - 1; j > 100; --j)
        {
            if(i * j <= res)
                continue;
            else if(palindrome(i * j))
                res = i * j;
        }
    }
    cout << res << endl;
    return 0;
}