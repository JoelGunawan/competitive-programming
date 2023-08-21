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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int que;
    cin >> que;
    pair<int, int> q[que];
    for(int i = 0; i < que; ++i)
        cin >> q[i].fi, q[i].se = i;
    sort(q, q + que);
    int allow[l + 1];
    memset(allow, -1, sizeof(allow));
    for(int i = 0; i < que; ++i) {
        if(allow[q[i].fi] == -1)
            allow[q[i].fi] = i;
    }
    for(int i = l - 1; i >= 0; --i) {
        if(allow[i] == -1)
            allow[i] = allow[i + 1];
    }
    // given compare substring shift by x
    // size l - 1
    int cnt[que][n + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
        // try for every length i
        // geser
        int idx1 = 1, idx2 = 1 + i, diff = 0;
        if(idx2 + l - 1 > n)
            break;
        for(int j = 0; j < l; ++j) {
            if(a[idx1 + j] != a[idx2 + j])
                ++diff;
        }
        // simpan batas di query i
        // find lowest yg bs ditambahkan
        ++cnt[allow[diff]][idx1];
        ++cnt[allow[diff]][idx2];
        //cout << idx1 << " " << idx2 << " " << diff << endl;
        for(;idx2 + l <= n;) {
            // coba geser
            if(a[idx1 + l] != a[idx2 + l])
                ++diff;
            if(a[idx1] != a[idx2])
                --diff;
            ++idx1, ++idx2;
            ++cnt[allow[diff]][idx1];
            ++cnt[allow[diff]][idx2];
            //cout << idx1 << " " << idx2 << " " << diff << endl;
        }
    }
    for(int i = 1; i < que; ++i) {
        for(int j = 1; j <= n; ++j)
            cnt[i][j] += cnt[i - 1][j];
    }
    int ans[que][n + 1];
    for(int i = 0; i < que; ++i) {
        for(int j = 1; j <= n; ++j) {
            ans[q[i].se][j] = cnt[i][j];
        }
    }
    for(int i = 0; i < que; ++i) {
        for(int j = 1; j <= n - l + 1; ++j)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}