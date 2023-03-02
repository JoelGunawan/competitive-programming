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
void tc() {
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i) 
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    map<int, int> mapping, mapping2;
    for(auto i : a)
        mapping[i]++;
    int cnt = 0;
    for(auto i : mapping) {
        mapping2[i.fi] = cnt++;
    }
    for(int i = 0; i < n; ++i)
        a[i] = mapping2[a[i]];
    mapping.clear();
    for(auto i : b)
        mapping[i]++;
    cnt = 0;
    mapping2.clear();
    for(auto i : mapping) {
        mapping2[i.fi] = cnt++;
    }
    for(int i = 0; i < n; ++i)
        b[i] = mapping2[b[i]];
    // from the largest, as largest can eliminate everything
    // go to lower numbers
    // semacam dfs/bfs
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}