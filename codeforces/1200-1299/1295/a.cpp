#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if(n % 2 == 1)
    {
        n -= 3;
        cout << 7;
    }
    for(int i = 0; i < n / 2; ++i)
    {
        cout << 1;
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
