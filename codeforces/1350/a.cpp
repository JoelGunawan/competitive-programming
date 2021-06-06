#include <iostream>

#define ll long long int

using namespace std;

int findOddDivisor(int n)
{
    for(int i = 3; i <= n; i += 2)
    {
        if(n % i == 0) return i;
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    if(n % 2 == 0)
    {
        cout << n + k * 2 << endl;
    }
    else cout << n + (k - 1) * 2 + findOddDivisor(n) << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
