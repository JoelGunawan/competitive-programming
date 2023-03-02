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
    int l, r;
    cin >> l >> r;
    // max possible sz tinggal dr l ke r, dikali 2 terus
    // if size is more than 2, then only mul by 2
    // if size is less than that, than can mul by 3
    // binser last possible location of l where it still satisfies
    // actually, there can be mul by 2 streak, then last is either 2 or 3
    int mul2 = 0, tmp = l, a = 1;
    while(2 * tmp <= r)
        ++mul2, tmp *= 2, a *= 2;
    // coba binser
    int ans2 = l - 1, ans3 = l - 1, cl = l, cr = r;
    while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(1ll * a * mid <= r)
            ans2 = mid, cl = mid + 1;
        else
            cr = mid - 1;
    }
    cl = l, cr = r;
    a /= 2, a *= 3;
    while(cl <= cr) {
        int mid = (cl + cr) >> 1;
        if(1ll * a * mid <= r)
            ans3 = mid, cl = mid + 1;
        else
            cr = mid - 1;
    }
    //cout << a << " " << ans2 << " " << ans3 << endl;
    ll out = ans2 - l + 1 + 1ll * (ans3 - l + 1) * mul2;
    // ans3 itu bisa taruh perkalian 3 di mana aja, jadi kali sebanyak mul2
    cout << mul2 + 1 << " " << out << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}