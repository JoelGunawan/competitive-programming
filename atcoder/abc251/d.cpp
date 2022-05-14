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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int w;
    cin >> w;
    // divide by something supaya akhirnya 3
    // divide by 100 every time
    vector<int> res;
    int tmp = 1;
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j < 100; ++j) {
            res.pb(j * tmp);
        }
        tmp *= 100;
    }
    cout << res.size() << endl;
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}