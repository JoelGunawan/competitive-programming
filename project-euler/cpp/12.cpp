#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll idx = 1; bool ans = 0;
    while(!ans)
    {
        ll cur = idx * (idx + 1) / 2;
        // find the amount of divisors of cur
        ++idx;
        int factor = 1;
        for(int i = 2; i <= sqrt(cur); ++i)
        {
            if(cur % i == 0)
            {
                int counter = 0;
                while(cur % i == 0)
                    cur /= i, ++counter;
                factor *= (counter + 1);
            }
        }
        if(cur > 1)
            factor *= 2;
        if(factor > 500)
            ans = 1;
    }
    cout << idx * (idx - 1) / 2 << endl;
    return 0;
}