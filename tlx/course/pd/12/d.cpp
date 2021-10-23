#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s, t = s;
    reverse(t.begin(), t.end());
    if(s == t)
        cout << "YA" << endl;
    else
        cout << "BUKAN" << endl;
    return 0;
}