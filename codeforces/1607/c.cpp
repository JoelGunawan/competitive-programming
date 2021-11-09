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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll cur_reduce = 0;
    sort(a, a + n);
    ll highest_minimum = LLONG_MIN;
    for(int i = 0; i < n; ++i)
    {
        highest_minimum = max(highest_minimum, a[i] - cur_reduce);
        cur_reduce += (a[i] - cur_reduce);
    }
    cout << highest_minimum << endl;
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