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
    int n, x;
    cin >> n >> x;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // pake xor prefix
    int prefix[n + 1]; prefix[0] = 0;
    for(int i = 1; i <= n; ++i)
        prefix[i] = prefix[i - 1] ^ a[i];
    for(int i = 1; i <= n - x; ++i)
        cout << prefix[i + x] << " " << prefix[i - 1] << " "<< (prefix[i + x] ^ prefix[i - 1]) << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}