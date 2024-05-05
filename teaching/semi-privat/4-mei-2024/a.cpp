#include <bits/stdc++.h>
using namespace std;
int main() {
    multiset<int> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        // jika tidak ada elemen yg >= x di a, maka if ini dijalankan
        if(a.lower_bound(x) == a.end()) {
            a.insert(x);
        }
        // jika ada elemen yg >= x di a, maka else dijalankan
        else {
            // yg >= x di a kita hapus yg paling kecil, kita ganti dengan x
            a.erase(a.lower_bound(x));
            a.insert(x);
        }
    }
    cout << a.size() << endl;
}