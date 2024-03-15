#include <bits/stdc++.h>
using namespace std;
int main() {
    // int n;
    // cin >> n;
    // bilangan positif -> > 0
    // bilangan genap -> % 2 == 0
    // if(n % 2 == 0) {
    //     if(n > 0) {
    //         cout << n << endl;
    //     }
    // }

    // if(n % 2 == 0 && n > 0) {
    //     cout << n << endl;
    // }
    // input desimal, tentuin bilangan bulat?
    // tricky question?
    double n;
    cin >> n;
    // c++ -> round()
    // precision error?
    // 1.000000
    // 1.000000000002352
    // 2 bilangan desimal sama?
    // if()
    // abs(x) -> nilai absolut
    // round(x) -> ke bil. bulat terdekat
    // negatif -> positif
    // positif -> positif
    // 1e-7 (sebuah angka yg sangat kecil)
    if(abs(n - round(n)) < 1e-10) {
        // bilangan bulat
        cout << round(n) << endl;
    }
    else {
        // bukan bilangan bulat
        cout << false << endl;
    }
}