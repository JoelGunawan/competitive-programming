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
    // each node with indegree > 1 -> remove all nodes going to cur node except for one
    // determining the one -> if form SCC with cur node -> definitely
    // else -> just choose any random
    // free nodes -> just assign to random
    // other nodes with indegree > 1 can have their nodes rerouted
    // nodes pointing to nodes with no outdegree can be made SCC directly
    // pick node with no indegree first
    // if not exist, then what?
    // do recursive on child!
    // indegree 1: either cycle or ends in self loop
    
    return 0;
}