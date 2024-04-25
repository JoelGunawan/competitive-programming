#include <bits/stdc++.h>
using namespace std;
int main() {
    set<int> s;
    // set tidak bisa mengandung duplikat
    // operasi:
    // insert(x) -> masukkan x ke dalam set
    // erase(x) -> hapus x dari set
    // count(x) -> memeriksa apakah ada elemen itu di set atau tidak
    // lower_bound(x) -> mendapatkan iterator untuk elemen pertama yg >= x, jika elemen tersebut tidak ada,
    // maka akan mengembalikan iterator untuk "end" 
    // upper_bound(x) -> mendapatkan iterator untuk elemen pertama yg > x, jika elemen tersebut tidak ada,
    // maka akan mengembalikan iterator untuk "end" 
    // begin() -> mendapatkan iterator untuk elemen dengan nilai paling kecil
    // end() -> mendapatkan iterator untuk "end"
    // find(x) -> mendapatkan iterator untuk elemen tersebut, jika elemen tersebut tidak ada,
    // maka akan mengembalikan iterator untuk "end" 
    s.insert(3);
    s.insert(5);
    s.insert(2);
    s.insert(2);
    // {2, 3, 5}
    // {it2, it3, it5, end}
    cout << *s.begin() << endl; // 2
    cout << *++s.begin() << endl; // 3
    cout << *++(++s.begin()) << endl; // 5
    cout << *--s.end() << endl; // 5
    /*
    // iterator
    auto it = s.find(3);
    s.erase(it);
    // 2, 5
    cout << *s.lower_bound(3) << endl;
    cout << *s.begin() << endl;
    bool x = s.find(3) == s.end();
    cout << x << endl;
    bool y = s.find(2) == s.end();
    cout << y << endl;
    */
}