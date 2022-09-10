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
    // fi -> elem
    // se -> cnt
    deque<pair<int, int>> a;
    int cnt = 0;
    bool rev = 0;
    while(n--) {
        string op;
        cin >> op;
        if(op == "add") {
            int x, y;
            cin >> x >> y;
            if(!rev)
                a.pb(mp(x, y));
            else
                a.push_front(mp(x, y));
            cnt += y;
            cout << cnt << endl;
        }
        else if(op == "del") {
            int y;
            cin >> y;
            cnt -= y;
            if(a.size() == 0) {
                cout << -1 << endl;
                continue;
            }
            else if(!rev) {
                cout << a.front().fi << endl;
                while(y && a.size()) {
                    if(a.front().se <= y)
                        y -= a.front().se, a.pop_front();
                    else
                        a.front().se -= y, y = 0;
                }
            }
            else {
                cout << a.back().fi << endl;
                while(y && a.size()) {
                    if(a.back().se <= y)
                        y -= a.back().se, a.pop_back();
                    else
                        a.back().se -= y, y = 0;
                }
            }
        }
        else
            rev = !rev;
    }
    return 0;
}