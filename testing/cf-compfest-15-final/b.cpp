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
        int n, p;
        cin >> n >> p;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; ++i) 
            cin >> a[i];
        for(int i = 1; i <= n; ++i)
            cin >> b[i];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, to_ins;
        pq.push(mp(p, 1e9));
        for(int i = 1; i <= n; ++i)
            to_ins.push(mp(b[i], a[i]));
        ll cost = 0;
        while(to_ins.size()) {
            while(pq.top().se == 0)
                pq.pop();
            cost += pq.top().fi;
            pair<int, int> tmp = pq.top();
            pq.pop();
            --tmp.se;
            pq.push(tmp);
            pq.push(to_ins.top());
            to_ins.pop();
        }
        cout << cost << endl;
    }
    return 0;
}