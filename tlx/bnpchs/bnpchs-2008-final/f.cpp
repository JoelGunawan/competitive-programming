#include <bits/stdc++.h>
using namespace std;
int mod;
int powmod(int a, int b)
{
    if(b == 0)
        return 1;
    else
    {
        int tmp = powmod(a, b / 2);
        return b & 1 ? (((tmp * tmp) % mod) * a) % mod : (tmp * tmp) % mod; 
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, res = 1;
        cin >> a >> b >> mod;
        for(int i = 1; i <= a; ++i)
            res = (res * powmod(i, b)) % mod;
        cout << res << endl;
    }
    return 0;
}