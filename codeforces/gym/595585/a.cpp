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
void tc() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt = 0;
  for(int i = 0; i < n; ++i)
    if(s[i] == 'W')
      ++cnt;
  if(cnt & 1) {
    cout << "NO" << endl;
    return;
  }
  int pref = 0;
  for(int i = 0; i < n; ++i) {
    if(s[i] == 'W')
      ++pref;
    else
      break;
  }
  int suff = 0;
  for(int i = 2 * n - 1; i >= n; --i) {
    if(s[i] == 'R')
      ++suff;
    else
      break;
  }
  if(pref >= cnt / 2 && suff >= cnt / 2) {
    cout << "YES" << endl;
  }
  else
    cout << "NO" << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}