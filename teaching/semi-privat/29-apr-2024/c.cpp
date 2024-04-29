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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // mau complete search setiap subsequence
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 1; i <= n; ++i)
    v.push_back(i);
  // 0 ... 2^n - 1
  // 1 << x sama dengan 2^x
  // 1000 sama dengan 2^3
  // 0000000 (n digit)
  // 0000001
  // 0000010
  // ....
  // 1111111
  for(int i = 0; i < (1 << v.size()); ++i) {
    cout << "BITMASK " << i << endl;
    vector<int> cur;
    for(int j = 0; j < v.size(); ++j) {
      // kalo bit nyala -> bagian dari subsekuens
      // kalo bit mati -> bukan bagian dari subsekuens
      // apakah 
      // 0000001 & i hasilnya 0 atau bukan?
      // 0000010 & i hasilnya 0 atau bukan?
      // 0000100 & i hasilnya 0 atau bukan?
      // ...
      // 1000000
      cout << (1 << j) << " " << i << " " << ((1 << j) & i) << endl;
      if((1 << j) & i) {
        // bit nyala  
        cur.push_back(j);
      }
      else {
        // bit mati
      }
    }
    // 00 -> tidak ada
    // 01 -> elemen 0
    // 10 -> elemen 1
    // 11 -> elemen 0 dan 1
    // 000 -> tidak ada
    // 001 -> elemen 0
    // 010 -> elemen 1
    // 011 -> elemen 0 dan 1
    // 100 -> elemen 2
    // 101 -> elemen 0 dan 2
    // ...
    cout << "OUTPUT" << endl;
    for(auto x : cur) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}