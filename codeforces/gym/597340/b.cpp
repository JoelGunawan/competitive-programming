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
// pattern matches:
int arr[10][7] = {{1, 1, 1, 0, 1, 1, 1}, 
                  {0, 0, 0, 0, 0, 1, 1}, 
                  {0, 1, 1, 1, 1, 1, 0}, 
                  {0, 0, 1, 1, 1, 1, 1}, 
                  {1, 0, 0, 1, 0, 1, 1},
                  {1, 0, 1, 1, 1, 0, 1},
                  {1, 1, 1, 1, 1, 0, 1},
                  {0, 0, 1, 0, 0, 1, 1},
                  {1, 1, 1, 1, 1, 1, 1},
                  {1, 0, 1, 1, 1, 1, 1}};
  
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int cur[7];
    for(int j = 0; j < s.size(); ++j) {
      if(s[j] == 'g')
        cur[j] = 0;
      else if(s[j] == 'G')
        cur[j] = 1;
      else
        cur[j] = 2;
    }
    int match = -1;
    for(int j = 0; j < 10; ++j) {
      bool cur_match = 1;
      for(int k = 0; k < 7; ++k) {
        if(cur[k] == 2 || arr[j][k] == cur[k]) {
          // matches
        }
        else {
          cur_match = 0;
        }
      }
      if (cur_match) {
        if(match == -1)
          match = j;
        else
          match = 10;
      }
    }
    if(match == 10) {
      cout << '*';
    }
    else {
      cout << match;
    }
  }
  cout << endl;
  return 0;
}