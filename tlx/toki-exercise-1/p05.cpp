#include <bits/stdc++.h>
using namespace std;
pair<int, int> d[1000];
bool vis[1000];
int n;
int dfs(int cur)
{
    //cout << cur << endl;
    if(vis[cur])
        return 0;
    else
    {
        vis[cur] = 1;
        return dfs(d[cur].second) + 1;
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> d[i].first, d[i].second = i;
    sort(d, d + n);
    //cout << "TEST" << endl;
    // use dfs
    int res = 0;
    for(int i = 0; i < n; ++i)
        res += max(0, dfs(i) - 1);
    cout << res << endl;
    return 0;
}