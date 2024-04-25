#include <bits/stdc++.h>
using namespace std;
int main() {
    // stack<T>, T -> tipe data
    vector<int> s;
    stack<string> t;
    // operasi:
    // push(e) -> masukkan elemen di paling atas
    // pop() -> keluarkan elemen yang ada di paling atas
    // top() -> akses elemen yang ada di paling atas
    // size() -> ukuran stack (banyak elemen di dalam stack)
    // implementasi pake vektor:
    // stack -> vector
    // push(e) -> push_back(e)
    // pop() -> pop_back()
    // top() -> back()
    // size() -> size()
    // s = {}
    s.push_back(3);
    // s = {3}
    s.push_back(2);
    // s = {3, 2}
    s.push_back(4);
    // s = {3, 2, 4}
    cout << s.back() << endl; // A -> 4
    s.pop_back();
    // s = {3, 2}
    s.pop_back();
    // s = {3}
    cout << s.back() << endl; // B -> 3
    s.push_back(10);
    // s = {3, 10}
    cout << s.back() << endl; // C -> 10
    cout << s[0] << endl;
}