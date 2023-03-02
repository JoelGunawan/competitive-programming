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
    // tree find maximum nodes max dist = d
    // find diameter of tree
    // obs 1: ujung diameter of graph pasti dipakai
    // diameter -> indegree 1
    // if diameter chosen, the rest has to have dist x exactly from last node?
    // or not always dist x?
    // build from bottom up
    // maximum solution from depths x and above
    // dp from one of the diameters should be fine
    // modified dsu on tree
    
    return 0;
}