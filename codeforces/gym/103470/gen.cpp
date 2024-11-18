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
  int t = 1;
  cout << t << endl;
  mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
  while(t--) {
    int n = 5;
    cout << n << endl;
    for(int i = 1; i <= n; ++i) 
      cout << (rng() % n) + 1 << " ";
    cout << endl;
  }
}