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
        int a[n + 1];
        int b[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i], b[i] = a[i];
        sort(b + 1, b + n + 1);
        vector<int> oddidx, evenidx, odd, even;
        for(int i = 1; i <= n; ++i) {
            if(a[i] & 1)
                oddidx.pb(i), odd.pb(a[i]);
            else
                evenidx.pb(i), even.pb(a[i]);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        for(int i = 0; i < odd.size(); ++i) {
            a[oddidx[i]] = odd[i];
        }
        for(int i = 0; i < even.size(); ++i)   
            a[evenidx[i]] = even[i];
        bool ans = 1;
        for(int i = 1; i <= n; ++i)
            if(a[i] != b[i])
                ans = 0;
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}