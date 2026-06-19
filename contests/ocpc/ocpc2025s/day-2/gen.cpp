#include <bits/stdc++.h>
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

long long rand(long long l, long long r) {
  return l + rd() % (r - l + 1);
}

int main() {
  int n = rand(1,10000);
  cout << n << "\n";
  for (int i = 0; i < n; i++) {
    cout << rand(0, 1000) << " \n"[i == n - 1];
  }
}