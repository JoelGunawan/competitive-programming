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
ifstream in[11];
ofstream out[11];
void open(int i) {
  in[i].open("inputs/pertahanan_" + to_string(i) + ".in");
  out[i].open("outputs/pertahanan_" + to_string(i) + ".out");
}
// subtask 1: by hand
// subtask 2: by hand
// subtask 3: just print in order of receive
void subtask_3() {
  open(3);
  int n, m, k;
  in[3] >> n >> m >> k;
  int a[k + 5];
  // cerr << "debug " << k << endl;
  for (int i = 1; i <= k; ++i) in[3] >> a[i];

  int cur = 0;
  for (int i = 1; i <= k; ++i) {
    out[3] << 0 << " " << 1 << " " << cur << " " << cur + a[i] << endl;
    cur += a[i];
  }
}
// subtask 4: 
// 99999
// 99998 1
// 99997 2
// ....
void subtask_4() {
  open(4);
  int n, m, k;
  in[4] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[4] >> a[i];

  int x1[k + 5], x2[k + 5], y1[k + 5], y2[k + 5];
  int mx = 99999;
  for (int i = 0; i < 50000; ++i) {
    x1[i] = 0;
    x2[i] = i;
    x1[mx - i] = i;
    x2[mx - i] = n;
    y1[i] = y1[mx - i] = i;
    y2[i] = y2[mx - i] = i + 1;
  }

  for (int i = 1; i <= k; ++i) {
    out[4] << x1[i] << " " << x2[i] << " " << y1[i] << " " << y2[i] << endl;
  }
}
// 50000 49999 
// subtask 5:
// simple?
void subtask_5() {
  open(5);
  int n, m, k;
  in[5] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[5] >> a[i];

  int idx = 0;
  int x1[k + 5], x2[k + 5], y1[k + 5], y2[k + 5];
  for (int i = 0; i < 293; ++i) {
    for (int j = 0; j < 311; ++j) {
      ++idx;
      x1[idx] = 9973 * i;
      x2[idx] = 9973 * (i + 1);
      y1[idx] = 99991 * j;
      y2[idx] = 99991 * (j + 1);
    }
  }

  for (int i = 1; i <= k; ++i) {
    out[5] << x1[i] << " " << x2[i] << " " << y1[i] << " " << y2[i] << endl;
  }
}

void subtask_6() {
  open(6);
  int n, m, k;
  in[6] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[6] >> a[i];

  vector<int> odd, even;
  ll sum = 0;
  int num[k + 5];
  for (int i = 1; i <= k; ++i) {
    if (a[i] & 1) num[i] = odd.size(), odd.pb(a[i]);
    else num[i] = even.size(), even.pb(a[i]);
    sum += a[i];
  }
  cout << sum << endl;

  // 3^10 * 2^10 = 6^10 ~6e7
  // do bitmask approach for odd and even
  vector<int> em(10, 0);
  vector<int> om(10, 0);
  for (int even_mask = 0; even_mask < 59049; ++even_mask) {
    ++em[0];
    for (int i = 0; i < 9; ++i) {
      if (em[i] == 3) em[i] = 0, em[i + 1]++;
    }

    bool found = 0;
    for (int odd_mask = 0; odd_mask < 1 << 10; ++odd_mask) {
      ll lsum = 0, rsum = 0;
      for (int j = 0; j < 10; ++j) {
        // even
        if (em[j] == 0) lsum += even[j];
        else if (em[j] == 1) rsum += even[j];
        else lsum += even[j] >> 1, rsum += even[j] >> 1;
        
        // odd
        if ((1 << j) & odd_mask) lsum += odd[j];
        else rsum += odd[j];
      }

      if (lsum == rsum) {
        for (int j = 0; j < 10; ++j) {
          if ((1 << j) & odd_mask) om[j] = 1;
        }
        found = 1;
        break;
      }
    }

    if (found) break;
  }

  ll cl = 0, cr = 0, back = m;
  int x1[k + 5], x2[k + 5], y1[k + 5], y2[k + 5];
  for (int i = 1; i <= k; ++i) {
    if (a[i] & 1) {
      // odd case
      if (om[num[i]]) {
        // put left
        x1[i] = 0;
        x2[i] = 1;
        y1[i] = cl;
        y2[i] = cl + a[i];
        cl += a[i];
      } else {
        // put right
        x1[i] = 1;
        x2[i] = 2;
        y1[i] = cr;
        y2[i] = cr + a[i];
        cr += a[i];
      }
    } else {
      // even case
      if (em[num[i]] == 0) {
        // put left
        x1[i] = 0;
        x2[i] = 1;
        y1[i] = cl;
        y2[i] = cl + a[i];
        cl += a[i];
      } else if (em[num[i]] == 1) {
        // put right
        x1[i] = 1;
        x2[i] = 2;
        y1[i] = cr;
        y2[i] = cr + a[i];
        cr += a[i];
      } else {
        // split
        x1[i] = 0;
        x2[i] = 2;
        y1[i] = back - a[i] / 2;
        y2[i] = back;
        back -= a[i] / 2;
      }
    }
  }

  for (int i = 1; i <= k; ++i) {
    out[6] << x1[i] << " " << x2[i] << " " << y1[i] << " " << y2[i] << endl;
  }
}

void subtask_7() {
  open(7);
  int n, m, k;
  in[7] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[7] >> a[i];

  // try algo:
  // greedy 80 largest
  // brute force 20 smallest
  vector<int> vals;
  for (int i = 1; i <= k; ++i) vals.pb(a[i]);
  sort(vals.begin(), vals.end());
  reverse(vals.begin(), vals.end());
  vector<int> l, r, b;
  ll suml = 0, sumr = 0;
  for (int i = 0; i < 80; ++i) {
    if (vals[i] & 1) {
      if (suml < sumr) l.pb(vals[i]), suml += vals[i];
      else r.pb(vals[i]), sumr += vals[i];
    } else {
      if (abs(sumr - suml) <= vals[i] / 2) {
        // split into two
        b.pb(vals[i]);
        suml += vals[i] / 2;
        sumr += vals[i] / 2;
      } else {
        if (suml < sumr) l.pb(vals[i]), suml += vals[i];
        else r.pb(vals[i]), sumr += vals[i];
      }
    }
  }

  int x1[k + 5], x2[k + 5], y1[k + 5], y2[k + 5];
  for (int mask = 0; mask < 1 << 20; ++mask) {
    ll cl = suml, cr = sumr;
    for (int i = 0; i < 20; ++i) {
      if ((1 << mask) & i) cl += vals[i + 80];
      else cr += vals[i + 80];
    }
    if (cl == cr) {
      for (int i = 0; i < 20; ++i) {
        if ((1 << mask) & i) l.pb(vals[i + 80]);
      else r.pb(vals[i + 80]);
      }
      int ls = 0, rs = 0, back = m;
      for (int i = 1; i <= k; ++i) {
        if (find(l.begin(), l.end(), a[i]) != l.end()) {
          // add to left
          x1[i] = 0, x2[i] = 1;
          y1[i] = ls, y2[i] = ls + a[i];
          ls += a[i];
          l.erase(find(l.begin(), l.end(), a[i]));
        } else if (find(r.begin(), r.end(), a[i]) != r.end()) {
          // add to right
          x1[i] = 1, x2[i] = 2;
          y1[i] = rs, y2[i] = rs + a[i];
          rs += a[i];
          r.erase(find(r.begin(), r.end(), a[i]));
        } else {
          if (find(b.begin(), b.end(), a[i]) == b.end()) {
            cerr << "value: " << a[i] << endl;
            assert(false);
          }
          // add to back
          x1[i] = 0, x2[i] = 2;
          y1[i] = back - a[i] / 2, y2[i] = back;
          back -= a[i] / 2;
          b.erase(find(b.begin(), b.end(), a[i]));
        }
      }
      break;
    }
  }

  for (int i = 1; i <= k; ++i) {
    out[7] << x1[i] << " " << x2[i] << " " << y1[i] << " " << y2[i] << endl;
  }
}

// 2^i 0...29 in 4681 * 229383 grid
// 4681 = 12 + 9 + 6 + 3 + 0
// 229383 = 17 + 16 + 15 + 2 + 1 + 0
void subtask_8() {
  open(8);
  int n, m, k;
  in[8] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[8] >> a[i];

  vector<int> h = {12, 9, 6, 3, 0}, w = {17, 16, 15, 2, 1, 0};
  int x1[k + 5], x2[k + 5], y1[k + 5], y2[k + 5];
  ll curh = 0;
  for (int i = 0; i < h.size(); ++i) {
    ll curw = 0;
    for (int j = 0; j < w.size(); ++j) {
      x1[i * w.size() + j] = curh, x2[i * w.size() + j] = curh + (1 << h[i]);
      y1[i * w.size() + j] = curw, y2[i * w.size() + j] = curw + (1 << w[j]);
      curw += 1 << w[j];
    }
    curh += 1 << h[i];
  }

  for (int i = 1; i <= k; ++i) {
    for (int j = 0; j < k; ++j) {
      if ((x2[j] - x1[j]) * (y2[j] - y1[j]) == a[i]) {
        out[8] << x1[j] << " " << x2[j] << " " << y1[j] << " " << y2[j] << endl;
      }
    }
  }
}

void subtask_9() {
  open(9);
  int n, m, k;
  in[9] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[9] >> a[i];
  
  // create a spiral, then normalize
  // right, up, left, down
  int x1[k + 5], y1[k + 5], x2[k + 5], y2[k + 5];
  x1[1] = 0, x2[1] = 1, y1[1] = 0, y2[1] = 1;
  int cl = 0, cr = 1, cd = 0, cu = 1;
  int pr = 0, cur = 1;
  for (int i = 2; i <= k; ++i) {
    int tmp = cur;
    cur += pr;
    pr = tmp;
    if (i % 4 == 2) {
      // go right
      x1[i] = cr, x2[i] = cr + cur;
      y1[i] = cd, y2[i] = cu;
      cr += cur;
    } else if (i % 4 == 3) {
      // go up
      x1[i] = cl, x2[i] = cr;
      y1[i] = cu, y2[i] = cu + cur;
      cu += cur;
    } else if (i % 4 == 0) {
      // go left
      x1[i] = cl - cur, x2[i] = cl;
      y1[i] = cd, y2[i] = cu;
      cl -= cur;
    } else {
      // go down
      x1[i] = cl, x2[i] = cr;
      y1[i] = cd - cur, y2[i] = cd;
      cd -= cur;
    }
  }

  // normalize
  for (int i = 1; i <= k; ++i) {
    x1[i] += -cl;
    x2[i] += -cl;
    y1[i] += -cd;
    y2[i] += -cd;
    swap(x1[i], y1[i]);
    swap(x2[i], y2[i]);
  }

  // output
  for (int i = 1; i <= k; ++i) {
    out[9] << x1[i] << " " << x2[i] << " " << y1[i] << " " << y2[i] << endl;
  }
}

void subtask_10() {
  open(10);
  // last 10k elements, random shuffle, then do greedily
  // first 68k elements, do greedily
  int n, m, k;
  in[10] >> n >> m >> k;
  int a[k + 5];
  for (int i = 1; i <= k; ++i) in[10] >> a[i];

  vector<vector<int>> res(2000);
  vector<int> sum(2000, 0);
  vector<int> vals;
  for (int i = 1; i <= k; ++i) vals.pb(a[i]);
  sort(vals.begin(), vals.end());
  reverse(vals.begin(), vals.end());
  
  int lim = 69000;
  int cur = 0;
  vector<int> first;
  for (int i = 0; i < lim; ++i) first.pb(vals[i]);

  mt19937 rng(42);
  bool found = false;
  int it = 0;
  while (!found) {
    found = true;
    sum = vector<int>(2000, 0);
    res = vector<vector<int>>(2000);
    shuffle(first.begin(), first.end(), rng);
    for (int i = 0; i < lim; ++i) {
      while (cur < 2000 && first[i] + sum[cur] > 2000) ++cur;
      if (cur == 2000) {
        found = false;
        break;
      }
  
      sum[cur] += first[i];
      res[cur].pb(first[i]);
    }
    ++it;
  }
  // cerr << "iterations: " << it << endl;

  vector<int> final;
  for (int i = lim; i < k; ++i) {
    final.pb(vals[i]);
  }

  int cnt[105];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < final.size(); ++i) {
    ++cnt[final[i]];
  }

  for (int i = 0; i < 2000; ++i) {
    if (sum[i] != 2000) {
      int rem = 2000 - sum[i];
      for (int j = min(rem, 100); j >= 0; --j) {
        // j too large
        if (j > rem) {
          j = rem + 1;
          continue;
        }

        if (cnt[j] > 0) {
          int red_cnt = min(cnt[j], rem / j);
          cnt[j] -= red_cnt;
          sum[i] += j * red_cnt;
          rem -= j * red_cnt;
          for (int k = 0; k < red_cnt; ++k) {
            res[i].pb(j);
          }
        }
      }
    }
  }

  // vector<int> rem;
  // int total = 0;
  // int rem_sum = 0;
  // for (int i = 0; i < 2000; ++i) {
  //   out[10] << "line " << i << ": ";
  //   for (auto x : res[i]) {
  //     out[10] << x << " ";
  //   }
  //   out[10] << endl;
  // }
  // for (int i = 0; i < 2000; ++i) {
  //   rem_sum += 2000 - sum[i];
  //   out[10] << "remainder: " << 2000 - sum[i] << endl;
  // }
  // cerr << "remainder total: " << rem_sum << endl;
  // ll tmp = 0;
  // for (int i = 1; i <= 100; ++i) {
  //   out[10] << "excess: " << cnt[i] << endl;
  //   total += cnt[i];
  //   tmp += cnt[i] * i;
  // }
  // cerr << "count remainder: " << total << endl;
  // cerr << "sum remainder: " << tmp << endl;
  int x1[k + 5], x2[k + 5], y1[k + 5], y2[k + 5];
  int idx = 0;
  map<int, vector<int>> avail;
  for (int i = 0; i < 2000; ++i) {
    int cur = 0;
    for (auto j : res[i]) {
      x1[idx] = i;
      x2[idx] = i + 1;
      y1[idx] = cur;
      y2[idx] = cur + j;
      cur += j;
      avail[j].push_back(idx);
      ++idx;
    }
  }

  for (int i = 1; i <= k; ++i) {
    int cur_idx = avail[a[i]].back();
    avail[a[i]].pop_back();
    out[10] << x1[cur_idx] << " " << x2[cur_idx] << " " << y1[cur_idx] << " " << y2[cur_idx] << endl;
  }
}

int main() {
  // subtask_3();
  // subtask_4();
  // subtask_5();
  // subtask_6();
  // subtask_7();
  // subtask_8();
  subtask_9();
  // subtask_10();

  // vector<int> a, b;
  // int x = 4681, y = 229383;
  // for (int i = 0; i < 30; ++i) {
  //   if ((1 << i) & x) a.pb(i);
  //   if ((1 << i) & y) b.pb(i);
  // }

  // for (auto x : a) cout << x << " ";
  // cout << endl;

  // for (auto x : b) cout << x << " ";
  // cout << endl;

  return 0;
}