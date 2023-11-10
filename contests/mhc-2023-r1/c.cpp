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
    int c = 0;
    while(t--) {
        ++c;
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = " " + s;
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        int q;
        cin >> q;
        for(int i = 1; i <= q; ++i) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        for(int i = n; i >= 1; --i) {
            if(cnt[i] & 1) {
                for(int j = 2 * i; j <= n; j += i)
                    ++cnt[j];
            }
        }
        for(int i = 1; i <= n; ++i)
            cnt[i] += (s[i] == '1');    
        int res = 0;
        for(int i = 1; i <= n; ++i) {
            if(cnt[i] & 1) {
                //cout << i << " ";
                ++res;
                for(int j = i; j <= n; j += i)
                    ++cnt[j];
            }
        }
        //cout << endl;
        cout << "Case #" << c << ": " << res << endl;
    }
    return 0;
}