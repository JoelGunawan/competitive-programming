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
    string s;
    cin >> s;
    char prev = 'a';
    int counter = 0;
    for(int i = 0; i < s.size(); ++i)
        if(s[i] != prev)
            ++counter, prev = s[i];
    bool dp[counter + 1]; dp[0] = 0;
    for(int i = 1; i <= counter; ++i)
    {
        dp[i] = (!dp[i - 1]);
        if(i > 2)
            dp[i] |= (!dp[i - 2]);
    }
    if(dp[counter])
        cout << "Filco" << endl;
    else
        cout << "Riberto" << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}