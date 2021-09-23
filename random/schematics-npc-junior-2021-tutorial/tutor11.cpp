#include <iostream>
typedef unsigned long long ull;
using namespace std;
ull pow(ull a, ull b)
{
    if(b == 0)
        return 1;
    else
    {
        ull tmp = pow(a, b / 2); tmp *= tmp;
        return b & 1 ? tmp * a : tmp;
    }
}
int main()
{
    ull n;
    cin >> n;
    if(n == 4294967296)
    {
        cout << "18446744073709551616" << endl;
        return 0;
    }
    ull res = 0;
    for(int i = 0; i <= 33; ++i)
        if(n & (1 << (ull)i))
            res += pow(4, i);
    cout << res << endl;
    return 0;
}