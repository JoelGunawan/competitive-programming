#include <bits/stdc++.h>
#define endl "\n"
#define mp make_pair
#define pb push_back
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
  multiset<int> asli;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(auto x : b)
    pq.push(x);
  vector<int> sol;
  set<int> firsts;
  for(int i = 2; i < min(n + 2, elems); ++i) {
    // set b[i] as a[2] + a[3]
    // assertion -> b[i] != b[i - 1]
    priority_queue<int, vector<int>, greater<int>> sums(pq);
    int cur_first = (b[0] + b[1] - b[i]) / 2;
    // cout << cur_first << endl;
    if(firsts.count(cur_first))
      continue;
    if(cur_first <= 0)
      break;
    // check everything else is valid or not
    vector<int> cur_vals;
    cur_vals.pb(cur_first);
    bool valid = 1;
    priority_queue<int, vector<int>, greater<int>> del;
    while(sums.size() && cur_vals.size() <= n) {
      while(sums.size() && del.size() && sums.top() == del.top())
        sums.pop(), del.pop();
      if(sums.size() && del.size() && sums.top() > del.top())
        break;
      if(sums.empty())
        break;
      int nx = sums.top() - cur_first;
      // cout << sums.top() << " " << cur_first << endl;
      if(nx > 1e9)
        break;
      // cout << "DEB " << sums.top() << " " << cur_first << endl;
      for(auto x : cur_vals) {
        del.push(x + nx);
        // cout << "DEL " << x + nx << endl;
      }
      cur_vals.push_back(nx);
    }
    // has to be like this, the possible answer is small so to avoid a lot of wasteful operations it's best to do this
    if(cur_vals.size() == n && sums.empty()) {
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