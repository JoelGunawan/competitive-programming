#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
void solve()
{
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(n == 1)
    {
        if(a[0] <= c)
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return;
    }
    // divide a into 2 arrays
    // and store the sums that can be made from that subarray into a vector
    // find how many combinations we can make
    vector<ll> left, left_sum, right, right_sum;
    for(int i = 0; i < n / 2; ++i)
        left.pb(a[i]);
    for(int i = n / 2; i < n; ++i)
        right.pb(a[i]);
    // d is the sum array for b and e is the sum array for c
    // do left array
    ll sum = 0;
    for(int i = 1; i < (1 << left.size()); ++i)
    {
        sum = 0;
        for(int j = 0; j < left.size(); ++j)
            if(i & (1 << j))
                sum += left[j];
        if(sum <= c)
            left_sum.pb(sum);
    }
    for(int i = 1; i < (1 << right.size()); ++i)
    {
        sum = 0;
        for(int j = 0; j < right.size(); ++j)
            if(i & (1 << j))
                sum += right[j];
        if(sum <= c)
            right_sum.pb(sum);
    }
    sort(left_sum.begin(), left_sum.end()), sort(right_sum.begin(), right_sum.end());
    ll res = left_sum.size() + right_sum.size();
    for(int i = 0; i < left_sum.size(); ++i)
    {
        // use upper bound and minus with begin
        res += upper_bound(right_sum.begin(), right_sum.end(), c - left_sum[i]) - right_sum.begin();
    }
    cout << res << endl;
    
}
int main()
{
    fast_io();
    solve();
    return 0;
}