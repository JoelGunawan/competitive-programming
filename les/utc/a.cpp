#include <bits/stdc++.h>
using namespace std;
int a[] = {4, 7, 9};
bool vis[3];
// cur -> 1 2 3
// cur -> 1 3 2
// ...
int cur[3];
// x -> "depth/kedalaman", berapa yang udah di brute force
void f(int x) {
  if(x == 3) {
    for(int i = 0; i < x; ++i)
      cout << cur[i] << " ";
    cout << endl;
  }
  else {
    // brute force langkah selanjutnya
    for(int i = 0; i < 3; ++i) {
      if(!vis[i]) {
        vis[i] = 1;
        cur[x] = a[i];
        f(x + 1);
        vis[i] = 0;
      }
    }
  }
}
void g(int x) {
  if(x == 3) {
    for(int i = 0; i < x; ++i)
      cout << cur[i] << " ";
    cout << endl;
  }
  else {
    // brute force langkah selanjutnya
    for(int i = 0; i < 3; ++i) {
        cur[x] = a[i];
        g(x + 1);
    }
  }
}
void h(int x) {
  if(x == 3) {
    for(int i = 0; i < x; ++i) {
      if(cur[i])
        cout << i << " ";
    }
    cout << endl;
  }
  else {
    for(int i = 0; i < 2; ++i) {
      cur[x] = i;
      h(x + 1);
    }
  }
}
int pow(int a, int b) {
  if(b == 0)
    return 1;
  else {
    int tmp = pow(a, b / 2);
    tmp = tmp * tmp;
    if(b % 2 == 1)
      return tmp * a;
    else
      return tmp;
  }
}
int main() {
  // dua cara utama complete search
  //g(0);
  // 1 << 5 -> 2^5
  h(0);
}