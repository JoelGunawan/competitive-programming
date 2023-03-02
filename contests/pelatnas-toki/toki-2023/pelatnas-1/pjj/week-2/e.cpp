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
map<vector<int>, int> x;
map<vector<int>, bool> vis;
string ar[150];
int m, n;
int f(int mask, vector<int> a) {
    if(a.size() <= 1)
        return 0;
    else if(vis[a])
        return x[a];
    vis[a] = 1;
    // coba tiap mask yang belum disentuh
    int res = 1e9;
    for(int i = m - 1; i >= 0; --i) {
        if(!((1 << i) & mask)) {
            vector<int> on, off;
            for(int j = 0; j < a.size(); ++j) {
                if(ar[a[j]][i] == '1')
                    on.pb(a[j]);
                else
                    off.pb(a[j]);
            }
            int ans = 1 + max(f(mask | (1 << i), on), f(mask | (1 << i), off));
            if(on == a || off == a)
                continue;
            /*
            cout << "PROC" << endl;
            for(auto i : on)
                cout << i << " ";
            cout << endl;
            for(auto i : off)
                cout << i << " ";
            cout << endl;
            cout << mask << " " << i << " " << ans << endl;
            */
            res = min(res, ans);
        }
    }
    /*
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    cout << mask << " " << res << endl;
    */
    x[a] = res;
    return x[a];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // Tiap Bitmask dihitung sekali saja
    // pake bfs from bitmask
    // only append higher than previous msb
    while(true) {
        cin >> m >> n;
        if(m == n && n == 0)
            break;
        // coba every bitmask
        // jika sudah ketemu yang max sizenya 1, maka break
        for(int i = 0; i < n; ++i)
            cin >> ar[i];
        vector<int> y;
        for(int i = 0; i < n; ++i)
            y.pb(i);
        cout << f(0, y) << endl;
        vis.clear(), x.clear();
    }
    return 0;
}