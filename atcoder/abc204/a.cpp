#include <bits/stdc++.h>

#define endl "\n"

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    if(x == y)
        cout << x;
    else if(x == 0 || y == 0)
    {
        if(y == 1 || x == 1)
            cout << 2;
        else
            cout << 1;
    }
    else
        cout << 0;
    cout << endl;
    return 0;
}