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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string waste;
  cin >> waste >> waste;
  string data;
  cin >> data;
  ifstream fin("file.in");
  if(data == "impossible") {
    cout << "AC" << endl;
  }
  else if(data == "empty") {
    ll a, m, p, q, r, s;
    fin >> a >> m >> p >> q >> r >> s;
    if(p >= r && q <= s) {
      cout << "AC" << endl;
    } else {
      cout << "WA" << endl;
    }
  }
  else {
    ll a, m, p, q, r, s;
    fin >> a >> m >> p >> q >> r >> s;
    char last = data.back();
    data.pop_back();
    int num = std::stoi(data);
    if(last == 'M') {
      for(int i = 0; i < num; ++i) {
        p *= m;
        q *= m;
      }
    } else {
      p += a * num;
      q += a * num;
    }
    while(cin >> data) {
      char last = data.back();
      data.pop_back();
      int num = std::stoi(data);
      if(last == 'M') {
        for(int i = 0; i < num; ++i) {
          p *= m;
          q *= m;
        }
      } else {
        p += a * num;
        q += a * num;
      }
    }
    if(p >= r && q <= s) {
      cout << "AC" << endl;
    } else {
      cout << "WA" << endl;
    }
  }
  return 0;
}