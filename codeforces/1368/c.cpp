#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << n * 3 + 4 << "\n";
    for(int i = 0; i <= n + 1; ++i)
    {
        if(i != 0)
            cout << i - 1 << " " << i << "\n";
        cout << i << " " << i << "\n";
        if(i != n + 1)
            cout << i + 1 << " " << i << "\n";
    }
    return 0;
}
