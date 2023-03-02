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
    int n, q;
    cin >> n >> q;
    int r[n + 1], c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> r[i], r[i] %= 2;
    for(int i = 1; i <= n; ++i)
        cin >> c[i], c[i] %= 2;
    vector<int> hor_zero, col_zero, hor_one, col_one;
    for(int i = 1; i <= n; ++i) {
        if(r[i])
            hor_one.pb(i);
        else
            hor_zero.pb(i);
        if(c[i])
            col_one.pb(i);
        else
            col_zero.pb(i);
    }
    hor_one.pb(n + 1), hor_zero.pb(n + 1), col_zero.pb(n + 1), col_one.pb(n + 1);
    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(r[x1] != r[x2] || c[y1] != c[y2]) {
            cout << "NO" << endl;
            continue;
        }
        if(x1 > x2)
            swap(x1, x2);
        if(y1 > y2)
            swap(y1, y2);
        if(r[x1]) {
            if((*lower_bound(hor_zero.begin(), hor_zero.end(), x1) <= x2) || (*lower_bound(col_zero.begin(), col_zero.end(), y1) <= y2))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else {
            if((*lower_bound(hor_one.begin(), hor_one.end(), x1) <= x2) || (*lower_bound(col_one.begin(), col_one.end(), y1) <= y2))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}