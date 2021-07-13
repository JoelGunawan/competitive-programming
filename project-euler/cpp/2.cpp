#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int fib1 = 0, fib2 = 1, res = 0, limit = 4 * 1e6;
    while(fib2 <= limit)
    {
        fib2 = fib1 + fib2;
        fib1 = fib2 - fib1;
        if(!(fib2 & 1))
            res += fib2;
    }
    cout << res << endl;
    return 0;
}