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
int a[505];
int memo[505][505];
ll solve(int l, int r) {
  if(l == r)
    return 0;
  if(memo[l][r] != -1)
    return memo[l][r];
  // for each l, r iterate forward and get prefix minimum. It can be an arbitrary partition of distances to 1
  // solve(l, r) = ... + solve(cl, cr) + dist(cl, l)
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  memset(memo, -1, sizeof(memo));
  cout << solve(1, n) << endl;
  return 0;
}