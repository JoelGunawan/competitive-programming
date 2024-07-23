// header file
#include <bits/stdc++.h>
// pragma
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int t;
  cin >> t;
  int mod[100][100], div[100][100], mul[100][100];
  for(int i = 0; i < 100; ++i) {
    for(int j = 0; j < 100; ++j) {
      mul[i][j] = i * j;
      if(j != 0)
        mod[i][j] = i % j;
      else
        mod[i][j] = 0;
      if(j != 0)
        div[i][j] = i / j;
      else
        div[i][j] = 0;
    }
  }
  while(t--) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    int con = s.size();
    int a[con];
    for(int i = 0; i < con; ++i)
      a[i] = s[i] - '0';
    bool ans = 0;
    if(1ll * n * m > con) {
      cout << "Impossible" << endl;
      continue;
    }
    for(int i = 1; i <= 9; ++i) {
      int idx = 0;
      vector<int> b(m, -1);
      bool pos = 1;
      for(int j = 0; j < m && idx < con; ++j) {
        if(mod[a[idx]][i] == 0) {
          b[j] = div[a[idx]][i];
          ++idx;
        }
        else if(idx + 1 < con && mod[mul[a[idx]][10] + a[idx + 1]][i] == 0 && div[(mul[a[idx]][10] + a[idx + 1])][i] < 10) {
          b[j] = div[(mul[a[idx]][10] + a[idx + 1])][i];
          idx += 2;
        }
        else {
          pos = 0;
          break;
        }
      }
      for(auto x : b) {
        if(x == -1)
          pos = 0;
      }
      if(!pos) {
        continue;
      }
      vector<int> c(n, -1);
      c[0] = i;
      for(int j = 1; j < n && idx < con; ++j) {
        if(mod[a[idx]][b[0]] == 0) {
          c[j] = div[a[idx]][b[0]];
          ++idx;
        }
        else if(idx + 1 < con && mod[(mul[a[idx]][10] + a[idx + 1])][b[0]] == 0 && div[(mul[a[idx]][10] + a[idx + 1])][b[0]] < 10) {
          c[j] = div[(mul[a[idx]][10] + a[idx + 1])][b[0]];
          idx += 2;
        }
        for(int i = 1; i < b.size(); ++i) {
          if(idx < con && a[idx] == mul[b[i]][c[j]]) {
            ++idx;
          }
          else if(idx + 1 < con && mul[a[idx]][10] + a[idx + 1] == mul[b[i]][c[j]]) {
            idx += 2;
          }
          else {
            pos = 0;
            break;
          }
        }
        if(!pos)
          break;
      }
      for(auto x : c)
        if(x == -1)
          pos = 0;
      if(!pos || idx != con) {
        continue;
      }
      else {
        for(auto x : c)
          cout << x;
        cout << " ";
        for(auto x : b)
          cout << x;
        cout << endl;
        ans = 1;
        break;
      }
    }
    if(!ans)
      cout << "Impossible" << endl;
  }
  return 0;
}