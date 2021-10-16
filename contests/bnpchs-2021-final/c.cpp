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
    int n, m; string a, b;
    cin >> n >> m >> a >> b;
    bool a_zero = 1, b_zero = 1;
    int first_a, last_a, first_b, last_b;
    for(int i = 0; i < n; ++i)
        if(a[i] == '1')
        {
            a_zero = 0;
            first_a = i;
            break;
        }
    for(int i = 0; i < m; ++i)
        if(b[i] == '1')
        {
            b_zero = 0;
            first_b = i;
            break;
        }
    int a_counter = 0;
    for(int i = 0; i < n; ++i)
        if(a[i] == '1')
            ++a_counter;
    int b_counter = 0;
    for(int i = 0; i < m; ++i)
        if(b[i] == '1')
            ++b_counter;
    for(int i = n - 1; i >= 0; --i)
        if(a[i] == '1')
        {
            last_a = i;
            break;
        }
    for(int i = m - 1; i >= 0; --i)
        if(b[i] == '1')
        {
            last_b = i;
            break;
        }
    if(a_zero && b_zero)
    {
        // then output 0
        cout << 0 << endl;
        return;
    }
    else if(a_zero || b_zero)
    {
        if(b_zero)
            cout << m + a_counter - 1 << endl;
        else
            cout << n + b_counter - 1 << endl;
    }
    else
    {
        cout << n + m - 1 - min(first_a, first_b) - min(n - 1 - last_a, m - 1 - last_b) << endl;
    }
}
int main()
{
    fast_io();
    test_case();
    return 0;
}