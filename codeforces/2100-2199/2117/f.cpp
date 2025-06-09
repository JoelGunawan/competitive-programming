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
const int lim = 2e5 + 5;
vector<int> edges[lim], child[lim];
bool vis[lim];
int cnt_leaf = 0;
void dfs(int nd) {
  vis[nd] = 1;
  for(auto i : edges[nd]) {
    if(!vis[i]) {
      dfs(i);
      child[nd].push_back(i);
    }
  }
  if(child[nd].empty())
    ++cnt_leaf;
}
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
  if(b == 0) {
    return 1;
  }
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return (b & 1) & 1 ? (tmp * a) % mod : tmp;
  }
}
void tc() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    edges[i].clear(), child[i].clear(), vis[i] = 0;
  cnt_leaf = 0;
  for(int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1);
  // cerr << "RES " << cnt_leaf << endl;
  if(cnt_leaf > 2) {
    cout << 0 << endl;
  }
  else if(cnt_leaf == 1) {
    cout << powmod(2, n) << endl;
  } else {
    int split = -1;
    for(int i = 1; i <= n; ++i) {
      if(child[i].size() == 2) {
        split = i;
        break;
      }
    }
    int cnt = 2;
    int c1 = child[split][0], c2 = child[split][1];
    int d1 = 0, d2 = 0;
    while(child[c1].size()) {
      ++d1;
      ++cnt;
      c1 = child[c1][0];
    }
    while(child[c2].size()) {
      ++d2;
      ++cnt;
      c2 = child[c2][0];
    }
    // below split, count how many free, how many fixed
    cout << ((d1 != d2 ? 3 : 2) * powmod(2, max(0, abs(d1 - d2) - 1) + n - cnt)) % mod << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}