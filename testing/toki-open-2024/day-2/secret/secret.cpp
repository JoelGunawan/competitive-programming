#include "secret.h"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
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
const int inf = 1e9;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int lim = 1e9 + 5;
struct fenwick {
  gp_hash_table<int, ll, custom_hash> a;
  void update(int idx, ll val) {
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  void update(int l, int r, int val) {
    // cout << "update " << l << " " << r << " " << val << endl;
    ++l, ++r;
    update(l, val), update(r + 1, -val);
  }
  ll query(int idx) {
    ++idx;
    ll ret = 0;
    while(idx) {
      ret += a[idx];
      idx -= idx&-idx;
    }
    return ret;
  }
};
// subtask 1, 2 -> brute force precompute after each toggle
// subtask 3 -> binser if there is blocking segment in the middle of the query and outside of the query
// if both blocked -> impossible
// if middle blocked -> go to right most not blocked, then go left
// if outside blocked -> go right
// if both not blocked -> if there is a gap > half -> go right to the gap then go left (or just precomp)
// subtask 4 -> calc cost has to be large - small, check maxR and minL, make sure nothing is interfering
// subtask 5 -> calc cost while avoiding a "segment", if > 1 segment blocked -> no ans, else use precomp
// full sol -> ?
vector<int> a;
set<int> blocked;
int n, m;
/*
int mx = max(a[i], a[i - 1]), mn = min(a[i], a[i - 1]);
bool norm = blocked.lb(mn) == blocked.end() || *blocked.lb(mn) >= mx, out = blocked.size() == 0 || (blocked.lb(mn) == blocked.begin() && blocked.lb(mx) == blocked.end());
cost = min(mx - mn, m - mx + mn);
*/
ll total = 0;
fenwick bit;
void precomp() {
  for(int i = 1; i < n; ++i) {
    int mx = max(a[i], a[i - 1]), mn = min(a[i], a[i - 1]);
    if(mn == mx)
      continue;
    total += min(mx - mn, m - mx + mn);
    bit.update(mn, mx - 1, m - mx + mn);
    bit.update(0, mn - 1, mx - mn);
    bit.update(mx, lim, mx - mn);
  }
}
void init(int N, int M, std::vector<int> A) {
  a = A;
  m = M;
  n = N;
  precomp();
  sort(a.begin(), a.end());
  // remap values of a onto some other value
  return;
}

void toggle(int R) {
  if(blocked.count(R))
    blocked.erase(R);
  else
    blocked.ins(R);
  return;
}

long long query(int S, int T) {
  if(blocked.empty())
    return total;
  else {
    // cout << "DEBUG " << *blocked.begin() << " " << bit.query(*blocked.begin()) << endl;
    if(ub(a.begin(), a.end(), *blocked.begin()) != a.end() && (int)(*ub(a.begin(), a.end(), *blocked.begin())) <= (int)(*--blocked.end())) 
      return -1;
    else
      return bit.query(*blocked.begin());
  }
}
