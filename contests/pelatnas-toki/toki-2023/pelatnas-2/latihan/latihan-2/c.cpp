// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e6 + 1e3 + 5;
int n, curk;
vector<pair<pair<int, int>, pair<int, int>>> queries;
int ans[100005];
struct disjoint_set {
    int h[lim], sz[lim];
    set<int> a[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y]) 
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
            if(a[y].size() > a[x].size())
                swap(a[x], a[y]);
            for(auto i : a[y]) {
                if(a[x].find(i) == a[x].end())
                    a[x].ins(i);
                else {
                    a[x].erase(i);
                    ans[i] = curk;
                }
            }
            a[y].clear();
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;   
    int pref[n + 1][n + 1];
    char a[n + 1][n + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (int)(a[i][j] == '#');
            //cout << pref[i][j] << " ";
        }
        //cout << endl;
    }
    vector<pair<int, pair<int, int>>> kval;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int l = 1, r = min({i, j, n - i + 1, n - j + 1}), ans = 0;
            while(l <= r) {
                int mb = (l + r) / 2;
                int tmp = 2 * mb - 1;
                int x = i + tmp / 2, y = j + tmp / 2;
                //cout << i << " " << j << " " << tmp << " " << pref[x][y] - pref[x - tmp][y] - pref[x][y - tmp] + pref[x - tmp][y - tmp] << endl;
                if(pref[x][y] - pref[x - tmp][y] - pref[x][y - tmp] + pref[x - tmp][y - tmp] == 0) {
                    l = mb + 1;
                    ans = tmp;
                }
                else {
                    r = mb - 1;
                }
            }
            kval.pb(mp(ans, mp(i - 1, j - 1)));
        }
    }
    sort(kval.begin(), kval.end());
    reverse(kval.begin(), kval.end());
    /*
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << kval[i][j] << " ";
        }
        cout << endl;
    }
    */
    int m;
    cin >> m;
    disjoint_set dsu;
    for(int i = 0; i < m; ++i) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1, --c1, --r2, --c2;
        queries.pb(mp(mp(r1, c1), mp(r2, c2)));
        dsu.a[r1 * n + c1].ins(i);
        dsu.a[r2 * n + c2].ins(i);
    }   
    bool done[n][n];
    memset(done, 0, sizeof(done));
    curk = n;
    for(auto i : kval) {
        int x = i.se.fi, y = i.se.se;
        done[x][y] = 1;
        curk = i.fi;
        // cek atas bawah kiri kanan
        if(x && done[x - 1][y])
            dsu.merge(x * n + y, (x - 1) * n + y);
        if(y && done[x][y - 1])
            dsu.merge(x * n + y, x * n + y - 1);
        if(x < n - 1 && done[x + 1][y])
            dsu.merge(x * n + y, (x + 1) * n + y);
        if(y < n - 1 && done[x][y + 1])
            dsu.merge(x * n + y, x * n + y + 1);
    }
    for(int i = 0; i < m; ++i)
        cout << ans[i] << endl;
    return 0;
}