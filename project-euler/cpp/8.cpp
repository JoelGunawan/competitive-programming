#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ifstream fin("8.txt");
    string s = "", input;
    while(fin >> input)
        s += input;
    ll res = 0;
    cout << s.size() << endl;
    for(int i = 0; i < s.size() - 12; ++i)
    {
        ll local = 1;
        for(int j = i; j < i + 13; ++j)
            local *= (s[j] - '0');
        res = max(local, res);
    }
    cout << res << endl;    
    return 0;
}