#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x[n];
    for(int i = 0; i < n; ++i)
        cin >> x[i];
    sort(x, x + n);
    // we will have 2 * n segments, each segment is the left and right of a christmas tree
    // how many people max can we place to the left and to the right
    // maintain a sorted vector based on segment size that also stores left/right and start
    pair<int, pair<bool, int>> a[2 * n];
    for(int i = 0; i < n; ++i)
    {
        if(i == 0)
            a[2 * i] = {1e9, {0, x[i]}};
        else
            a[2 * i] = {(x[i] - x[i - 1] - 1) / 2 + (x[i] - x[i - 1] - 1) % 2, {0, x[i]}};
        if(i == n - 1)
            a[2 * i + 1] = {1e9, {1, x[i]}};
        else
            a[2 * i + 1] = {(x[i + 1] - x[i] - 1) / 2 , {1, x[i]}};
    }
    sort(a, a + 2 * n);
    int ans[m], first_index = 0;
    while(a[first_index].fi == 0)
        ++first_index;
    ll res = 0;
    int length = 1, cur_index = first_index;
    for(int i = 0; i < m; ++i)
    {
        // right
        if(a[cur_index].se.fi)
            ans[i] = a[cur_index].se.se + length;
        // left
        else
            ans[i] = a[cur_index].se.se - length;
        --a[cur_index].fi;
        res += length;
        while(a[first_index].fi == 0)
            ++first_index;
        ++cur_index;
        if(cur_index == 2 * n)
            ++length, cur_index = first_index;
    }
    cout << res << endl;
    for(int i = 0; i < m; ++i)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}