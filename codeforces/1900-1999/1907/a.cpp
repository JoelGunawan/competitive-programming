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
    string a[8][8];
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            a[i][j] = "";
            a[i][j] += (char)('a' + i);
            a[i][j] += (char)('1' + j);
        }
    }
    while(t--) {
        string s;
        cin >> s;
        int x = s[0] - 'a', y = s[1] - '1';
        vector<string> res;
        for(int i = 0; i < 8; ++i) {
            if(i != x)
                res.pb(a[i][y]);
            if(i != y)
                res.pb(a[x][i]);
        }
        for(auto i : res)
            cout << i << endl;
    }
    return 0;
}