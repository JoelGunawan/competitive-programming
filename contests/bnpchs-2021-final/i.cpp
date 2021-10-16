#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define pf push_front
#define pq priority_queue
#define ll long long
#define lll long long long
#define lb lower_bound
#define ub upper_bound
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
void test_case()
{
    ll n, m, d, s;
    cin >> n >> m >> d >> s;
    // n^2m or nm^2 is ok
    int a[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> a[i][j];
    int b[n][m]; memset(b, 0, sizeof(b));
    int counter = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(a[i][j] > 0)
                s -= a[i][j], b[i][j] = a[i][j];
            else
                b[i][j] = 0;
    // we have to take into account the difference in the test cases
    // as it can be very tricky
    // we need to pool a group of -1s and find the minimum and maximum amount we can make from them and use them according to what suits us
    // but we still have to create an algo to actually construct it
    
}
int main()
{
    fast_io();
    test_case();
    return 0;
}