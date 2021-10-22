#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cur = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
            cout << cur++ % 10;
        cout << endl;
    }
    return 0;
}