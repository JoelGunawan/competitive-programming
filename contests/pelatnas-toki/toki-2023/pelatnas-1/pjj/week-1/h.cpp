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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    map<int, ll> bottom[n + 1][n + 1], top[n + 1][n + 1];
    bottom[1][1][a[1][1]] = 1;
    top[n][n][a[n][n]] = 1;
    //cout << "bottom" << endl;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j + i - 1 <= n; ++j) {
            //cout << i << " " << j << endl;
            if(i == 1 && j == 1)
                continue;
            if(i != 1) {
                for(auto k : bottom[i - 1][j])
                    bottom[i][j][a[i][j] ^ k.fi] += k.se;
            }
            if(j != 1) {
                for(auto k : bottom[i][j - 1])
                    bottom[i][j][a[i][j] ^ k.fi] += k.se;
            }
        }
    }
    //cout << "top" << endl;
    for(int i = n; i >= 1; --i) {
        for(int j = n; j + i - 1 > n; --j) {
            //cout << i << " " << j << endl;
            if(i == n && j == n)
                continue;
            if(i != n) {
                for(auto k : top[i + 1][j])
                    top[i][j][a[i][j] ^ k.fi] += k.se;
            }
            if(j != n) {
                for(auto k : top[i][j + 1])
                    top[i][j][a[i][j] ^ k.fi] += k.se;
            }
        }
    }
    ll res = 0;
    //cout << "calc" << endl;
    for(int i = 1; i <= n; ++i) {
        int x = i, y = n - i + 1;
        //cout << x << " " << y << endl;
        for(auto j : bottom[x][y]) {
            if(y != n) {
                res += j.se * top[x][y + 1][j.fi];
            }
            if(x != n) {
                res += j.se * top[x + 1][y][j.fi];
            }
        }
        //cout << res << endl;
    }
    cout << res << endl;
    return 0;
}