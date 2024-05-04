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
bool is_prime(int a) {
  if(a <= 1)
    return 0;
  for(int i = 2; i <= sqrt(a); ++i) {
    if(a % i == 0)
      return 0;
  }
  return 1;
}
// 0 -> not vis
// 1 -> active
// 2 -> cycle
// 3 -> not cycle
int cycle[100005];
int get_sum(int a) {
  string s = to_string(a);
  int ret = 0;
  for(auto x : s) {
    ret += (x - '0') * (x - '0');
  }
  return ret;
}
void find_cycle(int nd) {
  if(nd == 1) {
    cycle[nd] = 3;
    return;  
  }
  int nxt = get_sum(nd);
  cycle[nd] = 1;
  if(!cycle[nxt]) {
    find_cycle(nxt);
  }
  if(cycle[nxt] == 1 || cycle[nxt] == 2) {
    cycle[nd] = 2;
  }
  else {
    cycle[nd] = 3;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n = 1e4;
  vector<int> primes;
  for(int i = 1; i <= n; ++i) {
    if(is_prime(i))
      primes.pb(i);
  }
  for(auto x : primes) {
    find_cycle(x);
  }
  int t;
  cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << " " << (is_prime(b) && cycle[b] == 3 ? "YES" : "NO") << endl;
  }
  return 0;
}