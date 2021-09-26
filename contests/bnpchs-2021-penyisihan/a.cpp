#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ulll unsigned __int128
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int oddcount = 0, evencount = 0, res = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        // oddcount logic
        if((i % 2 == 1 && s[i] == 'x') || (i % 2 == 0 && s[i] == 'z'))
            ++oddcount;
        else
            res = max(res, oddcount), oddcount = 0;
        // evencount logic
        if((i % 2 == 1 && s[i] == 'z') || (i % 2 == 0 && s[i] == 'x'))
            ++evencount;
        else
            res = max(res, evencount), evencount = 0;
    }
    cout << max(res, max(oddcount, evencount)) << endl;
    return 0;
}