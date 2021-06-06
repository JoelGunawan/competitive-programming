#include <iostream>

using namespace std;

void solve()
{
    int s;
    cin >> s;
    int result = 0;
    while(s > 9)
    {
        int cashback = s / 10;
        result += s - s % 10;
        s = s % 10 + cashback;
    }
    result += s;
    cout << result << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
