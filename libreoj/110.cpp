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
int powmod(int a, int b, int mod) {
    if(b == 0)  
        return 1;
    else {
        int tmp = powmod(a, b >> 1, mod);
        tmp = (1ll * tmp * tmp) % mod;
        return b & 1 ? (1ll * tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, p;
    cin >> n >> p;
    for(int i = 1; i <= n; ++i)
        cout << powmod(i, p - 2, p) << endl;
    return 0;
}