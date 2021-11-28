#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    // do a sweep line, where we maintain the multiset sorted by the furthest end point
    // if at any point amount of segments > k, remove the segment with the furthest point
    // save each segment with point, index, bool
    // and then sort
    pair<int, pair<bool, int>> sweep[2 * n];
    for(int i = 0; i < n; ++i)
    {
        sweep[2 * i] = {a[i].fi, {0, i}};
        sweep[2 * i + 1] = {a[i].se, {1, i}};
    }
    // right, index
    sort(sweep, sweep + 2 * n);
    multiset<pair<int, int>> segments;
    bool removed[n]; memset(removed, 0, sizeof(removed));
    int res = 0;
    for(int i = 0; i < 2 * n; ++i)
    {
        // left
        if(!sweep[i].se.fi)
        {
            segments.insert({a[sweep[i].se.se].se, sweep[i].se.se});
            //cout << segments.size() << endl;
            if(segments.size() > k)
            {
                // remove rbegin segment
                removed[(*segments.rbegin()).se] = 1;
                segments.erase(*segments.rbegin());
                ++res;
            }
        }
        // right
        else
        {
            if(!removed[sweep[i].se.se])
                segments.erase(segments.find({sweep[i].fi, sweep[i].se.se}));
        }
    }
    cout << res << endl;
    for(int i = 0; i < n; ++i)
        if(removed[i])
            cout << i + 1 << " ";
    if(res != 0)
        cout << endl;
    return 0;
}