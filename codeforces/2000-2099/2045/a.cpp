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
  int cntv = 0, cntc = 0, cntflex = 0, cntng = 0;
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  string s;
  cin >> s;
  for(auto c : s)
    ++cnt[c - 'A'];
  string vowel = "aieou";
  for(int i = 0; i < 26; ++i) {
    if(i == 'y' - 'a') {
      cntflex += cnt[i];
    }   
    else if(find(vowel.begin(), vowel.end(), 'a' + i) == vowel.end()) {
      cntc += cnt[i];
    }
    else {
      cntv += cnt[i];
    }
  }
  cntng = min(cnt['n' - 'a'], cnt['g' - 'a']);
  int res = 0;
  for(int i = 0; i <= cntng; ++i) {
    for(int j = 0; j <= cntflex; ++j) {
      int curvowel = 0, curcons = 0;
      curvowel += cntv;
      curvowel += j;
      curcons += cntflex - j;
      curcons += cntc;
      curcons -= i;
      // cerr << curvowel << " " << curcons << endl;
      if(curcons > curvowel << 1)
        curcons = curvowel << 1;
      else if(curcons < curvowel << 1)
        curvowel = curcons >> 1, curcons -= curcons & 1;
      int cur = curvowel + curcons + min(curcons, i);
      res = max(res, cur);
    }
  }
  cout << res << endl;
  return 0;
}