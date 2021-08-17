#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3])
    {
        cout << "Weak"; return 0;
    }
    bool weak = 1;
    for(int i = 1; i < 4; ++i)
        if(s[i] - '0' != (s[i - 1] - '0' + 1) % 10)
            weak = 0;
    if(!weak)
        cout << "Strong";
    else
        cout << "Weak";
    cout << endl;
    return 0;
}