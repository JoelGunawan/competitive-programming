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
        map<int, int> a;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            while(!(x & 1))
                x >>= 1;
            ++a[x];
        }
        bool ans = 1;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            while(!(x & 1))
                x >>= 1;
            while(x) {
                if(a[x]) {
                    --a[x];
                    break;
                }
                x /= 2;
            }
            if(!x)
                ans = 0;
        }
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        // dari a, yang penting prefixnya sama, 
        // so we actually only need to do prefix matching
        // pertama semua dijadikan bentuk ganjil
        // terus nanti di matching, b yang ga bisa dipasangkan akan dibagi terus

    }
    return 0;
}