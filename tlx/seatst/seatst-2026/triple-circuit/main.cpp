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
int cl = 128;
void do_or(int x, int y) {
  if (x >= cl || y >= cl) assert(false);
  ++cl;
  cout << "OR " << x << " " << y << endl;
}

void do_and(int x, int y) {
  if (x >= cl || y >= cl) assert(false);
  ++cl;
  cout << "AND " << x << " " << y << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // create the following structure:
  // make pairwise adjacent ORs
  // then create a grid 8x8 of pairs
  // do row ORs and column ORs
  // if row/column has more than one occurrence -> solution exists
  cout << 215 << endl;

  for (int i = 0; i < 64; ++i) {
    do_or(2 * i, 2 * i + 1);
  }

  int grid[8][8];
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      grid[i][j] = 128 + i * 8 + j;
    }
  }

  vector<int> row_or, col_or;
  for (int i = 0; i < 8; ++i) {
    do_or(grid[i][0], grid[i][1]);
    for (int j = 2; j < 8; ++j) {
      do_or(cl - 1, grid[i][j]);
    }
    row_or.pb(cl - 1);
  }

  for (int i = 0; i < 8; ++i) {
    do_or(grid[0][i], grid[1][i]);
    for (int j = 2; j < 8; ++j) {
      do_or(cl - 1, grid[j][i]);
    }
    col_or.pb(cl - 1);
  }

  // std::cout << "checkpoint" << endl;

  // we want to check from row_or/col_or whether there is more than one on bit
  std::function<void(vector<int>)> check_on = [&check_on] (vector<int> v) -> void {
    // dnc
    if (v.size() == 2) {
      do_and(v[0], v[1]);
      do_or(v[0], v[1]);
    } else {
      vector<int> l, r;
      for (int i = 0; i < v.size() / 2; ++i) l.push_back(v[i]);
      for (int i = v.size() / 2; i < v.size(); ++i) r.push_back(v[i]);

      check_on(l);
      int and1 = cl - 2, or1 = cl - 1;
      check_on(r);
      int and2 = cl - 2, or2 = cl - 1;
      do_and(or1, or2);
      do_or(cl - 1, and1);
      do_or(cl - 1, and2);
      if (v.size() != 8) do_or(or1, or2);
    }

    return;
  };

  check_on(row_or);
  int r = cl - 1;
  check_on(col_or);
  int c = cl - 1;
  do_or(r, c);

  return 0;
}