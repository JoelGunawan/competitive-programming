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
bool compfunc(pair<string, int> a, pair<string, int> b) {
    if(a.fi == b.fi)
        return a.se < b.se;
    else {
        for(int i = 0; i < a.fi.size(); ++i) {
            if(a.fi[i] == b.fi[i])
                continue;
            if(i % 2 == 0)
                return a.fi[i] < b.fi[i];
            else
                return a.fi[i] > b.fi[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    pair<string, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi, a[i].se = i + 1;
    sort(a, a + n, compfunc);
    for(int i = 0; i < n; ++i) 
        cout << a[i].se << " ";
    cout << endl;
    return 0;
}