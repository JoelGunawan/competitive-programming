#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int max_left = 0, min_right = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        max_left = max(max_left, l), min_right = min(min_right, r);
        if(max_left <= min_right)
            cout << 0 << endl;
        else
            cout << max(0, (max_left - min_right) / 2 + ((max_left + min_right) % 2)) << endl;
    }
    return 0;
}