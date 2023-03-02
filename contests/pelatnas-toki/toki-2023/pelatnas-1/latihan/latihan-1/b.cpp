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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // n / 2 atau n - 3
    ll n;
    cin >> n;
    if(n % 3 == 0)
        cout << "-" << endl, exit(0);
    string res = "";
    while(n > 1) {
        if(n & 1 || n == 4)
            n -= 3, res += '+';
        else
            n /= 2, res += 'x';
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}