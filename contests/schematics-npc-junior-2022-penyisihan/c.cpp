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
    // precompute
    // diag, row, column
    // no diag, row, column -> losing
    bool diag[2005], column[1005], row[1005];
    set<pair<int, int>> x;
    memset(diag, 0, sizeof(diag)), memset(column, 0, sizeof(column)), memset(row, 0, sizeof(row));
    for(int i = 0; i <= 1000; ++i) {
        for(int j = 0; j <= 1000; ++j) {
            if(i == 0 && j == 0)
                column[0] = 1, row[0] = 1, diag[1000] = 1;
            else {
                if(!column[i] && !row[j] && !diag[1000 + i - j]) {
                    column[i] = 1, row[j] = 1, diag[1000 + i - j] = 1;
                    x.ins(mp(i, j));
                }
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        // query
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        if((a == 0 && b == 0) || a > n || b > m)
            cout << "Draw" << endl;
        else if(x.find(mp(a, b)) == x.end())
            cout << "Pisi" << endl;
        else
            cout << "Eva" << endl;
    }
    return 0;
}