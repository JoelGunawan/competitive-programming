#include <bits/stdc++.h>
using namespace std;
int main() {
  // complete search permutasi
  vector<int> v = {};
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
    v.push_back(i);
  random_shuffle(v.begin(), v.end()); // rng
  v.push_back(-1);
  cout << "awal: " << endl;
  for(auto x : v)
    cout << x << " ";
  cout << endl;
  do {
    for(auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  } while(next_permutation(v.begin(), v.begin() + v.size() - 1));
}