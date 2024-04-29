#include <bits/stdc++.h>
using namespace std;
int main() {
  // mau top() jadi yg minimum
  // solusi 1 -> kita jadikan semuanya negatif (rawan salah)
  // solusi 2 -> 
  // priority_queue<tipe_data, vector<tipe_data>, greater<tipe_data>> pq;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push(make_pair(3, 2));
  pq.push(make_pair(2, 4));
  cout << pq.top().first << " " << pq.top().second << endl;
  pq.push(make_pair(2, 6));
  cout << pq.top().first << " " << pq.top().second << endl;
  pq.push(make_pair(2, 2));
  cout << pq.top().first << " " << pq.top().second << endl;
}