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
    string s, t;
    cin >> s >> t;
    int res = 1e9;
    for(int i = 0; i <= s.size() - t.size(); ++i) {
        int beda = 0;
        for(int j = i; j < i + t.size(); ++j) {
            if(s[j] != t[j - i])
                ++beda;
        }
        res = min(res, beda);
    }
    cout << res << endl;
    return 0;
}