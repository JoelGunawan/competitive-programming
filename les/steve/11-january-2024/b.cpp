#include <bits/stdc++.h>
using namespace std;
// tipe_data_kembalian nama_fungsi/subprogram(parameter) {
//
//
// }

int sum(int n) {
    int x = 0;
    for(int i = 1; i <= n; ++i) {
        x += i;
    }
    cout << x << endl;
    return x;
}

int max(int x, int y) {
    if(x > y) {
        return x;
    }
    else {
        return y;
    }
}
// gaperlu return value -> pake void
void print(int n) {
    cout << n << endl;
    // gaperlu return value?
}

int main() {
    // 1 + 2 + ... + N
    // biar ga penuh, gmau hitung di program utama
    int y = sum(5);
    cout << y << endl;
    cout << max(3, 7) << endl;
    print(3);
}