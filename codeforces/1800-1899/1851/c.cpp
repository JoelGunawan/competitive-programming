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
    int n, k;
    cin >> n >> k;
    int c[n + 1];
    for(int i = 1; i <= n; ++i) 
        cin >> c[i];
    bool pre[n + 1];
    memset(pre, 0, sizeof(pre));
    // if 1 -> bentuk size k, terakhir bentuk size k
    if(c[1] == c[n]) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(c[i] == c[1])
                ++cnt;
        }
        if(cnt >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    else {
        int idx = -1, cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if(c[i] == c[1])
                ++cnt;
            if(cnt >= k) {
                idx = i + 1;
                break;
            }
        }
        if(idx == -1) {
            cout << "NO" << endl;
            return;
        }
        cnt = 0;
        for(int i = idx; i <= n; ++i) {
            if(c[i] == c[n])
                ++cnt;
        }
        if(cnt >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}