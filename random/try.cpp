#include <bits/stdc++.h>
using namespace std;
int caterpie(int n) {
    int r = 0;
    for (int i = 1; i <= 2*n*n; i = i * 2)
        r++;
    return r * n - 1;
}

int eevee(int n) {
    int r;
    int s = 0;
    for (int q = 0; q <= 2 * n; q += 2)
        s = s + q;
    s *= 8;
    for (r = s / 4; r > 4; r--)
        s--;
    return r * s;
}

int pidgey(int n) {
    int r = 0;
    int q = 4*n;
    for (int i = 0; i < q; i = i+4)
        for (int j = 0; j < i; j++)
            r += 2;
    return r;
}

int main() {
  cout << caterpie(4) << endl;
}