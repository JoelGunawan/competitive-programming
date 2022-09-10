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
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    vector<int> s;
    for(int i = (n + 1) / 2; i <= n; ++i) {
        s.push_back(a[i]);
    }
    int res = s[0];
    for(int i = 0; i < s.size() - 1; ++i) {
        // yang mau dinaikkan i + 1 elemen
        // kalo sama dengan elemen ke i + 1, langsung naik
        // kalo ga sama, kita pake operasinya
        if(k >= 1ll * (i + 1) * (s[i + 1] - s[i])) {
            k -= (i + 1) * (s[i + 1] - s[i]);
            res = s[i + 1];
        }
        else {
            res = s[i] + k / (i + 1);
            cout << res << endl;
            return 0;
        }
    }
    res += k / (n / 2 + 1);
    cout << res << endl;
    return 0;   
}