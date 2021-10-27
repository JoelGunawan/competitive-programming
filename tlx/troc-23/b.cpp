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
    int n, counter = 0;;
    cin >> n;
    for(int i = 1; i <= min(n, 10000); ++i)
    {
        string a = to_string(i);
        int mul = 1, sum = 0;
        for(int i = 0; i < a.size(); ++i)
            mul *= (a[i] - '0'), sum += (a[i] - '0');
        if(mul + sum == i)
            ++counter;
    }
    cout << counter << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}