#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
  // we know the minimum ending N, M we need
  // therefore we will start the possible values of the top right from there.
  // type B -> less strict probably, forms a grid
  // type A -> only intersect points of grid
  // Q: smallest rectangle by area that encapsulates everything
  // Idea: try all possible values of width/height (we know max is 5k???? (because D is small!!!))
  // can use bsta maybe to verify some things
  return 0;
}