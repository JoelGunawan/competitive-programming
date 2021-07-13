#include <bits/stdc++.h>
#define endl "\n"
#define rll register int_fast64_t
#define rint register int_fast32_t
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    rll num = 600851475143, res = 0;
    for(rll i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
        {
            while(num % i == 0)
                num /= i;
            res = i;
        }
    }
    if(num > 1)
        res = num;
    cout << res << endl;
    return 0;
}