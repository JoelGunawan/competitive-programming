// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
int query(vector<int> v) {
  cout << "? ";
  cout << v.size() << " ";
  for(auto x : v) {
    cout << x << " ";
  }
  cout << endl;
  int ret;
  cin >> ret;
  return ret;
}
void answer(vector<int> ans) {
  cout << "! ";
  for(auto x : ans)
    cout << x << " ";
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> v = {0};
  while(v.size() < n) {
    int x = v.size();
    vector<int> q;
    q.pb(v[0]);
    q.pb(x);
    for(int i = 1; i < v.size(); ++i)
      q.pb(v[i]), q.pb(v[0]), q.pb(x);
    int ret = query(q);
    if(ret == 2 * v.size() - 1)
      v.insert(v.begin(), x);
    else
      v.insert(v.begin() + ret - (v.size() - 1) + 1, x);
  }
  vector<int> vv = vector<int>(v.size());
  for(int i = 0; i < v.size(); ++i)
    vv[v[i]] = i;
  answer(vv);
  return 0;
}