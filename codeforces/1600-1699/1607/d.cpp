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
    string color;
    cin >> color;
    vector<int> b, r;
    for(int i = 0; i < n; ++i)
        if(color[i] == 'R')
            r.pb(a[i]);
        else
            b.pb(a[i]);
    sort(r.rbegin(), r.rend());
    sort(b.begin(), b.end());
    // b decreasing, r increasing
    bool ans = 1;
    for(int i = 0; i < r.size(); ++i)
        if(r[i] > n - i)
            ans = 0;
    for(int i = 0; i < b.size(); ++i)    
        if(b[i] < i + 1)
            ans = 0;
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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