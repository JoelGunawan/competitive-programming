#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    vector<ll> counter(8, 0);
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 'c')
            ++counter[0];
        else if(s[i] == 'h')
            counter[1] = (counter[0] + counter[1]) % mod;
        else if(s[i] == 'o')
            counter[2] = (counter[1] + counter[2]) % mod;
        else if(s[i] == 'k')
            counter[3] = (counter[2] + counter[3]) % mod;
        else if(s[i] == 'u')
            counter[4] = (counter[3] + counter[4]) % mod;
        else if(s[i] == 'd')
            counter[5] = (counter[4] + counter[5]) % mod;
        else if(s[i] == 'a')
            counter[6] = (counter[5] + counter[6]) % mod;
        else if(s[i] == 'i')
            counter[7] = (counter[6] + counter[7]) % mod;
    }
    cout << counter[7] << endl;
    return 0;
}