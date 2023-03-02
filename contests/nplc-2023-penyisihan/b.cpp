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
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // syarat odd: merupakan faktor
    // syarat even: / 2 nilainya jadi .5 decimalnya
    // berarti gcd(n, x) = x / 2
    // berarti even -> faktor dikali 2
    int n;
    cin >> n;
    // antara faktor atau 2 kali faktor?
    int ans = 0;
    for(int i = 1; i <= sqrt(n) + 100; ++i) {
        // only factor <= sqrt yg mgkn
        // coba jadi i bilangan -> n / i
        // midpoint n / i
        // padding + 1 dan - 1
        // jika i even -> harus .5 atau gcd(n, x) = x / 2
        int l = i, r = n;
        while(l <= r) {
            // assume mid is end
            int mid = (l + r) / 2;
            ll sum = 1ll * mid * (mid + 1) / 2 - 1ll * (mid - i) * (mid + 1 - i) / 2;
            //cout << i << " " << mid << " " << sum << endl;
            if(sum == n) {
                ++ans;
                break;
            }
            else if(sum < n)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}