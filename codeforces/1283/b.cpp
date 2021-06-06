#include <iostream>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << (n - (n % k)) + min(n % k, k / 2) << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
