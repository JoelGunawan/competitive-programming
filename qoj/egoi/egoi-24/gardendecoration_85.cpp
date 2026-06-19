#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
  int w, n;
  cin >> w >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (w == 0) {
    cout << 6 << endl;
  } else {
    // subtask 1, 3 (19 points)
    // how do you do a swap?
    // let's say we have a, b we want to swap
    // 1 1 -> 1 1 -> 1 1 -> 1 1
    // 0 1 -> 0 0 -> 1 0 -> 1 0
    // 1 0 -> 1 0 -> 0 0 -> 0 1
    // 0 0 -> 0 1 -> 0 1 -> 0 0

    // subtask 4, 5 (26 points)
    // how do you shift?
    // a b c d e f -> b c d e f a
    // let's represent as disjoint swaps?
    // a b c d e f -> b a d c f e -> b c d a f e -> b c d e f a (3 * 3)
    // 3 * logN operations for general, is there a faster way?
    // a b c d -> b c d a
    // a b c d -> c b a d -> b c d a
    // a b c d e f -> c b a f e d -> b c d e f a
    // general algo?
    // for 6:
    // a[1] a[2] a[3] a[4] a[5] a[6]
    // a[3] a[2] a[1] a[6] a[5] a[4]
    // a[2] a[3] a[4] a[5] a[6] a[1]
    // for 12:
    // a[1] a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9] a[10] a[11] a[12]
    // a[3] a[2] a[1] a[6] a[5] a[4] a[9] a[8] a[7] a[12] a[11] a[10]
    // a[2] a[3] a[4] a[5] a[6] a[1] a[8] a[9] a[10] a[11] a[12] a[7]
    // a[2] a[3] a[4] a[5] a[6] a[7] a[8] a[9] a[10] a[11] a[12] a[1]
    // for 10:
    // 1 2 3 4 5 6 7 8 9 10
    // 9 8 7 6 5 4 3 2 1 10
    // 2 3 4 5 6 7 8 9 10 1
    // OBSERVE: we can reverse 1 to n - 1 then swap to final pos
    // for 16:
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    // 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 16
    // 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 1
    // W = 6 solution: Done

    // TODO:
    // 1. Implement a swap routine, test with subtask 1, 3
    // swap procedure:
    // 1 1 -> 1 1 -> 1 1 -> 1 1
    // 0 1 -> 0 0 -> 1 0 -> 1 0
    // 1 0 -> 1 0 -> 0 0 -> 0 1
    // 0 0 -> 0 1 -> 0 1 -> 0 0
    vector<int> vals(n, 0);
    auto swp = [&] (int x, int y) {
      // cerr << "SWAP " << w << " " << x << " " << y << endl;
      if (w & 1) {
        if (x > y) {
          return vals[x] ^ !vals[y];
        } else {
          return vals[x];
        }
      } else {
        if (x < y) {
          return vals[x] ^ !vals[y];
        } else {
          return vals[x];
        }
      }
    };

    // decompose permutations, for each permutation, execute the swap
    vector<vector<int>> perms;
    vector<int> perm_len;
    int perm_num[n], perm_idx[n];
    memset(perm_num, -1, sizeof(perm_num));
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        vector<int> cur = {i};
        vis[i] = 1;
        int tmp = a[i];
        while (tmp != i) {
          vis[tmp] = 1;
          cur.push_back(tmp); 
          tmp = a[tmp];
        }
        for (int i = 0; i < cur.size(); ++i) {
          perm_num[cur[i]] = perms.size();
          perm_idx[cur[i]] = i;
        }
        perms.push_back(cur);
        perm_len.push_back(cur.size());
      }
    }

    // phase 1: reverse 0 to len - 2 in every permutation
    if (w >= 1 && w <= 3) {
      if (w & 1) {
        for (int i = 0; i < n; ++i) {
          cin >> vals[i];
          int cur;
          int len = perm_len[perm_num[i]];
          if (perm_idx[i] + 1 < len) {
            cur = swp(i, perms[perm_num[i]][len - perm_idx[i] - 2]);
          } else {
            cur = swp(i, i);
          }
          cout << cur << endl;
        }
      } else {
        // cerr << "running loop" << endl;
        for (int i = n - 1; i >= 0; --i) {
          cin >> vals[i];
          int cur;
          int len = perm_len[perm_num[i]];
          if (perm_idx[i] + 1 < len) {
            cur = swp(i, perms[perm_num[i]][len - perm_idx[i] - 2]);
          } else {
            cur = swp(i, i);
          }
          cout << cur << endl;
        }
      }
    }

    // phase 2: reverse 0 to n - 3 in every permutation, swp (n - 2, n - 1)
    if (w >= 4 && w <= 6) {
      if (w & 1) {
        for (int i = 0; i < n; ++i) {
          cin >> vals[i];
          int cur;
          int len = perm_len[perm_num[i]];
          if (len == 1) cur = swp(i, i);
          else if (perm_idx[i] == len - 1) cur = swp(i, perms[perm_num[i]][len - 2]);
          else if (perm_idx[i] == len - 2) cur = swp(i, perms[perm_num[i]][len - 1]);
          else cur = swp(i, perms[perm_num[i]][len - 3 - perm_idx[i]]);
          cout << cur << endl;
        }
      } else {
        for (int i = n - 1; i >= 0; --i) {
          cin >> vals[i];
          int cur;
          int len = perm_len[perm_num[i]];
          if (len == 1) cur = swp(i, i);
          else if (perm_idx[i] == len - 1) cur = swp(i, perms[perm_num[i]][len - 2]);
          else if (perm_idx[i] == len - 2) cur = swp(i, perms[perm_num[i]][len - 1]);
          else cur = swp(i, perms[perm_num[i]][len - 3 - perm_idx[i]]);
          cout << cur << endl;
        }
      }
    }
  }
  
  return 0;
}