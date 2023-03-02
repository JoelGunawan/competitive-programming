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
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
long long modexp(long long a, long long b) {
    if(b == 0)
        return 1;
    else {
        long long tmp = modexp(a, b / 2);
        tmp = (tmp * tmp) % mod;
        if(b % 2 == 1) {
            return (tmp * a) % mod;
        }
        else
            return tmp;
    }
}
vector<int> edges[50005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // get dp transition of top * left
    // plus transition:
    /*
    +-
    -+
    
    --
    ++

    -+
    -+
    */
    /*
    save horizontal and vertical mask (4)
    */
    if(n == 1 || m == 1) {
        cout << powmod(2, max(n, m)) << endl;
        exit(0);
    }
    // dp transition
    // has to be certain symbol -> half all possibilities
    // 
    return 0;
}