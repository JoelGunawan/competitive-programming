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
  string s;
  cin >> s;
  stack<char> st;
  string res = "";
  for(int i = 1; i < s.size(); ++i) {
    st.push(s[i]);
    res += s[i];
  }
  for(int i = 0; i < s.size() - 1; ++i) {
    while (st.size() && st.top() != s[i]) {
      st.pop();
    }

    if (st.empty()) {
      res += s[i];
    }
  }

  cout << res << endl;

  return 0;
}