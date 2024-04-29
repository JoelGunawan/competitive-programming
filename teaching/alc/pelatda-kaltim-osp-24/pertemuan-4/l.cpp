#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  priority_queue<int> pq;
  // kompleksitas waktu: O(min(n, m)*logN + min(n, m) * k + nlogn + m)
  // sederhanakan! contoh: 1 + 2 + ... + n -> O(n^2)

  // for loop ini totalnya O(nlogn)
  for(int i = 1; i <= n; ++i) { // n kali
    pq.push(i); // tiap operasi O(logn)
  }

  // for loop ini totalnya O(m + min(n, m) * (logN + k)) 
  for(int i = 1; i <= m; ++i) {
    // m kali
    // di dalam if ini totalnya O(min(n, m) * (logN + k))
    if(pq.size() > 0) {
      // min(n, m) kali
      pq.pop(); // O(logn)
      for(int j = 1; j <= k; ++j) {
        cout << pq.top() << endl; // O(1)
      }
    }
  }
}