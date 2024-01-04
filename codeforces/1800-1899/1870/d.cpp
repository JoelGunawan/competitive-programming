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
        int c[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> c[i];
        int k;
        cin >> k;
        // find largest of first, largest of second, largest of third, ...
        // find "upgrade" to the right that could work
        // order: by most that can be bought, than try swap lower for larger if can not buy
        // find increasing subsequence from 0 kind of like stack algo
        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            while(v.size() && c[v.back()] >= c[i]) 
                v.pop_back();
            v.pb(i);
        }
        // coba upgrade ke yang lebih besar kalo bisa
        vector<pair<int, int>> res = {mp(k / c[v[0]], v[0])};
        if(res[0].fi == 0) {
            for(int i = 1; i <= n; ++i)
                cout << 0 << " ";
            cout << endl;
            continue;
        }
        k %= c[v[0]];
        //cout << "INIT " << res[0].fi << " " << res[0].se << endl;
        for(int i = 1; i < v.size(); ++i) {
            int cur_cnt = 0;
            int can = k / (c[v[i]] - c[res.back().se]);
            //cout << can << endl;
            if(can >= res.back().fi) {
                k -= (c[v[i]] - c[res.back().se]) * res.back().fi;
                cur_cnt += res.back().fi;
                res.pop_back();
            }
            else {
                int add = k / (c[v[i]] - c[res.back().se]);
                cur_cnt += add;
                k -= add * (c[v[i]] - c[res.back().se]);
                res.back().fi -= add;
                //cout << "TEST " << cur_cnt << " " << res.back().se << endl;
            }
            if(cur_cnt)
                res.pb(mp(cur_cnt, v[i]));
        }
        int diff[n + 2];
        memset(diff, 0, sizeof(diff));
        for(auto i : res) {
            diff[1] += i.fi;
            diff[i.se + 1] -= i.fi;
        }
        int cur = 0;
        for(int i = 1; i <= n; ++i) {
            cur += diff[i];
            cout << cur << " ";
        }
        cout << endl;
    }
    return 0;
}