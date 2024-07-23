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

const int base = 311;
const int mod = 1e9 + 696969;

typedef unsigned long long ull;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string str;
  cin >> str;
  vector <int> a;
  int cur = 0;
  string s;
  while (getline(cin, s)) {
    str += s;
  }
  for (char c : str) {
    if (c == ',') {
      a.push_back(cur);
      cur = 0;
    } else {
      cur = 10 * cur + (c - '0');
    }
  }
  a.push_back(cur);

  vector <vector <ull>> xorhash(256, vector <ull> (256, 0));
  for (int i = 0; i < 256; i++)
  for (int j = 0; j < 256; j++) {
    xorhash[i][j] = rd();
  }

  int n = a.size();
  for (int len = 256; len >= 64; len--) {
    map <ull, int> index;
    for (int i = 0; i + len <= n; i++) {
      vector <int> cnt(256, 0);
      for (int k = i; k < i + len; k++) {
        cnt[a[k]]++;
      }  

      ull hash = 0;
      for (int j = 0; j < 256; j++) {
        hash ^= xorhash[j][cnt[j]];
      }

      if (index.count(hash)) {
        int j = index[hash];
        if (j + len <= i) {
          cout << len << " " << j << " " << i << "\n";
          exit(0);
        }
      } else {
        index[hash] = i;
      }
    }
  }

  cout << "no key\n";
  return 0;
}