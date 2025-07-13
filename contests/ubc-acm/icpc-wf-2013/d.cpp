#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
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
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(NULL);
  // states: n, k
  map<unsigned ll, unsigned ll> ans;
  map<vector<int>, bool> vis;
  queue<vector<int>> bfs;
  bfs.push({1});
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
  lll lim = (lll)1 << 63;
  while(bfs.size()) {
    auto arr = bfs.front();
    bfs.pop();
    if(vis[arr])
      continue;
    vis[arr] = 1;
    int s = 0;
    for(int i = 0; i < arr.size(); ++i)
      s += arr[i];
    
    lll val = 1;
    lll v2 = 1;
    
    vector<int> cnt(64, 0);
    for(int i = 0; i < arr.size(); ++i) {
      for(int j = 2; j <= arr[i]; ++j)
        ++cnt[j];
    }
    for(int i = 2; i <= s; ++i) {
      val *= i;
      for(int j = 2; j < 64; ++j)
        while(cnt[j] > 0 && val % j == 0) {
          val /= j;
          --cnt[j];
        }
    }

    
    for(int i = 0; i < arr.size(); ++i)
      for(int j = 0; j < arr[i]; ++j)
        v2 *= primes[i];

    // for(int j = 0; j < cnt.size(); ++j) {
    //   if(cnt[j] != 0) {
    //     cout << "DEBUG" << endl;
    //     cout << (unsigned ll)val << " " << (unsigned ll)v2 << endl;
    //     cout << s << endl;
    //     for(int i = 0; i < arr.size(); ++i)
    //       cout << arr[i] << " ";
    //     cout << endl;
    //     cout << "DONE" << endl;
    //     cout.flush();
    //     assert(false);
    //   }
    //   // assert(tmp2[j] <= 1);
    // }

    if(ans.find(val) == ans.end()) {
      ans[val] = v2;
    } else {
      ans[val] = min(ans[val], (unsigned ll)v2);
    }

    val *= s + 1;
    if(val < lim) {
      v2 *= primes[arr.size()];
      arr.push_back(1);
      if(!vis[arr] && v2 < lim)
        bfs.push(arr);
      arr.pop_back();
      v2 /= primes[arr.size()];
    }
    for(int j = 0; j < arr.size(); ++j) {
      if(j == 0 || arr[j - 1] != arr[j]) {
        ++arr[j];
        val /= arr[j];
        v2 *= primes[j];
        if(val < lim && v2 < lim) {
          if(!vis[arr])
            bfs.push(arr);
        }
        val *= arr[j];
        v2 /= primes[j];
        --arr[j];
      }
    }
  }
  // cout << vis.size() << endl;
  // cout << ans.size() << endl;

  unsigned ll n;
  while(cin >> n) {
    cout << n << " " << ans[n] << endl;
  }

  return 0;
}