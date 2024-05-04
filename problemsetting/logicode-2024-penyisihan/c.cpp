// header file
#include <bits/stdc++.h>
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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, p;
  cin >> n >> p;
  char a[n][2];
  for(int i = n - 1; i > n - p; --i) {
    if(i & 1) {
      a[i][0] = '0';
      a[i][1] = '1';
    }
    else {
      a[i][0] = '1';
      a[i][1] = '0';
    }
  }
  for(int i = n - p; i >= 0; --i) {
    if((n - p) & 1) {
      a[i][0] = '0';
      a[i][1] = '1';
    }
    else {
      a[i][0] = '1';
      a[i][1] = '0';
    }
  }
  for(int i = 0; i < 2; ++i) {
    for(int j = 0; j < n; ++j) {
      cout << a[j][i];
    }
    cout << endl;
  }
  return 0;
}