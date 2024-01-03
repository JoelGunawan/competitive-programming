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
vector<int> child[lim];
int subtree[lim];
void get_subtree(int nd) {
    subtree[nd] = 1;
    for(auto i : child[nd]) {
        get_subtree(i);
        subtree[nd] += subtree[i];
    }
}
int dfs(int nd, int rem = 0) {
    // use heavy/light concept
    int mxchild = -1, res = 0;
    if(rem) {
        ++res;
        --rem;
    }
    for(auto i : child[nd]) {
        if(mxchild == -1)
            mxchild = i;
        else if(subtree[i] > subtree[mxchild])
            mxchild = i;
    }
    for(auto i : child[nd]) {
        if(i != mxchild)
            rem += subtree[i];
    }
    if(mxchild == -1)
        return rem / 2 + res;
    else
        return dfs(mxchild, rem) + res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) 
            child[i].clear();
        for(int i = 2; i <= n; ++i) {
            int x;
            cin >> x;
            child[x].pb(i);
        }
        get_subtree(1);
        cout << dfs(1) << endl;
    }
    return 0;
}