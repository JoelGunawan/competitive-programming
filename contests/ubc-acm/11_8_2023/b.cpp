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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int cnt[105];
        memset(cnt, 0, sizeof(cnt));
        int a[n + 1];
        set<int> distinct;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            distinct.insert(a[i]);
            ++cnt[a[i]];
        }
        bool ans = 0;
        int cnt2 = 0;
        for(int i = 1; i <= 100; ++i) {
            if(cnt[i] >= 2) {
                ++cnt2;
            }
        }
        if(cnt2 >= 2) {
            int res[n + 1];
            for(int i = 1; i <= n; ++i) {
                res[i] = 1;
            }
            int x = 0;
            for(int i = 1; i <= 100; ++i) {
                if(cnt[i] >= 2) {
                    for(int j = 1; j <= n; ++j) {
                        if(a[j] == i) {
                            if(x == 1) {
                                res[j] = 3;
                            }
                        }
                    }
                    for(int j = n; j >= 1; --j) {
                        if(a[j] == i) {
                            if(x == 1) {
                                res[j] = 2;
                            }
                            else if(x == 0) {
                                res[j] = 3;
                            }
                            break;
                        }
                    }
                    ++x;
                }
            }
            for(int i = 1; i <= n; ++i)
                cout << res[i] << " ";
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}