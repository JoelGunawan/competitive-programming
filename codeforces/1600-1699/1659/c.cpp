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
void tc() {
    ll n, a, b;
    cin >> n >> a >> b;
    int x[n + 1];
    x[0] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> x[i];
    // pilihan:
    // traverse cost a * dist hemat b * dist * (n - i)
    ll res = 0, add = 0;
    for(int i = 1; i <= n; ++i) {
        res += b * (x[i] - x[i - 1] + add);
        if(a * (x[i] - x[i - 1]) <= b * (x[i] - x[i - 1]) * (n - i))
            add = 0, res += a * (x[i] - x[i - 1]);
        else
            add += (x[i] - x[i - 1]);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}