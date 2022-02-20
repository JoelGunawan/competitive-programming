#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    // determine query
    int l = 1, r = n;
    while(l != r)
    {
        cout << "? " << (l + r) / 2 << endl;
        int a;
        cin >> a;
        cout << "? " << (l + r) / 2 + 1 << endl;
        int b;
        cin >> b;
        if(a < b)
            r = (l + r) / 2;
        else
            l = (l + r) / 2 + 1;
    }
    cout << "! " << l << endl;
    return 0;
}