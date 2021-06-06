#include <bits/stdc++.h>

using namespace std;

bool f(int n)
{
    // check whether n can be represented as 2 * p where p is a prime number that is not two
    if(n & 1 || n % 4 == 0 || n <= 2) return false;
    //cout << "F:" << n << endl;
    n /= 2;
    for(int i = 3; i <= sqrt(n); ++i)
        if(n % i == 0) return false;
    return true;
}

bool hasOddDivisor(int n)
{
    if(n & 1) return 1;
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n % i == 0)
        {
            if((n / i) & 1 || i & 1)
            {
                //cout << "HOD:" << i << " " << n / i << endl;
                return true;
            }

        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    if(n == 1 || (!hasOddDivisor(n) && n > 2) || f(n))
        cout << "FastestFinger";
    else
        cout << "Ashishgup";
    cout << "\n";

}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
