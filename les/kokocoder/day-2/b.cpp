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
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1 - 2; i <= x1 + 2; ++i) {
        for(int j = y1 - 2; j <= y1 + 2; ++j) {
            if((x1 - i) * (x1 - i) + (y1 - j) * (y1 - j) == 5 && (x2 - i) * (x2 - i) + (y2 - j) * (y2 - j) == 5) {
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }
    cout << "No" << endl;
    return 0;
}