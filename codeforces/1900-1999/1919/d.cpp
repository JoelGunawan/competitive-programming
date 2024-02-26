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
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    int nsl[n + 1], nsr[n + 1];
    memset(nsl, -1, sizeof(nsl));
    memset(nsr, -1, sizeof(nsr));
    vector<int> st;
    for(int i = 1; i <= n; ++i) {
      while(st.size() && st.back() >= a[i])
        st.pop_back();
      if(st.size())
        nsl[i] = st.back();
      st.pb(a[i]);
    }
    st.clear();
    for(int i = n; i >= 1; --i) {
      while(st.size() && st.back() >= a[i])
        st.pop_back();
      if(st.size())
        nsr[i] = st.back();
      st.pb(a[i]);
    }
    int cnt0 = 0;
    for(int i = 1; i <= n; ++i) {
      if(a[i] == 0)
        ++cnt0;
    }
    if(cnt0 != 1) {
      cout << "NO" << endl;
      continue;
    }
    bool ans = 1;
    for(int i = 1; i <= n; ++i) {
      if(a[i] == 0)
        continue;
      else if(nsl[i] != a[i] - 1 && nsr[i] != a[i] - 1) {
        ans = 0;
      }
    }
    if(ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}