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
    int n, m;
    cin >> n >> m;
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        if(cnt[i] % 4 == 2 || cnt[i] % 4 == 3) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}