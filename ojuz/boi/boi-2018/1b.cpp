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
    int n, k, r;
    cin >> n >> k >> r;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt[k];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < r; ++i) {
        int b, q;
        cin >> b >> q;
        cnt[b] = q;
    }
    int right = 0, nonzero = r;
    int ans = 1e9;
    for(int i = 0; i < n; ++i) {
        while(right < n && nonzero) {
            --cnt[a[right]];
            if(cnt[a[right]] == 0)
                --nonzero;
            ++right;
        }
        if(nonzero)
            break;
        ans = min(ans, right - i);
        if(cnt[a[i]] == 0) {
            ++nonzero;
        }
        ++cnt[a[i]];
    }
    if(ans == 1e9)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}