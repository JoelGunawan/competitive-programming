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
  int n, q;
  cin >> n >> q;
  int last[n + 5];
  fill(last, last + n + 5, 1e9);
  int res = 0, last_lap = 0;
  for (int i = 1; i <= q; ++i) {
    // if we overtake -> assume the person "doesn't move"
    // if we get overtaken -> assume the person is infinitely fast
    // overtaking someone twice "in a row" -> at least one lap
    // what if
    // 1 2 1 2 -> only 1 lap minimum
    // 1 1 -2 2 2 -> two lap minimum (because get overtaken, then overtake again)
    // find "latest lap increase point", then we just have a bunch of segments 
    // and find the min time required
    // so important part: contiguous + only 
    int x;
    cin >> x;
    if (x < 0) {
      // get overtaken
      last[-x] = 1e9;
    } else {
      if (last[x] > i) {
        last[x] = i;
      } else {
        // check last lap, if last lap in current range, then fine, otherwise increment
        if (last_lap < last[x]) {
          last_lap = i - 1;
          ++res;
        }       
        last[x] = i; 
      }
    }
  }
  cout << res << endl;
  
  return 0;
}