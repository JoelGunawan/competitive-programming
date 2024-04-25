#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> a;
    // Kompleksitas Waktu: O(...)
    // T1 -> string
    // T2 -> string
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        string x, y;
        cin >> x >> y;
        a[x] = y;
    }
    for(int i = 0; i < q; ++i) {
        string x;
        cin >> x;
        if(a[x] == "")
            cout << "NIHIL" << endl;
        else
            cout << a[x] << endl;
    }
}