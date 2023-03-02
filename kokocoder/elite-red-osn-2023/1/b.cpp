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
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
const int lim = 1e6 + 5;
vector<int> primes[lim];
bool b[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int arr_gcd = 0;
    for(int i = 1; i <= n; ++i)
        arr_gcd = gcd(a[i], arr_gcd);
    if(arr_gcd != 1) {
        cout << "not coprime" << endl, exit(0);
    }
    memset(b, 1, sizeof(b));
    b[0] = 0, b[1] = 0;
    for(int i = 2; i < lim; ++i) {
        primes[i].pb(i);
        if(b[i])
            for(int j = 2 * i; j < lim; j += i)
                b[j] = 0, primes[j].pb(i);
    }
    set<int> p;
    for(int i = 1; i <= n; ++i) {
        for(auto j : primes[a[i]]) {
            if(p.count(j))
                cout << "setwise coprime" << endl, exit(0);
            else
                p.ins(j);
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}