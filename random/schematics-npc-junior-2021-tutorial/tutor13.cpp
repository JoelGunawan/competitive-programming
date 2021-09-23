#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < a; ++j)
            cout << '^';
        cout << endl;
        a += b;
    }
    return 0;
}