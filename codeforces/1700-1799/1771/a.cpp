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
        int n;
        cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        if(a[1] == a[n]) {
            cout << 1ll * n * (n - 1) << endl;
        }
        else {
            int low = 0, high = 0;
            for(int i = 1; i <= n; ++i) {
                if(a[1] == a[i])
                    ++low;
                if(a[n] == a[i])
                    ++high;
            }
            cout << 1ll * low * high * 2 << endl;
        }
    }
    return 0;
}