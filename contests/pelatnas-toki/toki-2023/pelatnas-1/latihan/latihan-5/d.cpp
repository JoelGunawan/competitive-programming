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
char a[1005][1005];
int mod = 998244353;
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i <= n + 1; ++i)
        for(int j = 0; j <= n + 1; ++j)
            a[i][j] = '.';
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    // for every contigious segment, hitung
    // jika ada '#' di kiri dan '#' di kanan, maka selalu invalid
    ll ans = 1;
    for(int i = 1; i <= n; ++i) {
        int segstart = -1;
        for(int j = 1; j <= n; ++j) {
            if(a[i][j] == '?') {
                if(segstart == -1)
                    segstart = j;
            }
            else {
                if(segstart != -1) {
                    // calculate ke ans
                    if(a[i][j] == '#' && a[i][segstart - 1] == '#')
                        cout << 0 << endl, exit(0);
                    else if(a[i][j] == '#' || a[i][segstart - 1] == '#') {

                    }
                    else
                        ans = mul(ans, j - segstart + 1);
                    segstart = -1;
                }
            }
        }
        if(segstart != -1 && a[i][segstart - 1] == '.')
            ans = mul(ans, n + 2 - segstart);
    }
    for(int i = 1; i <= n; ++i) {
        int segstart = -1;
        for(int j = 1; j <= n; ++j) {
            if(a[j][i] == '?') {
                if(segstart == -1)
                    segstart = j;
            }
            else {
                if(segstart != -1) {
                    // calculate ke ans
                    if(a[j][i] == '#' && a[segstart - 1][i] == '#')
                        cout << 0 << endl, exit(0);
                    else if(a[j][i] == '#' || a[segstart - 1][i] == '#') {

                    }
                    else
                        ans = mul(ans, j - segstart + 1);
                    segstart = -1;
                }
            }
        }
        if(segstart != -1 && a[segstart - 1][i] == '.')
            ans = mul(ans, n + 2 - segstart);
    }
    cout << ans << endl;
    return 0;
}