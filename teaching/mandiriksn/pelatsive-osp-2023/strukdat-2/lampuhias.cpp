#include <bits/stdc++.h>
#define lll __int128_t
// int -> -2^31...2^31 - 1
// long long -> -2^63... 2^63 - 1
// __int128_t -> -2^127 ... 2^127 - 1
// int128 overflow -> gatau
#define ll long long
using namespace std;
lll lcm(lll a, __int128_t b) {
    return a * (b / __gcd(a, b));
}
int main() {
    // nyala bersama -> waktu kpk
    long long p, q, r;
    cin >> p >> q >> r;
    // mis p: 10^9, q = p - 1, r - q - 1
    // KPK = 10^9*(10^9-1)*(10^9-2)/2 -> 10^27
    // -> ll dan integer overflow
    // tipe data apa???
    __int128_t kpk = lcm(p, lcm(q, r));
    int qe;
    cin >> qe;
    for(int i = 0; i < qe; ++i) {
        long long x;
        cin >> x;
        if(x % kpk == 0)
            cout << "YA" << endl;
        else
            cout << "TIDAK" << endl;
    }
}