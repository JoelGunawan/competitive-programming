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
    ll n, k;
    cin >> n >> k;
    ll a[n + 1];
    ll sum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    if(sum < k) {
        cout << 0 << endl;
        return 0;
    }
    ll acc = 0;
    ll res = sum - k;
    for(int i = n; i >= 2; --i) {
        acc += a[i] - a[1];
        // perlu di reduce -> sum - acc - k
        res = min(res, max(0ll, (ll)ceil((sum - acc - k) / (double)(n - i + 2))) + n - i + 1);
    }
    cout << res << endl;
    return 0;
}