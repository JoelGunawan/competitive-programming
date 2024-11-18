// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
// #define endl "\n"
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
  sort(v.begin(), v.end());
  cout << "TANYA " << v.size() << endl;
  for(auto x : v)
    cout << x << " ";
  cout << endl;
  int x;
  cin >> x;
  return x;
}
void answer(int x) {
  cout << "JAWAB " << x << endl;
  exit(0);
}
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  // 1 2 3 4
  int n = 256;
  vector<int> q;
  for(int i = 1; i <= n / 2; ++i) {
    q.pb(i);
  }
  int x = query(q);
  if(x == 0) {
    q.clear();
    for(int i = n / 2 + 1; i <= n; ++i) {
      q.pb(i);
    }
    int x = query(q);
    q.pb(1);
    int y = query(q);
    if(x == y) {
      answer(129 - x);
    }
    else
      answer(x);
  }
  else {
    q.pb(n / 2 + 1);
    int y = query(q);
    if(x == y) {
      answer(257 - x);
    }
    else {
      answer(128 + x);
    }
  }
  return 0;
}