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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    pair<int, int> order[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i], order[i] = mp(a[i], i);
    sort(order, order + n);
    reverse(order, order + n);
    bool dp[n];
    memset(dp, 1, sizeof(dp));
    // mulai dari nomor paling tinggi
    // kalo nomor paling tinggi selalu ga bisa
    for(auto p : order) {
        dp[p.se] = 0;
        for(int j = p.se + p.fi; j < n; j += p.fi)
            dp[p.se] |= !dp[j];
        for(int j = p.se - p.fi; j >= 0; j -= p.fi)
            dp[p.se] |= !dp[j];
    }
    for(int i = 0; i < n; ++i)
        if(dp[i])
            cout << "A";
        else
            cout << "B";
    cout << endl;
    return 0;
}