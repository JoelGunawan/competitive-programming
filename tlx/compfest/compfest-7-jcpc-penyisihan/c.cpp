#include <bits/stdc++.h>
#define endl "\n"
#define ull unsigned long long
using namespace std;

ull f(ull a)
{
    if(a <= 0)
        return 0;
    ull res = 0;
    if(a % 4 == 1 || a % 4 == 2)
        ++res;
    for(int i = 63; i > 0; --i)
        if((((ull)1 << i) & a) && !(a & 1))
            res += ((ull)1 << i);
    return res;
}

ull g(ull a)
{
    ull res = 0;
    for(int i = 1; i <= a; ++i)
        res ^= i;
    return res;
}

void print(ull a)
{
    if(a == 0)
        return;
    print(a / 2);
    if(a & 1)
        cout << 1;
    else
        cout << 0;
}

int main()
{
    ull a, b;
    cin >> a >> b;
    if((f(a - 1) ^ f(b)) == 0)
        cout << 0;
    else
        print(f(a - 1) ^ f(b));
    cout << endl;
}