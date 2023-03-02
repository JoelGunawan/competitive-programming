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
void tc() {
    int n, q;
    cin >> n >> q;
    ll pref[1001][1001];
    memset(pref, 0, sizeof(pref));
    for(int i = 0; i < n; ++i) {
        int h, w;
        cin >> h >> w;
        pref[h][w] += h * w;
    }
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j <= 1000; ++j) {
            pref[i][j] = pref[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    for(int i = 0; i < q; ++i) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        cout << pref[h2 - 1][w2 - 1] - pref[h2 - 1][w1] - pref[h1][w2 - 1] + pref[h1][w1] << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}