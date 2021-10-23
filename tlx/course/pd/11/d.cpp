#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    a.erase(a.find(b), b.size());
    a.insert(a.find(c) + c.size(), d);
    cout << a << endl;
    return 0;
}