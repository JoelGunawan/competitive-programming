#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cnt[2 * (int)1e5 + 1][21], m_cnt[2 * (int)1e5 + 1];
    // use greedy, while we can add a number and maintain increasing, we add a number. Otherwise, we don't add a number
    for(int i = 0; i < n; ++i)
    {
        int m, k;
        cin >> m >> k;
        for(int j = 1; j <= 20; ++j)
            ++cnt[m][j];
    }
    
    return 0;
}