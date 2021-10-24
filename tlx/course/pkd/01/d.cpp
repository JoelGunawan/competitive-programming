#include <bits/stdc++.h>
using namespace std;
string yes = "Tentu saja bisa!", no = "Wah, tidak bisa :(";
int main()
{
    string s, t;
    cin >> s >> t;
    int idx = 0;
    if(s.size() - t.size() != 1)
    {
        cout << no << endl;
        return 0;
    }
    bool ans = 1, moved = 0;
    for(int i = 0; i < t.size(); ++i, ++idx)
    {
        if(s[idx] != t[i] && !moved)
            moved = 1, ++idx;
        if(s[idx] != t[i])
        {
            ans = 0;
            break;
        }
    }
    if(ans)
        cout << yes << endl;
    else
        cout << no << endl;
    return 0;
}