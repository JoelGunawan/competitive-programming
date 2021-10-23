#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    while(s.find(t) != -1)
        s.erase(s.find(t), t.size());
    cout << s << endl;
}