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
void tc() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int color[n + 1];
    memset(color, 0, sizeof(color));
    for(int i = 0; i < n; ++i) {
        ++color[a[i]];
    }
    vector<int> b;
    for(int i = 1; i <= n; ++i) {
        if(color[i] > 0)
            b.push_back(color[i]);
    }
    sort(b.begin(), b.end(), greater<int>());
    bool used[n + 1];
    memset(used, 0, sizeof(used));
    int res = 0;
    for(auto i : b) {
        while(used[i] && i != 0) {
            --i;
        }
        if(i != 0)
            res += i, used[i] = 1;
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int q;
    cin >> q;
    while(q--)
        tc();
    return 0;
}