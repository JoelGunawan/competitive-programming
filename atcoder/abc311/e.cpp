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
int pref[3005][3005], h, w;
int query(int x1, int y1, int sz) {
    if(x1 + sz - 1 > h || y1 + sz - 1 > w)
        return 1;
    return pref[x1 + sz - 1][y1 + sz - 1] - pref[x1 + sz - 1][y1 - 1] - pref[x1 - 1][y1 + sz - 1] + pref[x1 - 1][y1 - 1];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> h >> w >> n;
    for(int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        pref[a][b] = 1;
    }
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j];
        }
    }
    ll res = 0;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            int l = 1, r = 3000, ans = 0;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(query(i, j, mid))
                    r = mid - 1;
                else
                    ans = mid, l = mid + 1;
            }
            res += ans;
        }
    }
    cout << res << endl;
    return 0;
}