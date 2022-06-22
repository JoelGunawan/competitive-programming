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
    ll n;
    cin >> n;
    // fi -> pos
    // se.fi -> type
    // se.se -> amount
    // L transition ->
    // R transition ->
    pair<int, pair<int, int>> a[2 * n];
    lll pre = 0, post = 0, pre_inc = 0, post_inc = 0;
    for(int i = 0; i < n; ++i) {
        int x, v, h;
        cin >> x >> v >> h;
        post += max(0, x - h) * 1ll * v;
        post_inc += v;
        a[2 * i] = mp(max(0, x - h), mp(0, v));
        a[2 * i + 1] = mp(x + h, mp(1, v));
    }
    int idx = 0;
    sort(a, a + 2 * n);
    lll res = 1e25;
    for(int i = 0; i < 2 * n; ++i) {
        lll cur_pos = a[i].fi, type = a[i].se.fi, amount = a[i].se.se;
        if(type) {
            // R variant, tambahkan ke pre
            // calculate 
            pre += (cur_pos - idx) * pre_inc;
            post -= (cur_pos - idx) * post_inc;
            res = min(res, pre + post);
            idx = cur_pos;
            pre_inc += amount;
        }
        else {
            // L variant, kurangi dari post
            // calculate
            pre += (cur_pos - idx) * pre_inc;
            post -= (cur_pos - idx) * post_inc;
            res = min(res, pre + post);
            idx = cur_pos;
            post_inc -= amount;
        }
        //cout << cur_pos << " " << pre << " " << post << endl;
    }
    string output = "";
    while(res > 0) {
        output += (char)((res % 10) + '0');
        res /= 10;
    }
    reverse(output.begin(), output.end());
    cout << output << endl;
    return 0;
}