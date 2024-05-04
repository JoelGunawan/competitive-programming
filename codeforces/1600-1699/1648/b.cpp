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
  int t;
  cin >> t;
  while(t--) {
    int n, c;
    cin >> n >> c;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    // limit of number -> x / y -> not a lot of possibilities
    // sieve style, if a[i] and a[j] exists, then 
    int pref[c + 1];
    bool exist[c + 1];
    memset(pref, 0, sizeof(pref));
    memset(exist, 0, sizeof(exist));
    for(int i = 1; i <= n; ++i) {
      ++pref[a[i]], exist[a[i]] = 1;
    }
    for(int i = 1; i <= c; ++i) {
      pref[i] = pref[i - 1] + pref[i];
      //cout << pref[i] << " ";
    }
    //cout << endl;
    bool ans = 1;
    for(int i = 1; i <= c; ++i) {
      // special case for 1
      if(!exist[i]) 
        continue;
      for(int j = i; j <= c; j += i) {
        //cout << i + j - 1 << " " << j - 1 << " " << pref[min(c, j + i - 1)] << " " << pref[j - 1] << endl;
        if(pref[min(c, j + i - 1)] - pref[j - 1]) {
          if(!exist[j / i])
            ans = 0;
        }
      }
    }
    cout << (ans ? "Yes" : "No") << endl;
  }
  return 0;
}