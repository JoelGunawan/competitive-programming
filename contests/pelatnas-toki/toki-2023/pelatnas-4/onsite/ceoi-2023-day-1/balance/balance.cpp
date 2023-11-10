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
    int a[n + 1][s + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= s; ++j)
            cin >> a[i][j];
    }
    int cnt[t + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= s; ++j)
            ++cnt[a[i][j]];
    }
    int lcnt[t + 1];
    memset(lcnt, 0, sizeof(lcnt));
    // kalo misal ada yg g sesuai, just pick any terus swap sama yg di kanan
    for(int i = 1; i <= n; ++i) {
        ++lcnt[a[i][1]];
    }
    while(true) {
        for(int i = 1; i <= n; ++i) {
            // kalo sekarang kelebihan
            // kecuali sekarang
            if(lcnt[a[i][1]] > (cnt[a[i][1]] / 2 + (cnt[a[i][1]] & 1)))
                --lcnt[a[i][1]], swap(a[i][1], a[i][2]), ++lcnt[a[i][1]];
        }
        bool valid = 1;
        for(int i = 1; i <= t; ++i) {
            if(lcnt[a[i][1]] != cnt[a[i][1]] / 2)
                valid = 0;
        }
        if(valid)
            break;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= s; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}