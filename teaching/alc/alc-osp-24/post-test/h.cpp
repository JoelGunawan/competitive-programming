#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, k;
    cin >> x >> k;
    string s = to_string(x); // mengubah x jadi string
    if(s.size() > k || x % 10 == 0) {
        cout << -1 << endl;
    }
    else if(k >= 2 * x) {
        // x 0000 x
        // jumlah digit k
        // yg udah terpakai: 2 * jumlah digit x -> 2 * s.size()
        // yg belum terpakai: k - 2 * s.size()
        cout << x;
        for(int i = 0; i < k - 2 * s.size(); ++i) {
            cout << 0;
        }
        cout << x << endl;
    }
    else if(k == s.size()) {
        cout << x << endl;
    }
    else {
        long long tmp = 1;
        for(int i = 1; i < k; ++i)
            tmp *= 10;
        long long res = (long long)ceil((double) tmp / x) * x;
        if(res % 10 == 0) {
            res += x;
        }
        cout << res << endl;
    }
}