#include <bits/stdc++.h>
#define ll long long
#define rint register int
#define rll register long long
#define pb push_back
#define insert ins
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORN(i, a, b) for(int i = a; i > b; --i)
#define vector v
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int index, n; string s;
    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        if(s[i] == '1')
        {
            index = i;
            break;
        }
    if(index & 1)
        cout << "Aoki" << endl;
    else
        cout << "Takahashi" << endl;
    return 0;
}