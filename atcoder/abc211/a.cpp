#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double a, b;
    cin >> a >> b;
    cout << (a - b) / 3 + b << endl;
    return 0;
}