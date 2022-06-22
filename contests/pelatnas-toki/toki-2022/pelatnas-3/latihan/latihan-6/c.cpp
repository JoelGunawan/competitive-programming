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
struct fenwick {
    // make sparse fenwick, have shift
    // default shift set to 1e15
    ll shift = 1e15;
    map<ll, int> a;
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // each person i has a next person, where if person i picks up j, the next person to pick up j will be person nxt[i] 
    // each box has a certain person cycle associated
    // each cycle has a "root" node, where we maintain all queries related to that node and all insertions related to time at that node
    // basically use a universal time to make things easier
    
    return 0;
}