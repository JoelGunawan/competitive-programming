#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    fast_io();
    int n, num, res = INT_MAX, min_dist = INT_MAX, input;
    cin >> n >> num;
    for(int i = 0; i < n; ++i)
    {
        cin >> input;
        if(abs(num - input) < min_dist || (abs(num - input) == min_dist && input < res))
            min_dist = abs(num - input), res = input;
    }
    cout << res << endl;
    return 0;
}