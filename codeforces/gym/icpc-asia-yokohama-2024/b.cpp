#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    ll cur = 0;
    for (int i = 60; i >= 0; i--) {
        if (getbit(a, i) == getbit(b, i)) {
            cur += getbit(a, i) * bit(i);
        } else {
            for (int j = i - 1; j >= 0; j--) {
              if (getbit(a, j)) {
                if (cur + bit(j) == a) {
                  cur += bit(j);
                } else {
                  cur += bit(j + 1);
                }
                break;
              }
            }
            break;
        }
    }

    cout << cur << "\n";
}
