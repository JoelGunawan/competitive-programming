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
    int n;
    cin >> n;
    vector<int> a;
    while(n) {
        a.pb(n % 10);
        n /= 10;
    }
    sort(a.begin(), a.end(), greater<int>());
    int res = 0;
    for(int i = 0; i < 1 << a.size(); ++i) {
        int fi = 0, se = 0;
        for(int j = 0; j < a.size(); ++j) {
            if((1 << j) & i)
                fi = 10 * fi + a[j];
            else
                se = 10 * se + a[j];
        }
        res = max(res, fi * se);
    }
    cout << res << endl;
    return 0;
}