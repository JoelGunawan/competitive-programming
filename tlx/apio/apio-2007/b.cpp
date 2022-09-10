#include <bits/stdc++.h>
#define fi first
#define se second
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int nxt[n + 1], prv[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i], nxt[i] = i + 1, prv[i] = i - 1;
    int dist[n + 5];
    priority_queue<pair<int, pair<int, int>>> x;
    for(int i = 2; i <= n; ++i) {
        dist[i] = a[i] - a[i - 1];
        x.push({-dist[i], {i - 1, i}});
    }
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    int res = 0;
    while(k && x.size()) {
        int cst = -x.top().fi, i = x.top().se.fi, j = x.top().se.se;
        x.pop();
        if(!used[i] && !used[j]) {
            used[i] = 1, used[j] = 1;
            --k;
            res += cst;
            int pr = prv[i], nx = nxt[j];
            nxt[pr] = nx, prv[nx] = pr;
            dist[nx] = dist[nx] + dist[i] - cst;
            if(pr >= 1 && nx <= n)
                x.push({-dist[nx], {pr, nx}});
        }
    }
    assert(k == 0);
    cout << res << endl;
    return 0;
}