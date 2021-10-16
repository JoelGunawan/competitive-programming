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
    int n, m;
    cin >> n >> m;
    set<pair<int, bool>> a;
    for(int i = 0; i < n; ++i)
    {
        int x; char y;
        cin >> x >> y;
        if(y == 'U')
            a.ins({x, 1});
        else
            a.ins({x, 0});
    }
    if(a.size() > 2)
    {
        cout << "NO" << endl;
        return;
    }
    // if they intersect it is possible
    if(a.size() == 1 || (((*a.begin()).first % 2) == ((*++a.begin()).first % 2)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}