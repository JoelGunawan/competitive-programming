// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int t;
    cin >> t;
    return t;
}
int main() {
    int n;
    cin >> n;
    vector<int> res;
    for(int i = 1; i <= n; ++i) {
        if(query(i, i))
            res.pb(i);
    }
    cout << "! " << res.size() << " ";
    for(auto i : res)   
        cout << i << " ";
    cout << endl;
    return 0;
}