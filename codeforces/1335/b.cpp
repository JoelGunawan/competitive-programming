#include <iostream>

using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string result = "";
    for(int i = 0; i < n; ++i)
    {
        result += ('a' + i % b);
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
