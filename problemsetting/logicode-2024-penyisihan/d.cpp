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
  int n;
  cin >> n;
  set<int> s;
  string tmp;
  cin >> tmp;
  for(int i = 0; i < tmp.size(); ++i) {
    if(tmp[i] == 'X')
        s.ins(i + 1);
  }
  assert(s.size());
  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if(t == 1) {
        int x, y;
        cin >> x >> y;
        s.erase(x), s.ins(y);
    }
    else {
        int close = 1e9;
        int x;
        cin >> x;
        if(s.lb(x) != s.end())
            close = min(close, *s.lb(x) - x);
        if(s.ub(x) != s.begin()) 
            close = min(close, x - *--s.ub(x));
        cout << close << endl;
    }
  }
  return 0;
}