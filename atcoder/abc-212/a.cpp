#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(b == 0)
        cout << "Gold" << endl;
    else if(a == 0)
        cout << "Silver" << endl;
    else
        cout << "Alloy" << endl;
    return 0;
}