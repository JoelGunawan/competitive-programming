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
    ll res = 0;
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // maintain pos of 1 2 and 2 1
    vector<int> one, two;
    // that will add
    // have ability to disregard 0
    int pr_idx = -1;
    int nxt[n + 1];
    fill(nxt, nxt + n + 1, n);
    for(int i = n - 1; i >= 1; --i) {
        if(a[i] == 3)
            nxt[i] = i;
        else
            nxt[i] = nxt[i + 1];
    }
    for(int i = 1; i <= n; ++i) {
        if(pr_idx != -1 && a[i] == 2 && a[pr_idx] == 1)
            one.pb(i);
        if(pr_idx != -1 && a[i] == 1 && a[pr_idx] == 2)
            two.pb(i);
        if(a[i] != 0)
            pr_idx = i;
    }
    one.pb(n + 1), two.pb(n + 1);
    ll ans[n + 1];
    fill(ans, ans + n + 1, -1);
    // 2nd iteration: case 3 2 1 atau 3 1 2
    // harus dalam bentuk itu
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 0)
            res += 1ll * (n - i + 1) * i;
        else {
            // find first either one or two
            // all the rest will have additional
            int o = *upper_bound(one.begin(), one.end(), i), t = *upper_bound(two.begin(), two.end(), i);
            
            if(o < t) {
                // cari dalam bentuk 3 2 1
                t = *upper_bound(two.begin(), two.end(), nxt[o]);
            }
            else if(o > t) {
                // cari dalam bentuk 3 1 2
                o = *upper_bound(one.begin(), one.end(), nxt[t]);
            }
            ans[i] = n + 1 - i + n + 1 - o + n + 1 - t;
        }
    }
    for(int i = n - 1; i >= 1; --i) {
        if(ans[i] == -1)
            ans[i] = ans[i + 1];
    }
    for(int i = 1; i <= n; ++i) {
        if(ans[i] != -1)
            res += ans[i];
        //cout << ans[i] << " ";
    }
    //cout << endl;
    cout << res << endl;
    return 0;
}