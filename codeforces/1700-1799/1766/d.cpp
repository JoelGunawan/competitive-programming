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
const int lim = 1e7 + 5;
vector<int> arr[lim];
bool prime[lim], flag[lim];
void sieve() {
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i < lim; ++i) {
        if(prime[i]) {
            if(flag[i])
                arr[i].pb(i);
            for(int j = 2 * i; j < lim; j += i) {
                if(flag[j]) {
                    arr[j].pb(i);
                }
                prime[j] = 0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se, flag[a[i].se - a[i].fi] = 1;
    // yang penting diff, kita cari diff terus nanti dapet modulo
    sieve();
    for(int i = 0; i < n; ++i) {
        if(arr[a[i].se - a[i].fi].size() == 0) {
            cout << -1 << endl;
            continue;
        }
        int ans = 1e9;
        for(auto j : arr[a[i].se - a[i].fi]) {
            ans = min(ans, ((-a[i].se % j) + j) % j);
        }
        cout << ans << endl;
    }
    return 0;
}