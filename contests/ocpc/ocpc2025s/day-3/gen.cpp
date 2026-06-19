#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
#define ll long long 
using namespace std;

const int oo = 1e9;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r) {
  return l + rd() % (r - l + 1);
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = rand(3, 5);
  cout << n << "\n";
  for (int i = 1; i <= n; i++) {
    cout << rand(1, 10) << " ";
  }
}