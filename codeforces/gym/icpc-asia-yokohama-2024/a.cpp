#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int d[n + 1];
  for(int i = 1; i <= n; ++i)
    cin >> d[i];
  d[0] = 0;
  int res = 0;
  for(int i = 1; i <= 100; ++i) {
    bool active = 0;
    for(int j = 1; j <= n; ++j) {
      if(d[j] == i) {
        if(!active) {
          ++res;
          active = 1;
        }
      } else if(d[j] < i) {
        active = 0;
      }
    }
  }
  cout << res << endl;
}