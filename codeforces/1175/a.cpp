#include <iostream>

using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    long long result = 0;
    while(n != 0)
    {
        result += n % k;
        if(n >= k) ++ result;
        n /= k;
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
