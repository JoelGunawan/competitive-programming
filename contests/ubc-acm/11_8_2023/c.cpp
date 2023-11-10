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
const int lim = 2e5 + 5;
bool vis[lim];
vector<int> edges[lim];
int max_len(int nd, int cur) {
    vis[nd] = 1;
    int ans = cur;
    for(auto i : edges[nd]) {
        if(vis[i]) {
            return 1e9;
        }
        ans = max(ans, max_len(i, cur + 1));
    }
    return ans;
}
void tc() {
    int n, k;
    cin >> n >> k;
    int b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    // cek harus cycle shift berapa biar bs lakuin fixed point di x
    vector<int> pos[n + 1];
    for(int i = 1; i <= n; ++i) {
        if(b[i] <= n)
            pos[b[i]].pb(i);
    }
    for(int i = 1; i <= n; ++i) {
        vector<int> shifts;
        for(auto j : pos[i]) {
            shifts.push_back(i - j);
            if(shifts.back() < 0)
                shifts.back() += n;
        }
        for(auto j : shifts) {
            if(j - i < 0) {
                edges[j - i + n].push_back(j);
            }
            else
                edges[j - i].push_back(j);
        }
    }
    // edges are created, try to find path that ends at 0 with length at least k
    // or if 0 is part of a cycle
    if(max_len(0, 0) >= k) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for(int i = 0; i <= n; ++i)
        edges[i].clear(), vis[i] = 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}