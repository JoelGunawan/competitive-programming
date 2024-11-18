#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;
int main() {
  // wrong approach, correct approach using BFS
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x, y, p, q;
  cin >> x >> y >> p >> q;
  // fi -> sheep
  // se -> wolves
  pair<int, int> left = mp(x, y), right = mp(0, 0);
  pair<int, int> boat = mp(0, 0);
  int res = 0;
  // first can be all wolves, sometimes this is more optimal?
  // dp state of left and dp state of right with count of moves?
  while(left.fi != 0) {
    bool move = 0;
    // cout << "LEFT " << left.fi << " " << left.se << endl;
    for(int i = min(p, left.fi); i >= 0; --i) {
      // cout << "TRY " << i << " " << left.fi - i + q << " " << left.se - (p - i) << endl;
      if(left.fi - i + q >= left.se - max(0, p - i) || i == left.fi) {
        boat.fi += i;
        left.fi -= i;
        boat.se += min(left.se, max(0, p - i));
        left.se -= min(left.se, max(0, p - i));
        move = 1;
        break;
      }
    }
    assert(left.fi >= 0 && left.se >= 0 && boat.fi >= 0 && boat.se >= 0 && right.fi >= 0 && right.se >= 0);
    // cout << "MOVING " << boat.fi << " " << boat.se << endl;
    if(!move) {
      cout << -1 << endl;
      exit(0);
    }
    else
      ++res;
    if(left.fi == 0) {
      cout << res << endl;
      exit(0);
    }
    right.se += boat.se;
    right.fi += boat.fi;
    boat.se = 0;
    boat.fi = 0;
    // leave max amount of wolves possible
    // cout << "RIGHT " << right.fi << " " << right.se << endl;
    assert(left.fi >= 0 && left.se >= 0 && boat.fi >= 0 && boat.se >= 0 && right.fi >= 0 && right.se >= 0);
    move = 0;
    for(int i = 0; i <= min(p, right.se); ++i) {
      if(right.fi + q >= right.se - i || right.fi == 0) {
        right.se -= i;
        boat.se += i;
        move = 1;
        break;
      }
    }
    assert(left.fi >= 0 && left.se >= 0 && boat.fi >= 0 && boat.se >= 0 && right.fi >= 0 && right.se >= 0);
    if(!move) {
      cout << -1 << endl;
      exit(0);
    }
    ++res;
    left.se += boat.se;
    boat.se = 0;
    assert(left.fi >= 0 && left.se >= 0 && boat.fi >= 0 && boat.se >= 0 && right.fi >= 0 && right.se >= 0);
  }
}