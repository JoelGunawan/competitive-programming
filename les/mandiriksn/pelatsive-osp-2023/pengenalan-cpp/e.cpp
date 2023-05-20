#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    // if/else if
    // trik menarik if/else if
    // bisa jadi kasus udh "masuk" ke sebelumnya, jadi gperlu dipikirin lagi
    // kasus tertentu, else if terakhir bs dijadikan else aja (tapi klo mau aman ttp jadiin else if)
    if(n <= 9) {
        cout << "satuan" << endl;
    }
    else if(n <= 99) {
        cout << "puluhan" << endl;
    }
    else if(n <= 999) {
        cout << "ratusan" << endl;
    }
    else if(n <= 9999) {
        cout << "ribuan" << endl;
    }
    else {
        cout << "puluhribuan" << endl;
    }
    // selalu bisa: else -> else if (buang")
    // tdk selalu bisa: else if -> else
    // kapan bisa? kasus else if pasti true (dibuang aja gapapa)
}