#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
char a[] = {'^', '<', 'v', '>'};
int main() {
  int n;
  cin >> n;
  // (2n + 1) * (2n + 1) box
  // U, L, D, R
  int posx = n + 1, posy = n + 1;
  vector<vector<int>> direction(2 * n + 5, vector<int>(2 * n + 5, -1));
  auto get_input = [&](int dir) -> void {
    cout << a[dir] << endl;
    if(dir == 0)
      --posx;
    else if(dir == 1)
      --posy;
    else if(dir == 2)
      ++posx;
    else
      ++posy;
    char x;
    cin >> x;
    if(x == 'G')
      exit(0);
    if(x == '^')
      direction[posx][posy] = 0;
    else if(x == '<')
      direction[posx][posy] = 1;
    else if(x == 'v')
      direction[posx][posy] = 2;
    else  
      direction[posx][posy] = 3;
  };
  if((2 * n + 1) * (2 * n + 1) <= 10000) {
    while(posx > 1) {
      --posx;
      get_input(0);
    }
    while(posy > 1) {
      --posy;
      get_input(1);
    }
    for(int i = 0; i < 2 * n + 1; ++i) {
      // for each row
      if(i & 1) {
        // go left
        for(int j = 1; j < 2 * n + 1; ++j) {
          get_input(1);
        }
      }
      else {
        // go right
        for(int j = 1; j < 2 * n + 1; ++j) {
          get_input(3);
        }
      }
      get_input(2);
    }
  }
  int iter = 0;
  int minx = 1, miny = 1, maxx = 2 * n + 1, maxy = 2 * n + 1;
  // first iteration, check left/right
  direction[posx][posy] = 0;
  // right
  for(int i = 0; i < n; ++i) {
    get_input(3);
  }
  // up
  get_input(0);
  // left
  for(int i = 0; i < 2 * n; ++i) {
    get_input(1);
  }
  // down
  get_input(2);
  //right
  for(int i = 0; i < n; ++i) {
    get_input(3);
  }
  int cntup = 0, cntdown = 0;
  for(int i = 1; i <= 2 * n + 1; ++i) {
    if(direction[posx][i] == 0)
      ++cntup;
    else if(direction[posx][i] == 2)
      ++cntdown;
  }
  if(cntup > cntdown) {
    maxx = posx - 1;
  }
  else {
    minx = posx;
  }
  while((maxx - minx) * (maxy - miny) > 400) {
    if (iter % 2 == 0) {
      // first iter, divide by y
      // divide into 2
      int startx, starty = (miny + maxy) / 2;
      if(abs(maxx - posx) < abs(minx - posx)) {
        startx = maxx;
      }
      else {
        startx = minx;
      }
      // go to start pos
      // go up
      while(posx > startx) {
        get_input(0);
      }
      // go down
      while(posx < startx) {
        get_input(2);
      }
      // go right
      while(posy < starty) {
        get_input(3);
      }
      // go left
      while(posy > starty) {
        get_input(1);
      }
      if(startx == minx) {
        // go right
        for(int i = maxx; i > minx; --i) {
          get_input(3);
        }
        // go up one
        get_input(0);
        // go left
        for(int i = minx; i < maxx; ++i) {
          get_input(1);
        }
        // go down one
        get_input(2);
        
        // go down
        for(int i = maxx; i > (maxx + minx) / 2; --i) {
          get_input(3);
        }
      }
      else {
        // go left
        for(int i = maxx; i > minx; --i) {
          get_input(1);
        }
        // go up one
        get_input(0);
        // go right
        for(int i = miny; i < maxy; ++i) {
          get_input(3);
        }
        // go down one
        get_input(2);
        
        // go left
        for(int i = maxy; i > (maxy + miny) / 2; --i) {
          get_input(1);
        }
      }
      // check x = (minx, maxx), y = (miny, posy - 1)
      int cntout = 0, cntin = 0;
      if(minx <= n + 1 && n + 1 <= maxx && miny <= n + 1 && n + 1 <= posy - 1)
        ++cntin;
      for(int i = miny; i <= posy - 1; ++i) {
        if(direction[maxx][i] == 0)
          ++cntout;
        else if(direction[maxy + 1][i] == 2)
          ++cntin;
      }
      for(int i = minx; i <= maxx; ++i) {
        if(direction[i][posy - 1] == 3)
          ++cntout;
        else if(direction[i][posy] == 1)
          ++cntin;
      }
      if(cntin > cntout) {
        // inside
        maxy = posy - 1;
      }
      else {
        // outside
        miny = posy;
      }
    } 
    else {
      // second iter, divide by x
      // divide into 2
      int startx = (maxx + minx) / 2, starty;
      if(abs(maxy - posy) < abs(miny - posy)) {
        starty = maxy;
      }
      else {
        starty = miny;
      }
      // go to start pos
      // go up
      while(posx > startx) {
        get_input(0);
      }
      // go down
      while(posx < startx) {
        get_input(2);
      }
      // go right
      while(posy < starty) {
        get_input(3);
      }
      // go left
      while(posy > starty) {
        get_input(1);
      }
      if(starty == miny) {
        // go down
        for(int i = maxy; i > miny; --i) {
          get_input(2);
        }
        // go left one
        get_input(1);
        // go up
        for(int i = miny; i < maxy; ++i) {
          get_input(0);
        }
        // go right one
        get_input(3);
        
        // go down
        for(int i = maxy; i > (maxy + miny) / 2; --i) {
          get_input(2);
        }
      }
      else {
        // go up
        for(int i = maxy; i > miny; --i) {
          get_input(0);
        }
        // go left one
        get_input(1);
        // go down
        for(int i = miny; i < maxy; ++i) {
          get_input(2);
        }
        // go right one
        get_input(3);
        
        // go up
        for(int i = maxy; i > (maxy + miny) / 2; --i) {
          get_input(0);
        }
      }
      // check x = (minx, posx - 1), y = (miny, maxy)
      int cntout = 0, cntin = 0;
      if(minx <= n + 1 && n + 1 <= posx - 1 && miny <= n + 1 && n + 1 <= maxy)
        ++cntin;
      for(int i = minx; i <= posx - 1; ++i) {
        if(direction[i][maxy] == 0)
          ++cntout;
        else if(direction[i][maxy + 1] == 2)
          ++cntin;
      }
      for(int i = miny; i <= maxy; ++i) {
        if(direction[posx - 1][i] == 3)
          ++cntout;
        else if(direction[posx][i] == 1)
          ++cntin;
      }
      if(cntin > cntout) {
        // inside
        maxx = posx - 1;
      }
      else {
        // outside
        minx = posx;
      }
    }

    ++iter;
  }
}