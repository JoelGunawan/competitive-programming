#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;
        if(a < b)
            swap(a, b);
        if(a == b)
            cout << 0 << " " << 0 << endl;
        else if(a % (a - b) == 0 && b % (a - b) == 0)
            cout << a - b << " " << 0 << endl;
        else
            cout << a - b << " " << min((a - b) - (a % (a - b)), a % (a - b)) << endl;
    }   
    return 0;
}