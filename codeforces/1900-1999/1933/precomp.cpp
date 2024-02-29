// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
  // code every 5x5 square
  for(int i = 0; i < (1 << 25); ++i) {
      // if valid output
      bool a[5][5];
      for(int j = 0; j < 25; ++j) {
          if((1 << j) & i)
              a[j / 5][j % 5] = 1;
          else
              a[j / 5][j % 5] = 0;
      }
      bool valid = 1;
      for(int i = 0; i < 5; ++i) {
          for(int j = 0; j < 5; ++j) {
              if(j <= 2)
                  valid &= !((a[i][j] == a[i][j + 1]) && (a[i][j] == a[i][j + 2]));
              if(i <= 2)
                  valid &= !((a[i][j] == a[i + 1][j]) && (a[i][j] == a[i + 2][j]));
              if(i <= 2 && j <= 2) {
                  valid &= !((a[i][j] == a[i + 1][j + 1]) && a[i][j] == a[i + 2][j + 2]);
                  valid &= !(a[i][j + 2] == a[i + 1][j + 1] && a[i][j + 2] == a[i + 2][j]);
              }
              if(!valid)
                  break;
          }
      }
      if(valid) {
          cout << "{";
          for(int i = 0; i < 4; ++i) {
            cout << "{";
              for(int j = 0; j < 4; ++j) {
                cout << a[i][j];
                if(j != 3)
                    cout << ",";
                else
                    cout << "}";
              }
              if(i != 3)
                cout << "," << endl;
          }
          cout << "},";
          cout << endl;
      }
  }
  return 0;
}