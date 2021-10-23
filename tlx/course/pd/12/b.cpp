#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int res = 1;
    for(int i = 1; i <= n; ++i)
    {
        if(i & 1)
            res *= i;
        else
            res *= i / 2;
    }
    cout << res << endl;
    return 0;
}