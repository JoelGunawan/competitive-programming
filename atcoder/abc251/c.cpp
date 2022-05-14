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
    int n;
    cin >> n;
    map<string, bool> a;
    int res = -1, res_idx = -1;
    for(int i = 0; i < n; ++i) {
        string s; int t;
        cin >> s >> t;
        if(!a[s]) {
            a[s] = 1;
            if(t > res) {
                res_idx = i + 1, res = t;
            }
        }
    }
    cout << res_idx << endl;
    return 0;
}