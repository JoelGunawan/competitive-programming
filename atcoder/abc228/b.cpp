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
    int n, x;
    cin >> n >> x;
    int a[n];
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = 0;
    while(!vis[x - 1])
    {
        ++cnt;
        vis[x - 1] = 1;
        x = a[x - 1];
    }
    cout << cnt << endl;
    // do dfs
    return 0;
}