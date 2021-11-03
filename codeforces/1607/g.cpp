#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void test_case()
{
    // each dish has a range, l and r, we can select anything between l and r, find a way to select the l and r
    int n, m;
    cin >> n >> m;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    // semakin besar, semakin banyak fish
    int left[n], right[n];
    for(int i = 0; i < n; ++i)
    {
        right[i] = min(b[i], m) - max(m - b[i], 0);
        left[i] = -(min(a[i], m) - max(m - a[i], 0));
    }
    ll max_left = 0, max_right = 0;
    for(int i = 0; i < n; ++i)
        max_left += left[i], max_right += right[i];
    ll remaining_max_left = max_left, remaining_max_right = max_right, cur = 0;
    if(0 >= max_left && 0 <= max_right)
    {
        // do max left and then do max right
        cout << 0 << endl;
        int idx = 0;
        while(cur + remaining_max_left < 0)
        {
            if(remaining_max_left - left[idx] + cur - right[idx]);
        }
    }
    else if(0 > max_right)
    {
        // choose max right option
        cout << max_right << endl;
        // select the option that goes right
        for(int i = 0; i < n; ++i)
            cout << max(m - b[i], 0) << " " << min(b[i], m) << endl;
    }
    else
    {
        // choose max left option
        cout << max_left << endl;
        for(int i = 0; i < n; ++i)
            cout << min(a[i], m) << " " << max(m - a[i], 0) << endl;

    }
}

int main()
{
    fast_io();
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}