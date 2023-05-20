#include <bits/stdc++.h>
using namespace std;
int main() {
    int p, q, r, n;
    cin >> p >> q >> r >> n;
    for(int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        if(x % p == 0 && x % q == 0 && x % r == 0) {
            cout << "YA" << endl;
        }
        else
            cout << "TIDAK" << endl;
    }
}