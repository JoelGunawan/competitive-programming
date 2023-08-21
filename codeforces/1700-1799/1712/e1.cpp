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
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // if any of i, j is outside of the factors of k, it is a valid triplet
    int t;
    cin >> t;
    while(t--) {
        // get factors of k, salah satu dr i atau j harus di luar faktor, sisanya bebas
        // invalid -> both merupakan faktor k
        int l, r;
        cin >> l >> r;
        ll res = 0;
        vector<int> factors[r + 1];
        for(int i = 1; i <= r; ++i) {
            for(int j = 2 * i; j <= r; j += i)
                factors[j].pb(i);
        }
        for(int i = l + 2; i <= r; ++i) {
            int cnt = 0;
            for(auto j : factors[i]) {
                //cout << "DEB " << i << " " << j << endl;
                // mis 6
                // 4 3 6
                // lcm -> 12
                // sum -> 13
                // 36
                // 18 24 36
                // x/2 2x/3 x
                // 2x/3 2x/5 x
                if(j >= l)  
                    ++cnt;
            }
            int can = i - l;
            //cout << can << " " << cnt << endl;
            // lcm ga nambah
            ll lama = res;
            // can -> bisa dihitung O(1)
            // cnt -> harus dihitung O(N)?, try precompute
            // edge case -> bisa dihitung O(1)
            res += 1ll * can * (can - 1) / 2 - 1ll * cnt * (cnt - 1) / 2;
            // lcm nambah
            if(i % 6 == 0 && i / 3 * 2 >= l && i / 2 >= l)
                --res;
            if(i % 15 == 0 && 2 * i / 3 >= l && 2 * i / 5 >= l)
                --res;
            /*
            ll brute = 0;
            for(int j = l; j < i; ++j) {
                for(int k = j + 1; k < i; ++k) {
                    if(lcm(lcm(i, j), k) >= i + j + k) {
                        ++brute;
                    }
                    else if(i % 15 == 0)
                        cout << i << " " << j << " " << k << endl;
                }
            }
            //cout << lama + brute << " " << res << endl;
            if(lama + brute != res) {
                cout << i << endl;
            } 
            */
        }
        cout << res << endl;
    }
    return 0;
}