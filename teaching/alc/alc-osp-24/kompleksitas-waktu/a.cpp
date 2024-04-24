#include <bits/stdc++.h>
using namespace std;
int main() {
    // tips utk menentukan kompleksitas tanpa tahu secara langsung
    // - spam cout/print semua bagian dari kode kalian
    // - kodenya jalan berapa kali? berapa line yg di proses?
    int n;
    cin >> n;
    // O(N)
    for(int i = 0; i < n; ++i) {
        cout << i << endl;
    }
    // O(N^2)
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << i << " " << j << endl;
        }
    }
    // O(N^3)
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++i) {
            for(int k = 0; k < n; ++k) {
                cout << i << " " << j << " " << k << endl;
            }
        }
    }

    vector<int> a(n, 0);
    // O(NlogN)
    sort(a.begin(), a.end()); // fungsi sort punya kompleksitas NlogN
    // n kali
    // O(NlogN * N)
    // O(N^2logN)
    for(int i = 0; i < n; ++i) {
        // jalan n kali
        sort(a.begin(), a.end()); // nlogn
        // ...
        /// ..
    }
    
    // trik utk logN
    // kalo ada yg dibagi/dikali hingga capai bilangan tertentu -> O(logN)
    int x = n;
    // O(logN)
    while(x > 0) {
        x = x / 2;
    }
    x = 1;
    // O(logN)
    while(x < n) {
        x = 3 * x;
    }
}