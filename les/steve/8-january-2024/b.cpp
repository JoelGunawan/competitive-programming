#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        // i = 1 (baris pertama) j = n - 1 ... 0
        // i = 2 (baris kedua) j = n - 1 ... 0
        // i = 3 (baris ketiga) j = n - 1 ... 0
        // mis. n = 3
        // i = 1, baris pertama j = 2, 1, 0
        // i = 2, baris pertama j = 2, 1, 0
        // i = 3, baris pertama j = 2, 1, 0
        cout << "DEBUG " << i << endl;
        for(int j = n - 1; j >= 0; --j) {
            //cout << " ";
            // (1)
            cout << "DEBUG1 " << i << " " << j << endl;
        }
        for(int j = 1; j <= i; ++j) {
            //cout << "*";
            // (2)
            cout << "DEBUG2 " << i << " " << j << endl;
        }
        // (3)
        cout << endl;
    }
}