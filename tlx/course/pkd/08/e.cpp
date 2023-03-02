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
    int a[n + 1];
    vector<int> v;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(v.empty())
            v.pb(a[i]);
        else if(a[i] <= v.back())
            v.pb(a[i]);
        else {
            while(v.size() && a[i] > v.back()) {
                if(v.size() == 1 || v[v.size() - 2] > a[i])
                    ans += a[i];
                else
                    ans += v[v.size() - 2];
                v.pop_back();
            }
            v.pb(a[i]);
        }
    }
    if(v.size()) {
        for(int i = 0; i < v.size() - 1; ++i) {
            ans += v[i];
        }
    }
    cout << ans << endl;
    return 0;
}