#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if(m <= n / k)
    {
        cout << m << endl;
    }
    else
    {
        cout << n / k - ceil((m - n / k) / (double)(k - 1)) << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
