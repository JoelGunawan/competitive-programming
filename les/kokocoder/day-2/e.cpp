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
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt[(int)1e6 + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
        ++cnt[a[i]];
    }
    int res = 0;
    for(int i = 0; i < n; ++i) {
        bool valid = 1;
        for(int j = 2; j <= sqrt(a[i]); ++j) {
            if(a[i] % j == 0 && (cnt[a[i] / j] || cnt[j])) {
                valid = 0;
            }
        }
        if(valid && cnt[a[i]] == 1 && (a[i] == 1 || cnt[1] == 0))
            ++res;
    }
    cout << res << endl;
    return 0;
}