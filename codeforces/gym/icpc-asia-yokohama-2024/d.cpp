#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;

const int oo = 1e9;
const ll ooo = 1e18;
const int mod = 998244353;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = 0;
  for (char c : s) {
    n += c == '1';
  }
  vector<int> lef(n, oo), rig(n, oo);

  auto prep = [&](string s) -> void {
    vector<pair<int, int>> st;
    int cnt = 0;
    for (char c : s) {
      if (c == '(') {
        continue;
      }

      if (c == '1') {
        st.push_back({cnt, cnt});
        cnt++;
      } else if (c == ')') {
        auto [u, v] = st.back();
        st.pop_back();
        auto [l, r] = st.back();
        st.pop_back();

        // cerr << l << " " << r << " " << u << " " << v << "\n";

        lef[r] = min(lef[r], r - l + 1);
        rig[u] = min(rig[u], v - u + 1);
        st.push_back({l, v});
      }
    }
  };

  prep(s), prep(t);

  int ans = 1;
  for (int i = 0; i + 1 < n; i++) {
    // cerr << lef[i] << " " << rig[i + 1] << "\n";
    ans = (ll) ans * lef[i] % mod * rig[i + 1] % mod;
  }

  cout << ans << "\n";
}