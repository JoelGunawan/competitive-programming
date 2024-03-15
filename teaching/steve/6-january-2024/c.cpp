#include <iostream>
using namespace std;
int main() {
    // if (kondisi) {
    //  jalanin kode    
    // }
    // else {
    //  jalanin kode
    // }
    // bool -> 0/1. 0 -> false, 1 -> true
    // int a, b;
    // cin >> a >> b;
    // comparison tipe data primitif
    // a == b
    // a > b
    // a >= b
    // a < b
    // a <= b
    // a != b
    // comparison buat string
    // a == b
    // a == b dan a <= 5
    // operator logika
    // and (&&)
    // a and b bernilai true jika a dan b true
    // or (||)
    // a or b bernilai true jika salah satu dari a atau b true
    // xor (^) \oplus
    // a xor b bernilai true jika TEPAT salah satu dari a atau b true
    // bool c = a, d = b;
    // x > y
    // x == y
    // x < y
    // else if
    int x, y;
    cin >> x >> y;
    if(x > y) {
        cout << "X LEBIH BESAR DARI Y" << endl;
    }
    else if(x == y) {
        cout << "X SAMA DENGAN Y" << endl;
    }
    else if(x < y) {
        cout << "X KURANG DARI Y" << endl;
    }
}