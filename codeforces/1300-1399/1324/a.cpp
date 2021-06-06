#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int oddCount = 0, evenCount = 0;
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if(a % 2 == 1) oddCount++;
        else evenCount++;

    }
    if(oddCount > 0 && evenCount > 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
