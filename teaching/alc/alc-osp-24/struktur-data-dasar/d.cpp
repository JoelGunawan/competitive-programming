#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    // seperti antrian
    // operasi:
    // push(e) -> masukkan di akhir
    // pop() -> keluarkan di awal
    // front() -> akses awal queue
    // size() -> banyak elemen di dalam queue
    q.push(5);
    // q = {5}
    q.push(4);
    // q = {5, 4}
    q.push(7);
    // q = {5, 4, 7}
    cout << q.front() << endl; // A
    q.pop();
    // q = {4, 7}
    cout << q.front() << endl; // B
    q.pop();
    // q = {7}
    cout << q.front() << endl; // C
    q.push(3);
    // q = {7, 3}
    cout << q.front() << endl; // D
}