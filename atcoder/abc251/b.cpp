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
    int n, w;
    cin >> n >> w;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    bool b[w + 1];
    memset(b, 0, sizeof(b));
    for(int i = 0; i < n; ++i) {
        if(a[i] <= w)
            b[a[i]] = 1;
        for(int j = i + 1; j < n; ++j) {
            if(a[i] + a[j] <= w)
                b[a[i] + a[j]] = 1;
            for(int k = j + 1; k < n; ++k) {
                if(a[i] + a[j] + a[k] <= w)
                    b[a[i] + a[j] + a[k]] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= w; ++i)
        cnt += b[i];
    cout << cnt << endl;
    return 0;
}