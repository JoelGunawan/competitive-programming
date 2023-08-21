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
int f(int a, int b) {
    if(a == 0) 
        return 0;
    else if(b == 0)
        return 1;
    else {
        int x = a / b;
        if(a < b) {
            // lakuin manual
            int c = abs(a - b);
            return f(b, c) + 1;
        }
        if(x & 1) {
            return f(b, a % b) + 3 * (x / 2) + 1;
        }
        else {
            return f(a % b, b) + 3 * (x / 2);
        }
        // a 5 b 4
        // [5] [4 1] [3 2 1 1 0] -> 8
        // a 9 b 4
        // [9 4 5] [1 4] [3 1 2 1 1 0] -> 11
        // a 13 b 4
        // [13 4 9 5] [4 1] [3 2 1 1 0] -> 11
        // a 17 b 4
        // [17 4 13 9 4 5] [1 4] [3 1 2 1 1 0] -> 14
        // a 21 b 4
        // [21 4 17 13 4 9 5] [4 1] [3 2 1 1 0] -> 14
        // a 6 b 4
        // [6] [4 2]
        // 10 4
        // [10 4 6] [2 4]
        // 3 5
        // 5 2
        // 2 3
        // 3 1
        // 1 2
        // 2 1
        // 1 1
        // 1 0
        // 0 1
        // 1 1

        // 5 3
        // 3 2
        // 2 1
        // 1 1 
        // 1 0
        // 0 1
        // 1 0 
        // 0 1

    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // masalah parity kapan jadi 0
    // kalo parity beda, maka gapernah jadi 0
    // kalo sama semua, maka bisa jadi all 0
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        for(int i = 1; i <= n; ++i)
            cin >> b[i];
        int par[3];
        par[0] = par[1] = par[2] = 0;
        // 5 3 2 1 1 0 1 0 1
        // 4 4 0 4 0 4 0 4 0
        // 1 7 6 1 5 4
        // 2 6 [4 2] 2 0
        // 3 5 2 3 1
        // 4 4 0 4 0
        // 5 3 2 1 1
        // 6 2 4 2 2 0
        // 7 1 6 5 1
        for(int i = 1; i <= n; ++i) {
            if(mp(a[i], b[i]) != mp(0, 0))
                ++par[f(a[i], b[i]) % 3];
        }
        int cnt = 0;
        for(int i = 0; i <= 2; ++i) {
            if(par[i])
                ++cnt;
        }
        if(cnt > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        // tentuin parity ke berapa -> divide by gcd
        // pakai semacam algo gcd, tentuin berapa kali dia di di modulo/divivde suatu angka
    }
    return 0;
}