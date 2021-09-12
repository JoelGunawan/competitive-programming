#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    vector<char> mapping(26, '?');
    bool bingung = 0;
    for(int i = 0; i < n; ++i)
    {
        // go through b and find the mapping
        if(mapping[b[i] - 'A'] == '?')
            mapping[b[i] - 'A'] = a[i];
        else if(mapping[b[i] - 'A'] != a[i])
            bingung = 1;
    }
    for(int i = 0; i < 26; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            if(i != j && mapping[i] == mapping[j] && mapping[i] != '?')
                bingung = 1;
        }
    }
    if(bingung)
        cout << "Pak Dengklek bingung" << endl;
    else
    {
        for(int i = 0; i < n; ++i)
            cout << mapping[c[i] - 'A'];
        cout << endl;
    }
    return 0;
}