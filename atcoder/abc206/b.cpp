#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 1;
    while(res * (res - 1) < 2 * n)
        ++res;
    cout << res - 1<< endl;
    return 0;
}