#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll a, b;
    cin >> a >> b;
    if(a % 11 == 0)
        cout << a / 11 * b << endl;
    else
        cout << b / 11 * a << endl;
    return 0;
}