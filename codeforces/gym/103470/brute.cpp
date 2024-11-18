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
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), b;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    for(int i = 1; i <= n; ++i) {
      b = a;
      int cnt = 0;
      for(int j = 1; j <= i; ++j) {
        for(int k = 1; k <= i; ++k) {
          if(b[j] < b[k])
            swap(b[j], b[k]), ++cnt;
        }
      }
      cout << cnt;
      if(i != n)
        cout << " ";
    }
    cout << endl;
  }
}
