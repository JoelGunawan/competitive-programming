// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // urutan ga ngaruh
    // ijin ke toilet :D
    // mau isi minum :")
    // lock yang dipindah yang mana tidak pengaruh
    // yang penting hanya pin yang dipilih saja
    // kemungkinan pin dipilih ada 16
    // berarti dari 16 operasi, operasi apa yang kita pakai supaya kembali ke 0
    // perhatikan bahwa operasi di 1 pasti menghasilkan kelipatan C
    // ijin ke toilet :D
    // objective: jadikan 2, 4, 6, 8 sama
    // jadikan 2 sama dengan 4
    // proses: while(a[2] != a[4])
    int mod;
    cin >> mod;
    int a[10];
    for(int i = 0; i < 3; ++i)
        for(int j = 1; j <= 3; ++j)
            cin >> a[i * 3 + j];
    int cnt = 0;
    while(a[2] != a[4]) {
        ++cnt;
        ++a[2], ++a[3], ++a[5], ++a[6], ++a[8], ++a[9];
        for(int i = 1; i <= 9; ++i)
            a[i] %= mod;
    }
    vector<vector<int>> operations;
    // b, d
    if(cnt > 0) {
        operations.pb({0, 1, 0, 1, 3, cnt});
    }
    cnt = 0;
    while(a[2] != a[6]) {
        ++cnt;
        ++a[1], ++a[2], ++a[4], ++a[5], ++a[7], ++a[8];
        for(int i = 1; i <= 9; ++i)
            a[i] %= mod;
    }
    // a, c
    if(cnt > 0) {
        operations.pb({1, 0, 1, 0, 1, cnt});
    }
    cnt = 0;
    while(a[2] != a[8]) {
        ++cnt;
        for(int i = 1; i <= 6; ++i)
            ++a[i];
        for(int i = 1; i <= 9; ++i)
            a[i] %= mod;
    }
    // a, b
    if(cnt > 0) {
        operations.pb({1, 1, 0, 0, 1, cnt});
    }
    cnt = 0;
    // a and then d
    while(a[2] != a[5]) {
        ++a[1], ++a[2], ++a[4], ++a[5], ++a[6], ++a[8], ++a[9];
        ++a[5];
        ++cnt;
        for(int i = 1; i <= 9; ++i)
            a[i] %= mod;
    }
    if(cnt > 0) {
        operations.pb({1, 0, 0, 0, 1, cnt});
        operations.pb({0, 0, 0, 1, 9, cnt});
    }
    cnt = 0;
    while(a[2] != a[1])
        ++a[1], a[1] %= mod, ++cnt;
    if(cnt > 0) {
        operations.pb({0, 0, 0, 0, 1, cnt});
    }
    cnt = 0;
    while(a[2] != a[3])
        ++a[3], a[3] %= mod, ++cnt;
    if(cnt > 0) {
        operations.pb({0, 0, 0, 0, 3, cnt});
    }
    cnt = 0;
    while(a[2] != a[7])
        ++a[7], a[7] %= mod, ++cnt;
    if(cnt > 0) {
        operations.pb({0, 0, 0, 0, 7, cnt});
    }
    cnt = 0;
    while(a[2] != a[9])
        ++a[9], a[9] %= mod, ++cnt;
    if(cnt > 0) {
        operations.pb({0, 0, 0, 0, 9, cnt});
    }
    cnt = 0;
    while(a[2] != 0)
        ++a[2], ++cnt, a[2] %= mod;
    if(cnt > 0) {
        operations.pb({1, 1, 1, 1, 1, cnt});
    }
    cout << "YES" << endl;
    cout << operations.size() << endl;
    for(auto i : operations) {
        for(auto j : i) 
            cout << j << " ";
        cout << endl;
    }
    return 0;
}