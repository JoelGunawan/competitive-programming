#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int n = s.size(), cur = -1;
  vector<int> l, r;
  for (int i = 0; i < n; i++) {
    if (s[i] == '#') {
      if (cur == -1) {
        l.push_back(i);
      } else {
        r.push_back(i);
      }
    } else if (s[i] == 'X') {
      cur = i;
    }
  }
  reverse(begin(r), end(r));
  int dl = 0, dr = 0, tcur = cur;
  bool flag = 0;
  vector<int> tl = l, tr = r;
  char pre = 'T';
  string ans = "";
  while (tl.size() || tr.size()) {
    if (tr.size()) {
      if (tr.back() - dr <= cur) {
        flag = 1;
        break;
      }
    }
    if (tl.size()) {
      if (tl.back() + dl >= cur) {
        flag = 1;
        break;
      }
    }
    if (tl.size() == 0) {
      if (pre != 'R') {
        tr.pop_back();
        pre = 'R';
      } else {
        pre = 'L';
      }
    } else if (tr.size() == 0) {
      if (pre != 'L') {
        tl.pop_back();
        pre = 'L';
      } else {
        cur++;
        pre = 'D';
      }
    } else {
      if (tl.back() + dl == cur - 1) {
        if (pre != 'L') {
          tl.pop_back();
          pre = 'L';
        } else {
          cur++;
          pre = 'D';
        }
      } else {
        if (pre != 'R') {
          tr.pop_back();
          pre = 'R';
        } else {
          tl.pop_back();
          pre = 'L';
        }
      }
    }
    dl++, dr++;
    ans.push_back(pre);
  }
  if (!flag) {
    cout << "Yes\n";
    cout << ans;
    return;
  }
  tl = l, tr = r;
  dl = dr = flag = 0;
  cur = tcur;
  pre = 'T';
  ans = "";
  if (tl.size()) {
    dl++, dr++;
    pre = 'L';
    tl.pop_back();
    ans.push_back('L');
  }
  while (tl.size() || tr.size()) {
    if (tr.size()) {
      if (tr.back() - dr <= cur) {
        flag = 1;
        break;
      }
    }
    if (tl.size()) {
      if (tl.back() + dl >= cur) {
        flag = 1;
        break;
      }
    }
    if (tl.size() == 0) {
      if (pre != 'R') {
        tr.pop_back();
        pre = 'R';
      } else {
        pre = 'L';
      }
    } else if (tr.size() == 0) {
      if (pre != 'L') {
        tl.pop_back();
        pre = 'L';
      } else {
        cur++;
        pre = 'D';
      }
    } else {
      if (tl.back() + dl == cur - 1) {
        if (pre != 'L') {
          tl.pop_back();
          pre = 'L';
        } else {
          cur++;
          pre = 'D';
        }
      } else {
        if (pre != 'R') {
          tr.pop_back();
          pre = 'R';
        } else {
          tl.pop_back();
          pre = 'L';
        }
      }
    }
    dl++, dr++;
    ans.push_back(pre);
  }
  if (!flag) {
    cout << "Yes\n";
    cout << ans;
    return;
  }
  cout << "No";
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int test;
  cin >> test;
  while (test--) {
    solve();
    cout << '\n';
  }
}