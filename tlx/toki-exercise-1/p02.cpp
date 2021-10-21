#include <bits/stdc++.h>
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int a, b; char op;
    cin >> a >> op >> b;
    if(op == '+')
        cout << a + b << endl;
    else if(op == '-')
        cout << a - b << endl;
    else if(op == '*')
        cout << a * b << endl;
    else
    {
        bool benar;
        if(op == '=')
            benar = a == b;
        else if(op == '<')
            benar = a < b;
        else if(op == '>')
            benar = a > b;
        if(benar)
            cout << "benar" << endl;
        else
            cout << "salah" << endl;
    }
    return 0;
}