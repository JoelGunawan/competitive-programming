#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    multiset<int> s;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        // cari yg >= x di barisan sebelumnya
        // jika tidak ada...
        if(s.lower_bound(x) == s.end()) {
            // buat barisan baru
            s.insert(x);
        }
        else {
            // yg lama nilainya diganti yang baru
            s.erase(s.lower_bound(x));
            s.insert(x);
        }
    }
    cout << s.size() << endl;
}