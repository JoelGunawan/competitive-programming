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
// get all divisors of N and M
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // banyak faktor prima
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 2; i <= n; ++i) {
        while(n % i == 0)
            n /= i, ++cnt;
    }
    int cnt2 = 0;
    for(int i = 2; i <= m; ++i) {
        while(m % i == 0)
            m /= i, ++cnt2;
    }
    if(cnt > cnt2)
        cout << "Mimi" << endl;
    else
        cout << "Shasha" << endl;
    return 0;
}