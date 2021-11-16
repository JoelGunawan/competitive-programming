#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int sum = 0;
    for(int i = 1; i <= 200; ++i)
        if(i % 3 == 0 && i % 4 != 0)
            sum += i;
    cout << sum << endl;
    /*
    int n, m, k; string s;
    cin >> n >> m >> k >> s;
    ll dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    1 3 5 7 10
    x = 1000
    */
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; ++i)
    {
        if(binary_search(a, a + n,  x - a[i]))
        {
            cout << "YES" << endl;
            break;
        }
    }
    // hashmap
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        if(mp[x - a[i]] != 0)
        {
            cout << mp[x - a[i]] - 1 << " " << i << endl;
            return 0;
        }
        else
            mp[a[i]] = i + 1;
    }
    cout << -1 << endl;
    return 0;
}