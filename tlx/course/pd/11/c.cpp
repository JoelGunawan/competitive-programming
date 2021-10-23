#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s; int a;
    cin >> s >> a;
    for(int i = 0; i < s.size(); ++i)
        cout << (char)((s[i] - 'a' + a) % 26 + 'a');
    cout << endl;
    return 0;
}