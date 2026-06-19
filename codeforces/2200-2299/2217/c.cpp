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

ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}

void tc() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  // find period of a + period of b
  // period must be n, m
  if (gcd(n, a) != 1 || gcd(m, b) != 1) {
    cout << "NO" << endl;
    return;
  }

  // both gcd one, then assert that periods are "non-intersecting"
  // NO, NOT THE CASE (2, 2, 1, 1) case
  if (gcd(n, m) > 2) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) tc();
  return 0;
}