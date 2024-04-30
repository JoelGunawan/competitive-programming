#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    // pair.first -> angka
    // pair.second -> indeks asli
    pair<int, int> a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    // for(int i = 1; i <= n; ++i) {
    //     cout << "angka dan indeks asli " << a[i].first << " " << a[i].second << endl;
    // }
    // awal: 2 7 5 1
    // jadi: 1 2 5 7
    // simpan indeks: 4 1 3 2
    for(int i = 1; i <= n; ++i) {
        // coba pilih utk posisi i
        // 2-sum untuk x - a[i].first
        int r = n;
        for(int l = i + 1; l <= n; ++l) {
            // selama r terlalu besar, maka turunkan r
            while(r > l && (long long)a[i].first + a[l].first + a[r].first > x) {
                --r;
            }
            if(l == r) {
                break;
            }
            if(l != r && a[i].first + a[l].first + a[r].first == x) {
                // ketemu
                cout << a[i].second << " " << a[l].second << " " << a[r].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}