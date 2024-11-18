#include <bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define mp make_pair
#define ins insert
#define ll long long
#define endl "\n"
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s = "";
  if(a - 1 + b - 1 <= n - 1) {
    for(int i = 1; i < n; ++i) {
      s += "L";
    }
    for(int j = 1; j < n; ++j) {
      s += "U";
    }
    pair<int, int> cur = mp(1, 1);
    while(cur != mp(a, b)) {
      if(cur.fi != a)
        s += "D", ++cur.fi;
      else
        s += "R", ++cur.se;
    }
    cout << s << endl;
  }
  else if(a - 1 + n - b <= n - 1) {
    for(int i = 1; i < n; ++i) {
      s += "R";
    }
    for(int j = 1; j < n; ++j) {
      s += "U";
    }
    pair<int, int> cur = mp(1, n);
    while(cur != mp(a, b)) {
      if(cur.fi != a)
        s += "D", ++cur.fi;
      else
        s += "L", --cur.se;
    }
    cout << s << endl;
  }
  else if(n - a + b - 1 <= n - 1) {
    for(int i = 1; i < n; ++i) {
      s += "L";
    }
    for(int j = 1; j < n; ++j) {
      s += "D";
    }
    pair<int, int> cur = mp(n, 1);
    while(cur != mp(a, b)) {
      if(cur.fi != a)
        s += "U", --cur.fi;
      else
        s += "R", ++cur.se;
    }
    cout << s << endl;
  }
  else {
    for(int i = 1; i < n; ++i) {
      s += "R";
    }
    for(int j = 1; j < n; ++j) {
      s += "D";
    }
    pair<int, int> cur = mp(n, n);
    while(cur != mp(a, b)) {
      if(cur.fi != a)
        s += "U", --cur.fi;
      else
        s += "L", --cur.se;
    }
    cout << s << endl;
  }
}