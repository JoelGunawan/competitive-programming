#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i)
        cin >> b[i];
    // mau coba utk setiap angka b apa dia dipindah ke a?
    // mengiterasi setiap subhimpunan/subset
    for(int i = 0; i < (1 << m); ++i) {
        vector<int> idx;
        for(int j = 0; j < m; ++j) {
            if((1 << j) & i) {
                idx.push_back(j);
            }
        }
        bool dipindah[m];
        memset(dipindah, 0, sizeof(dipindah));
        int min_pindah = 1e9;
        for(auto x : idx) {
            min_pindah = min(min_pindah, b[x]);
            dipindah[x] = 1;
        }
        bool valid = 1;
        for(int j = 0; j < m; ++j) {
            if(!dipindah[j] && b[j] >= min_pindah) {
                // bukan pemindahan yg valid
                valid = 0;
            }
        }
        // dipindah semua
        if(idx.size() == m) 
            valid = 0;
        if(valid) {
            long long jumlah_a = 0, jumlah_b = 0;
            int cnta = 0, cntb = 0;
            for(auto x : a)
                jumlah_a += x, ++cnta;
            for(int i = 0; i < m; ++i) {
                if(dipindah[i])
                    jumlah_a += b[i], ++cnta;
                else
                    jumlah_b += b[i], ++cntb;
            }
            if(jumlah_a / (double)cnta > jumlah_b / (double)cntb) {
                cout << jumlah_a / (double)cnta << " " << jumlah_b / (double)cntb << endl;
                cout << "subhimpunan:" << endl;
                for(auto x : idx) {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
}