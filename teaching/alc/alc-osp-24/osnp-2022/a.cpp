#include <bits/stdc++.h>
using namespace std;
int main() {
    int p, q, r;
    cin >> p >> q >> r;
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        long long t;
        cin >> t;
        if(t % p == 0 && t % q == 0 && t % r == 0) {
            cout << "YA" << endl;
        }
        else {
            cout << "TIDAK" << endl;
        }
    }
}