#include "purwokerto.h"

// header file
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

std::pair<long long, int> purwokerto(int N, int M, std::vector<int> T) {
  // choose maximum empty day
  set<int> em, ac;
  for(int i = 1; i <= N; ++i)
    em.ins(i);
  ll res = 0;
  for(int i = 0; i < M; ++i) {
    if(!T[i]) {
      // purchase
      if(em.size()) {
        ac.ins(*--em.end());
        // cout << "to active " << *--em.end() << endl;
        em.erase(--em.end());
      }
    }
    else {
      // sell
      if(ac.size()) {
        em.ins(*--ac.end());
        res += *--ac.end();
        // cout << "sell " << *--ac.end() << endl;
        ac.erase(--ac.end());
      }
    }
  }
  return mp(res, 0);
}
