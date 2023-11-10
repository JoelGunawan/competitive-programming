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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> p[i];
        // cannot move -> lose state
        // if can move to lose
        vector<int> v;
        bool win[n + 1];
        memset(win, 1, sizeof(win));
        int mn = 1e9, mn2 = 1e9;
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            // gabisa pergi ke losing state
            if(mn2 > p[i] && p[i] > mn)
                win[i] = 0, ++cnt;
            mn = min(mn, p[i]);
            if(!win[i])
                mn2 = min(mn2, p[i]);
        }
        cout << cnt << endl;
    }
    return 0;
}