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
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        pair<int, int> a[m];
        int row[n + 1], col[n + 1];
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(int i = 0; i < m; ++i)
            cin >> a[i].fi >> a[i].se, ++row[a[i].fi], ++col[a[i].se];
        bool can = 1;
        int two_cnt = 0;
        for(int i = 1; i <= n; ++i)
            if(row[i] > 2 || col [i] > 2)
                can = 0;
            else {
                if(row[i] == 2)
                    ++two_cnt;
                if(col[i] == 2)
                    ++two_cnt;   
            }
        if(two_cnt > 1 || !can) {
            cout << "NO" << endl;
            continue;
        }
        // check case for all same, if move crash
        if(m == n && two_cnt == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}