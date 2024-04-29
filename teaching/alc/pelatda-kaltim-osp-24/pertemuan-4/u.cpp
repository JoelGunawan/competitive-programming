#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  priority_queue<int> pq;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pq.push(x);
  }
  int cur = 0, cnt = 0;
  while(pq.size() && cur < b) {
    cur += pq.top();
    cnt++;
    pq.pop();
  }
  cout << cnt << endl;
}