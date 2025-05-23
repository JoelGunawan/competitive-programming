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
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    int arr_min = 1e9;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        arr_min = min(arr_min, a[i]);
    }
    map<int, int> total_gcd;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= sqrt(a[i]); ++j)
            if(a[i] % j == 0) {
                total_gcd[j] = gcd(total_gcd[j], a[i]);
                total_gcd[a[i] / j] = gcd(total_gcd[a[i] / j], a[i]);
            }
    }
    int ans = 0;
    for(auto i : total_gcd) {
        if(i.fi == i.se && i.fi != 0 && i.fi <= arr_min)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}