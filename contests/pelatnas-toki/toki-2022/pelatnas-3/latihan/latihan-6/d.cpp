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
int s = sqrt(200000);
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int v[s + 1][s + 1];
    memset(v, 0, sizeof(v));
    int n, h;
    cin >> n >> h;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    int cnt[h + 1];
    memset(cnt, 0, sizeof(cnt));
    int idx = 0;
    sort(a, a + n);
    for(int i = 1; i <= h; ++i) {
        while(idx < n && a[idx].fi == i) {
            if(a[idx].se <= s) {
                ++v[a[idx].se][i % a[idx].se];
            }
            else {
                for(int j = i; j <= h; j += a[idx].se)
                    ++cnt[j];
            }
            ++idx;
        }
        int res = cnt[i];
        for(int j = 1; j <= s; ++j) {
            res += v[j][i % j];
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}