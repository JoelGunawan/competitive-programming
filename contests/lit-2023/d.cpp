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
pair<int, int> op(pair<int, int> a, pair<int, int> b) {
    // pasti ada intersect
    // maxl dan minr
    return mp(max(a.fi, b.fi), min(a.se, b.se));
}
pair<int, int> conv(pair<int, int> a) {
    return mp(a.fi - 1, a.se + 1);
}
void tc() {
    int n;
    cin >> n;
    // coba dari bawah, dari kiri, dari atas, dari bawah?
    // try every diagonal path, terus nanti cari intersect of all
    pair<int, int> allow[n + 2][n + 2];
    for(int i = 0; i <= n + 1; ++i) {
        for(int j = 0; j <= n + 1; ++j) {
            allow[i][j] = mp(0, 1e9);
        }
    }
    int grid[n + 1][n + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
            if(grid[i][j])
                allow[i][j] = mp(grid[i][j], grid[i][j]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            // find intersect
            //if(mp(i, j) == mp(5, 1) || mp(i, j) == mp(4, 1)) {
            //    cout << "DEBUG " << allow[i - 1][j].fi << " " << allow[i - 1][j].se << " " << allow[i][j - 1].fi << " " << allow[i][j - 1].se << endl;
            //    cout << allow[i][j].fi << " " << allow[i][j].se << endl;
            //}
            allow[i][j] = op(allow[i][j], op(conv(allow[i - 1][j]), conv(allow[i][j - 1])));       
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = n; j >= 1; --j) {
            allow[i][j] = op(allow[i][j], op(conv(allow[i - 1][j]), conv(allow[i][j + 1])));
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= n; ++j) {
            allow[i][j] = op(allow[i][j], op(conv(allow[i][j - 1]), conv(allow[i + 1][j])));
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = n; j >= 1; --j) {
            allow[i][j] = op(allow[i][j], op(conv(allow[i][j + 1]), conv(allow[i + 1][j])));
        }
    }
    /*
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << i << " " << j << " " << allow[i][j].fi << " " << allow[i][j].se << endl;
        }
    }
    */
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << (allow[i][j].fi == allow[i][j].se ? allow[i][j].fi : 0) << " ";
        }
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
   return 0;
}