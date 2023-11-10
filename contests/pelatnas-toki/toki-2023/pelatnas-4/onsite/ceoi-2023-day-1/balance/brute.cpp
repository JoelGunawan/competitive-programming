#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, s, t;
    cin >> n >> s >> t;
    // coba s = 2, kalo ada yg kurang atau lebih, coba swap aja satu per satu
    // kalo misal ada yg 
    // s = 2^k -> why?
    // amount of minutes doesn't matter?
    // atau harus di dnc?
    // merge -> kiri sm kanan harus jadi equal
    // bagi jadi 2 bagian dimana sum utk tiap jenis itu equal
    int a[n][s + 1];
    int cnt[t + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
        for(int j = 1; j <= s; ++j)
            cin >> a[i][j], ++cnt[a[i][j]];
    }
    for(int i = 0; i < 1 << n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i) 
                swap(a[j][1], a[j][2]);
        }
        int lcnt[t + 1];
        memset(lcnt, 0, sizeof(lcnt));
        for(int j = 0; j < n; ++j) {
            ++lcnt[a[j][1]];
        }
        for(int j = 1; j <= t; ++j) {
            //cout << "DEB " << j << " " << lcnt[j] << " " << cnt[j] - lcnt[j] << endl;
            if(abs(lcnt[j] - (cnt[j] - lcnt[j])) > 1)
                break;
            if(j == t) {
                for(int i = 0; i < n; ++i) {
                    for(int j = 1; j <= s; ++j)
                        cout << a[i][j] << " ";
                    cout << endl;
                }
                return 0;
            }
        }
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i) 
                swap(a[j][1], a[j][2]);
        }
    }
}