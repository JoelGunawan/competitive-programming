#include <bits/stdc++.h>
using namespace std;
int main() {
    // use pending update?
    // count of 0 inside a segment
    // tiap perubahan -> update tiap parent -> HLD
    // how to update tiap parent?
    // atau tiap parent yang query anaknya
    // masalah: colornya bs banyak
    // klo update tiap parent pake HLD, anggep aja update inside a 2d segment tree/using map bisa O(log^2)
    // problem -> can't find count
    // solution -> use map, trus nanti tinggal count aja !!!
    // update count of every parent, lazy segment update bs lgsg -1 for everything
    // implement HLD gmn yah dah lama :"D logic aja deh
    cout << sqrt(60000) << endl;
    cout << 10000 / 216.0 << endl;
    cout << 47 * 47 / 6.0 / 6.0 << endl;
    cout << 47 * 47 / 6.0 << endl;
    cout << 47 * 47 << endl;
    cout << 60000 / 36.0 << endl;
    cout << 1666 / 216.0 << endl;
    cout << 60000 / 216.0 / 216.0 << endl;
    cout << 7 * 36 << endl;
    cout << 9978 / 216 << endl;
    cout << 9978 / 216 << endl;
}