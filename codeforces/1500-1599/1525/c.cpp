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
  int n, m;
  cin >> n >> m;
  int x[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> x[i];
  char a[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  // check parity
  // for each pairty, check collision closest
  // at most after one collision with wall, hit something, otherwise ignore
  vector<pair<pair<int, int>, int>> par1, par2;
  for(int i = 1; i <= n; ++i) {
    if(x[i] & 1)
      par1.push_back({{x[i], a[i] == 'R'}, i});
    else
      par2.push_back({{x[i], a[i] == 'R'}, i});
  }

  sort(par1.begin(), par1.end());
  sort(par2.begin(), par2.end());
  // if last two collide before current, then last two will collide together
  // otherwise, continue pushing
  // what happens for rightmost (bash on right?)
  // same case...
  auto collide = [&] (pair<int, int> a, pair<int, int> b) -> int {
    if(a.se && b.se) {
      // both right
      if(a.fi > b.fi)
        swap(a, b);
      return abs(a.fi - b.fi) / 2 + m - max(a.fi, b.fi);
    }
    else if(a.se || b.se) {
      if(a.se && !b.se)
        swap(a, b);
      // one going right, one going left
      if(a.fi > b.fi) {
        return abs(a.fi - b.fi) / 2;
      }
      else {
        // go opposite directions...
        return (m + m - b.fi + a.fi) / 2;
      }
    }
    else {
      if(a.fi < b.fi)
        swap(a, b);
      return abs(a.fi - b.fi) / 2 + min(a.fi, b.fi);
    }
  };
  vector<pair<pair<int, int>, int>> v;
  int ans[n + 1];
  memset(ans, -1, sizeof(ans));
  for(int i = 0; i < par1.size(); ++i) {
    while(v.size() >= 2) {
      int tmp;
      if((tmp = collide(v[v.size() - 2].fi, v.back().fi)) < collide(v.back().fi, par1[i].fi)) {
        ans[v.back().se] = tmp;
        v.pop_back();
        ans[v.back().se] = tmp;
        v.pop_back();
      }
      else {
        break;
      }
    }
    v.pb(par1[i]);
  }
  while(v.size() >= 2) {
    int tmp = tmp = collide(v[v.size() - 2].fi, v.back().fi);
    ans[v.back().se] = tmp;
    v.pop_back();
    ans[v.back().se] = tmp;
    v.pop_back();
  }
  v.clear();
  for(int i = 0; i < par2.size(); ++i) {
    while(v.size() >= 2) {
      int tmp;
      if((tmp = collide(v[v.size() - 2].fi, v.back().fi)) < collide(v.back().fi, par2[i].fi)) {
        ans[v.back().se] = tmp;
        v.pop_back();
        ans[v.back().se] = tmp;
        v.pop_back();
      }
      else {
        break;
      }
    }
    v.pb(par2[i]);
  }
  while(v.size() >= 2) {
    int tmp = tmp = collide(v[v.size() - 2].fi, v.back().fi);
    ans[v.back().se] = tmp;
    v.pop_back();
    ans[v.back().se] = tmp;
    v.pop_back();
  }
  for(int i = 1; i <= n; ++i) 
    cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  while(t--)
    tc();
  return 0;
}