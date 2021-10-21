#include <bits/stdc++.h>
using namespace std;
int get_val(int a)
{
    int res = 0;
    while(a > 0)
        res += a % 10, a /= 10;
    return res;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << get_val(a) * get_val(b) << endl;
    return 0;
}