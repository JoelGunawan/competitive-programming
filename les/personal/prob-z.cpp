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
const int lim = 3005;
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y];
            head[y] = x;
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout << fixed << setprecision(3);
    int n;
    disjoint_set dsu;
    while(cin >> n) {
        if(n == -1)
            return 0;
        for(int i = 0; i < n; ++i) {
            dsu.size[i] = 1;
            dsu.head[i] = -1;
        }
        long double x[n], y[n], r[n];
        for(int i = 0; i < n; ++i) 
            cin >> x[i] >> y[i] >> r[i];
        long double cost[n][n];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cost[i][j] = 0;
        const long double pi = 3.14159265358979323846;
        vector<pair<long double, pair<int, int>>> adj;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                long double sudut = 0;
                if(dist != 0)
                    sudut = 2 * acos(abs(r[i] - r[j]) / dist);
                //cout << sudut << endl;
                // sudut(radian) * jari"
                //cout << sudut << endl;
                cost[i][j] = cost[j][i] = sudut * min(r[i], r[j]) + (2 * pi - sudut) * max(r[i], r[j])
                + 2.0 * sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) - pow(r[i] - r[j], 2));
                //cout << i << " " << j << " " << cost[i][j] << endl;
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                adj.pb(mp(cost[i][j], mp(i, j)));
            }
        }
        sort(adj.begin(), adj.end());
        long double res = 0;
        for(auto i : adj) {
            if(dsu.merge(i.se.fi, i.se.se)) {
                //cout << i.se.fi << " " << i.se.se << endl;
                res += i.fi;
            }
        }
        cout << res << endl;
    }
    return 0;
}