#include <bits/stdc++.h>
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
// Joel's solution
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // set a[2] + a[3] to b[x]
  // then we get that a[1] = a[2] + a[3]
  int n;
  cin >> n;
  int elems = n * (n - 1) / 2;
  int b[elems];
  for(int i = 0; i < elems; ++i)
    cin >> b[i];
  sort(b, b + elems);
  multiset<int> sums;
  for(auto x : b)
    sums.insert(x);
  vector<int> sol;
  set<int> firsts;
  for(int i = 2; i < min(n + 2, elems); ++i) {
    // set b[i] as a[2] + a[3]
    // assertion -> b[i] != b[i - 1]
    int cur_first = (b[0] + b[1] - b[i]) / 2;
    if(firsts.count(cur_first))
      continue;
    if(cur_first <= 0)
      break;
    // check everything else is valid or not
    vector<int> cur_vals;
    cur_vals.pb(cur_first);
    bool valid = 1;
    multiset<int> deleted;
    for(int j = 0; j < elems; ++j) {
      if(sums.find(b[j]) != sums.end()) {
        // set as an element that is bigger than everything else previously
        // has to be paired with smallest first (automatically it should be >= all prev)
        int nx = b[j] - cur_first;
        for(auto x : cur_vals) {
          if(sums.find(nx + x) == sums.end()) {
            valid = 0;
            break;
          }
          else {
            sums.erase(sums.find(nx + x));
            deleted.insert(nx + x);
          }
        }
        cur_vals.pb(nx);
      }
      if(!valid)
        break;
    }
    // has to be like this, the possible answer is small so to avoid a lot of wasteful operations it's best to do this
    for(auto x : deleted)
      sums.insert(x);
    if(valid) {
      firsts.insert(cur_first);
      if(cur_first == *firsts.begin())
        sol = cur_vals;
    }
  }
  cout << firsts.size() << endl;
  for(auto x : sol)
    cout << x << " ";
  cout << endl;
  return 0;
}