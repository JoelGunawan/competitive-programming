#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b)
            swap(a, b);
        if(a / 2 < b || c > 2 * (a - b))
            cout << -1 << endl;
        else if(c <= a - b)
            cout << c + a - b << endl;
        else
            cout << c - (a - b) << endl;
    }
}