#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << std::fixed << std::setprecision(10);
    long double a, b, x, y;
    cin >> a >> b >> x >> y;
    cout << a + (x - a) / (b + y) * b << endl;
}