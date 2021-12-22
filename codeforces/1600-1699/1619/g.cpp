// THIS TEMPLATE IS NOT OFTEN USED AS PREPARATION FOR THE NOI/IOI
// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
struct disjoint_set {
    int head[200005], size[200005], value[200005];
    void build(vector<int> arr) {
        for(int i = 0; i < arr.size(); ++i)
            head[i] = -1, size[i] = 1, value[i] = arr[i];
    }
    int find_head(int node) {
        while(head[node] != -1)
            node = head[node];
        return node;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        //cout << a << " " << b << " " << x << " " << y << endl;
        if(x != y) {
            if(size[x] > size[y])
                head[y] = x, size[x] += y, value[x] = min(value[x], value[y]);
            else
                head[x] = y, size[y] += size[x], value[y] = min(value[x], value[y]);
        }
        return x != y;
    }
};
disjoint_set dsu;
void tc() {
    int n, k;
    cin >> n >> k;
    // do a horizontal sweep line and a vertical sweep line
    // use dsu UwU
    pair<pair<int, int>, pair<int, int>> x[n], y[n];
    vector<int> dsu_build(n);
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        x[i] = mp(mp(a, b), mp(c, i));
        y[i] = mp(mp(b, a), mp(c, i));
        dsu_build[i] = c;
    }
    dsu.build(dsu_build);
    int idx = 0;
    // by x sweep
    sort(x, x + n);
    sort(y, y + n);
    while(idx < n) {
        int cur = x[idx].fi.fi;
        vector<pair<pair<int, int>, pair<int, int>>> tmp;
        while(idx < n && x[idx].fi.fi == cur)
            tmp.pb(x[idx++]);
        for(int i = 1; i < tmp.size(); ++i) {
            if(abs(tmp[i].fi.se - tmp[i - 1].fi.se) <= k)
                dsu.merge(tmp[i].se.se, tmp[i - 1].se.se);
        }
    }
    idx = 0;
    while(idx < n) {
        int cur = y[idx].fi.fi;
        vector<pair<pair<int, int>, pair<int, int>>> tmp;
        while(idx < n && y[idx].fi.fi == cur)
            tmp.pb(y[idx++]);
        for(int i = 1; i < tmp.size(); ++i) {
            if(abs(tmp[i].fi.se - tmp[i - 1].fi.se) <= k)
                dsu.merge(tmp[i].se.se, tmp[i - 1].se.se);
        }
    }
    bool vis[n]; memset(vis, 0, sizeof(vis));
    vector<int> num;
    for(int i = 0; i < n; ++i) {
        if(!vis[dsu.find_head(i)]) {
            vis[dsu.find_head(i)] = 1;
            num.pb(dsu.value[dsu.find_head(i)]);
        }
    }
    num.pb(-1);
    sort(num.begin(), num.end());
    int res = INT_MAX;
    for(int i = 0; i < num.size(); ++i) {
        //cout << num[i] << " " << (int)num.size() - i - 2 << endl;
        //cout << num[i] << " ";
        res = min(res, max(num[i], (int)num.size() - i - 2));
    }
    //cout << endl;
    cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) 
        tc();
    return 0;
}