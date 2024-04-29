#include <bits/stdc++.h>
using namespace std;
int main() {
  // kegunaan lower bound dan upper bound set
  set<int> s;
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; ++i) {
    // carilah elemen pertama yg kurang dari input yg diberi
    int x;
    cin >> x;
    // --s.lower_bound(x) -> dari elemen pertama yg >= jadi elemen pertama yg <
    if(s.lower_bound(x) == s.begin()) {
      cout << "INVALID" << endl;
    }
    else {
      cout << *--s.lower_bound(x) << endl;
    }
    // logika: 
    // 3, 5, 7, 9, 12
    // if(s.upper_bound(x) == s.end()) {
    //   cout << "INVALID" << endl;
    // }
    // else {
    //   cout << (*s.upper_bound(x)) << endl;
    // }
  }
}