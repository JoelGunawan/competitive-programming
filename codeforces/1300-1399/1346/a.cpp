#include <iostream>

#define ll long long

using namespace std;

// cannot do problem, is kotlin, this is the solution I made in C++
// don't know if it is correct

ll pow(int a, int b)
{
    if(b == 0) return 1;
    else if(b == 1) return a;
    else if(b % 2 == 0)
    {
        ll tmp = pow(a, b / 2);
        return tmp * tmp;
    }
    else return pow(a, b - 1) * a;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int start = 0;
    while(true)
    {
        ll divisor = 0;
        for(int i = start; i < start + 4; ++i)
        {
            divisor += pow(k, i);
        }
        if(divisor > n)
        {
            break;
        }
        if(n % divisor == 0)
        {
            for(int i = 0; i < 4; ++i)
            {
                if(i == 3)
                {
                    cout << (n / divisor) * pow(k, start + i) << endl;
                }
                else
                {
                    cout << (n / divisor) * pow(k, start + i) << " ";
                }
            }
            return;
        }
        ++start;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
