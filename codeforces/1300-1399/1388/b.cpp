#include <iostream>
#include <cmath>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a = ceil(n / 4.0);
    for(int i = 0; i < n - a; ++i)
    {
        cout << "9";
    }
    for(int i = 0; i < a; ++i)
    {
        cout << "8";
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
