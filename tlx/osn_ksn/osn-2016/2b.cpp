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
    string buang;
    cin >> buang;
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // pakai two pointers dari depan dan dari belakang
    int pre[n + 1], post[n + 1];
    int r = 0, x[n + 1];
    memset(x, 0, sizeof(x));
    for(int i = 1; i <= n; ++i) {
        while(r < n && !x[a[r + 1]])
            ++r, ++x[a[r]], pre[r] = r - i + 1;
        --x[a[i]];
    }
    reverse(a + 1, a + n + 1);
    memset(x, 0, sizeof(x));
    r = 0;
    for(int i = 1; i <= n; ++i) {
        while(r < n && !x[a[r + 1]])
            ++r, ++x[a[r]], post[r] = r - i + 1;
        --x[a[i]];
    }
    reverse(post + 1, post + n + 1);
    int res = 0, l, r;
    for(int i = 2; i <= n; ++i) {
        if(2 * min(pre[i - 1], post[i]) >= res) {

        }
    }
    return 0;
}