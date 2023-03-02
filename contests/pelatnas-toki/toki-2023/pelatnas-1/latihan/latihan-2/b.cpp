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
int mod;
int sub(int a, int b) {
    return (((a - b) % mod) + mod) % mod;
}
int add(int a, int b) {
    return (a + b) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // bsta
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    mod = n;
    sort(a, a + m);
    int l = 0, r = n / 2, ans, sz = n / m;
    while(l <= r) {
        int mid = (l + r) >> 1;
        int le = a[0] - mid, re = a[0] + mid;
        bool pos = 1;
        //cout << mid << endl;
        for(int i = 1; i < m; ++i) {
            int curle = a[i] - mid, curre = a[i] + mid;
            // find intersection of segments
            le += sz, re += sz;
            //cout << le << " " << re << " " << curle << " " << curre << endl;
            re = min(re, curre);
            le = max(le, curle);
            if(le > re) {
                pos = 0;
                break;
            }
        }
        if(pos)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}