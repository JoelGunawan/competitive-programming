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
  ll n;
  cin >> n;
  vector<pair<int, int>> cnt;

  for(ll i = 2; i * i <= n; ++i) {
    if(n % i == 0) {
      int num = 0;
      while(n % i == 0) {
        n /= i;
        ++num;
      }
      cnt.emplace_back(num, i);
    }
  }

  if(n > 1) {
    cnt.emplace_back(1, n);
  }
  
  sort(cnt.begin(), cnt.end());

  cout << cnt[0].se << endl;

  return 0;
}