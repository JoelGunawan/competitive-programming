#include <bits/stdc++.h>
using namespace std;
int main() {
    deque<int> d;
    // operasi:
    // push_back() -> masukkan di belakang
    // pop_back() -> keluarkan di belakang
    // push_front() -> masukkan di depan (beda dengan vector)
    // pop_front() -> keluarkan di depan (beda dengan vector)
    // front() -> akses elemen paling depan
    // back() -> akses elemen paling belakang
    // size()
    // bisa diakses menggunakan indeks (seperti vector)
    d.push_back(0);
    // d = {0}
    d.push_back(1);
    // d = {0, 1}
    d.push_back(2);
    // d = {0, 1, 2}
    cout << d[1] << endl;
    d.push_front(5);
    // d = {5, 0, 1, 2}
    d[2] = 4;
    // d = {5, 0, 4, 2}
    for(auto x : d)
        cout << x << " ";
    cout << endl;
    d.pop_back();
    // d = {5, 0, 4}
    for(auto x : d)
        cout << x << " ";
    cout << endl;
    d.pop_front();
    // d = {0, 4}
    for(auto x : d)
        cout << x << " ";
    cout << endl;
}