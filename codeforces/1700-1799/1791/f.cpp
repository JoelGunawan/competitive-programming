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
        int n, q;
        cin >> n >> q;
        int a[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        set<int> can_up;
        for(int i = 1; i <= n; ++i) {
            if(a[i] >= 10)
                can_up.insert(i);
        }
        while(q--) {
            int op;
            cin >> op;
            if(op == 1) {
                int l, r;
                cin >> l >> r;
                auto it = can_up.lb(l);
                vector<int> del;
                while(it != can_up.end() && *it <= r) {
                    int tmp = *it;
                    string tmp2 = to_string(a[tmp]);
                    int sum = 0;
                    for(auto i : tmp2)
                        sum += i - '0';
                    a[tmp] = sum;
                    ++it;
                    if(sum < 10)
                        del.pb(tmp);
                }
                for(auto i : del)
                    can_up.erase(i);
            }
            else {
                int x;
                cin >> x;
                cout << a[x] << endl;
            }
        }
    }
    return 0;
}