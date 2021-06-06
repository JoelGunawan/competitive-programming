#include <iostream>

#define ull unsigned long long

using namespace std;

void solve()
{
    ull n;
    cin >> n;
    ull result = (n / 2) * n * n;
    for(int i = 0; i < n / 2; ++i)
    {
        result -= ((ull)(2 * i + 1) * (2 * i + 1));
    }
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
