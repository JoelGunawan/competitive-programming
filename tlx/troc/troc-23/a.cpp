#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
void test_case()
{
    int n;
    cin >> n;
    int factor_count = 0;
    for(int i = 1; i <= n; ++i)
        if(n % i == 0)
            ++factor_count;
    if(factor_count == 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}