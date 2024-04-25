#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> a;
    // Kompleksitas Waktu: O(nlogn + qlogn)
    // O(N + Q)
    // O(NlogN + QlogN)
    // T1 -> string
    // T2 -> string
    int n, q;
    cin >> n >> q;
    // n kali
    // note:
    // operasi map: O(logN), N -> banyak elemen di map
    for(int i = 0; i < n; ++i) {
        string x, y; // n kali * 1
        cin >> x >> y; // n kali * 1
        a[x] = y; // n kali * logn
    }
    for(int i = 0; i < q; ++i) {
        string x; // q kali * 1
        cin >> x; // q kali * 1
        if(a[x] == "") // q kali * logn
            cout << "NIHIL" << endl;
        else
            cout << a[x] << endl;
    }
}