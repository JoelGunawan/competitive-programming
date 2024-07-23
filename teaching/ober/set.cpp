#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> s;
  s.insert(4);
  s.insert(6);
  s.insert(7);
  s.insert(8);
  cout << s.count(8) << endl;
  cout << s.count(10) << endl;
  s.erase(8);
  cout << s.count(8) << endl;
  cout << *s.lower_bound(2) << endl;
  // s = {4, 6, 7}
  s.erase(s.lower_bound(2));
  // s = {6, 7}
  cout << *s.lower_bound(2) << endl;
  // s.erase(s.lower_bound(10)); // menyebabkan error
  if(s.lower_bound(10) == s.end())
    cout << "INVALID" << endl;
  else
    cout << *s.lower_bound(10) << endl;
  if(s.lower_bound(7) == s.end())
    cout << "INVALID" << endl;
  else
    cout << *s.lower_bound(7) << endl;
  cout << s.size() << endl;
  // s = {6, 7}
  s.insert(5);
  s.insert(5);
  s.insert(5);
  cout << s.size() << endl;
}