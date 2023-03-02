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
    // to reduce friends outside group -> make one of the friends of the original to the friend group
    // if init for cur group friend is >= q
    // therefore we should select one of the friends to be in cur group, which one?
    // we can merge using DSU?
    // start from most edges?
    // or start from least edges
    // most edges -> choose a few edges
    // if unique in consideration not possible fulfill -> abandon
    // what if need used by other nodes?
    // edges of node <= q -> just single group, others can merge
    // for p, what is the purpose?
    // each group has limit of p
    // the amount of edges reduced is at most p
    // q external connections, group not neccessarily connected but not useful if not connected (it just adds external for no reason)
    // difficulty is in assessing which node should get a certain node
    // for each node with edges <= q -> list all neighbors > q
    // it has to be paired
    // if 2 with neighbor > q connect -> possible
    // q == 1 or p == 1 trivial
    // q == 2 test case
    // if(p == q) -> 
    // if(p > q) -> 
    return 0;
}