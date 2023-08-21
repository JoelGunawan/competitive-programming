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
void tc() {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    int x, y;
    cin >> x >> y;
    bool ans = 1;
    for(int i = 1; i <= k; ++i) {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) & 1]++;
        if(a == x && b == y) {
            ans = 0;
        }
    }
    if(cnt[(x + y) & 1] >= 1)
        ans = 0;
    if(cnt[(x + y) & 1] == 1 && (n == 1 || m == 1))
        ans = 0;
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // same base
    // kalo n = 1 atau m = 1
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}