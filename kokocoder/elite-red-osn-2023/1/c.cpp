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
    int prime_order[50];
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        // go by first prime number
        pair<int, int> x[n + 1];
        for(int i = 1; i <= n; ++i) {
            for(int j = 2; j <= a[i]; ++j) {
                if(a[i] % j == 0) {
                    x[i] = mp(j, i);
                    break;
                }
            }
        }
        sort(x + 1, x + n + 1);
        int cur_color = 0, ans[n + 1];
        for(int i = 1; i <= n; ++i) {
            if(x[i].fi != x[i - 1].fi)
                ++cur_color;
            ans[x[i].se] = cur_color;
        }
        cout << cur_color << endl;
        for(int i = 1; i <= n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}