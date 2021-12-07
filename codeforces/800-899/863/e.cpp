#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    bool redundant[n + 1];
    pair<int, pair<bool, int>> sweep[2 * n];
    memset(redundant, 1, sizeof(redundant));
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        sweep[2 * i] = {l, {0, i + 1}};
        sweep[2 * i + 1] = {r, {1, i + 1}};
    }
    set<int> active_tv;
    sort(sweep, sweep + 2 * n);
    int idx = 0;
    while(idx < 2 * n)
    {
        int cur = sweep[idx].fi;
        while(sweep[idx].fi == cur && !sweep[idx].se.fi)
            active_tv.insert(sweep[idx++].se.se);
        if(active_tv.size() == 1)
            redundant[*active_tv.begin()] = 0;
        while(sweep[idx].fi == cur && sweep[idx].se.fi)
            active_tv.erase(sweep[idx++].se.se);
        if(idx < 2 * n && sweep[idx].fi > cur + 1 && active_tv.size() == 1)
            redundant[*active_tv.begin()] = 0;
    }
    int res = -1;
    for(int i = 1; i <= n; ++i)
    {
        if(redundant[i])
        {
            res = i;
            break;
        }
    }
    cout << res << endl;
    return 0;
}