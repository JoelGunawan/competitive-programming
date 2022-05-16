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
int mod(ll n, int x) {
    return n % x;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n & 1 || n < 4) {
            cout << -1 << endl;
        }
        else {
            ll a = (n / 12 - 1) * 2, b = (n / 12 - 1) * 3;
            int mini[25], maxi[25];
            fill(mini, mini + 25, 1e9);
            fill(maxi, maxi + 25, 0);
            mini[0] = 0;
            for(int i = 0; i <= 24; ++i) {
                if(i >= 4) {
                    mini[i] = min(mini[i], mini[i - 4] + 1);
                    maxi[i] = max(maxi[i], maxi[i - 4] + 1);
                }
                if(i >= 6) {
                    mini[i] = min(mini[i], mini[i - 6] + 1);
                    maxi[i] = max(maxi[i], maxi[i - 6] + 1);
                }
            }
            //cout << a << " " << b << " " << mod(n, 12) + 12 << endl;
            if(n <= 24)
                cout << mini[n] << " " << maxi[n] << endl;
            else
                cout << a + mini[mod(n, 12) + 12] << " " << b + maxi[mod(n, 12) + 12] << endl;
        }
    }
    return 0;
}