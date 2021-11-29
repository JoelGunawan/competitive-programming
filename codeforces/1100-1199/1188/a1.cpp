#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        ++cnt[u], ++cnt[v];
    }
    bool ans = 1;
    for(int i = 0; i <= n; ++i)
    {
        if(cnt[i] == 2)
            ans = 0;
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}