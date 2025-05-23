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
void tc() {
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 2; i <= n; ++i)
        cin >> a[i];
    int b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    // have a, b
    int mx_del = 0;
    sort(b + 1, b + n + 1);
    a[1] = 1;
    b[0] = 0;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        //cout << "DEBUG " << i << " " << upper_bound(b, b + n + 1, a[i]) - b << endl;
        mx_del = max(mx_del, (int)((upper_bound(b, b + n + 1, a[i]) - b) - i));
    }
    cout << mx_del << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}