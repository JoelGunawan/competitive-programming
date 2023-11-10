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
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        int c[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> c[i];
        // greedy by indegree value
        ll res = 0;
        ll b[n + 1];
        memset(b, 0, sizeof(b));
        for(int i = 1; i <= n; ++i) {
            b[a[i]] += c[i];
        }
        // fi -> val
        // se -> index
        set<pair<ll, int>> s;
        for(int i = 1; i <= n; ++i) {
            s.ins(mp(b[i], i));
        }
        bool erased[n + 1];
        memset(erased, 0, sizeof(erased));
        vector<int> v;
        while(s.size()) {
            ll cost = (*s.begin()).fi; int idx = (*s.begin()).se;
            s.erase(s.begin());
            // waktu erase, cek par erase
            if(erased[a[idx]])
                res += c[idx];
            else
                res += 2 * c[idx];
            // hapus dr cost indegree parentnya
            erased[idx] = 1;
            int par = a[idx];
            if(!erased[par]) {
                s.erase(s.lb(mp(b[par], par)));
                b[par] -= c[idx];
                s.ins(mp(b[par], par));
            }
            v.pb(idx);
        }
        //cout << "TEST" << endl;
        //cout.flush();
        //cout << res << endl;
        for(auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}