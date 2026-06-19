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
  int n;
  cin >> n;
  int p[n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> p[i];
  int q;
  cin >> q;
  // maintain a map<int, int> of counts
  // maintain a shift
  map<ll, int> cnt;
  ll shift = 0;
  ll sum = 0;

  for(int i = 1; i <= n; ++i) {
    sum += p[i];
    ++cnt[p[i]];
  }

  for(int que = 0; que < q; ++que) {
    string s; int x;
    cin >> s >> x;
    if(s == "INFLATION") {
      shift += x;
      sum += 1ll * x * n;
    } else {
      int y;
      cin >> y;
      ll st = x - shift, tgt = y - shift;
      sum += 1ll * (y - x) * cnt[st];
      int tmp = cnt[st];
      cnt[st] = 0;
      cnt[tgt] += tmp;
    }
    cout << sum << endl;
  }
  return 0;
}