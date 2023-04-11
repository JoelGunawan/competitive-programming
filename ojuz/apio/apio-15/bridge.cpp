#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, n;
    cin >> k >> n;
    if(k == 1) {
        ll base = 0;
        vector<int> a;
        for(int i = 1; i <= n; ++i) {
            char x, y;
            int e, f;
            cin >> x >> e >> y >> f;
            if(x != y)
                a.push_back(e), a.push_back(f);
            else
                base += abs(e - f);
        }
        // k = 1 -> cari sum r suffix dan l prefix
        // pakai prefix sum bisa
        // k = 2 -> cari sum r suffix dan l prefix
        // untuk mid cari l tengah dan r tengah
        // l tengah r tengah -> choose closest
        // semakin tinggi r -> semakin dikit l tengah
        // obs 1: k = 1 -> always choose median?
        // no?
        // karena based on l and r juga
        // median belum tentu optimal karena
        // l l r r 
        // l r l r
        // eh median pasti optimal???
        int med = a.size() / 2;
        if(a.size() == 0)
            cout << base << endl, exit(0);
        sort(a.begin(), a.end());
        ll res = 0;
        for(int i = 0; i < a.size(); ++i) {
            res += abs(a[i] - a[med]);
        }
        //cout << a[med] << endl;
        //cout << base << " " << res << " " << a.size() / 2 << endl;
        cout << res + base + a.size() / 2 << endl;
    }
    else {
        // kalo dibagi jadi 2 pivot
        // berarti ada kasus ke kiri dan ke kanan
        // jika l di idx1 dan r di idx2
        // maka jika <= (l + r) / 2 pergi ke kiri
        // jika >= (l + r) / 2 pergi ke kanan
        // (l + r) / 2 -> median
        // take 1st quarter and 3rd quarter?
        // coba aja???
        // gaboleh karena dia harus pake bridge yang sama
        // for given l find opt r
        // try O(N^2)
        // jika L di kiri i, maka pasti L dan R nya pivot ke bridge 1
        // jika L di kanan i, maka ada 2 kemungkinan, dia pake bridge 1 atau pake bridge 2
        // lebih optimal pakai bridge 2 jika idx2 - r <= l - idx1
        // kalo idx2 - r kurang dr 0, ambil jadi 0 aja
        // bs diubah jadi idx2 + idx1 <= l + r
        // sort by r + l di vector
        // nanti di kanan certain index pake
        ll base = 0;
        vector<pair<long long, pair<int, int>>> a;
        vector<pair<int, int>> b;
        vector<int> c;
        for(int i = 0; i < n; ++i) {
            char x, y;
            int e, f;
            cin >> x >> e >> y >> f;
            if(x == y)
                base += abs(e - f);
            else
                a.push_back(make_pair(e + f, make_pair(min(e, f), max(e, f)))), b.push_back(make_pair(min(e, f), max(e, f))),
                c.push_back(e), c.push_back(f);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        reverse(b.begin(), b.end());
        // process a terus lanjutkan process b
        if(b.size() <= 2) {
            for(auto i : b)
                base += i.second - i.first;
            cout << base << endl;
            return 0;
        }
        int pr = 0, prpos = 0;
        ll cum = 0;
        for(int i = 0; i < c.size(); ++i) {
            // mis bridge 1 di i, maka bridge 2 nya di kanan bridge 1
            cum += (c[i] - prpos) * 1ll * pr;
            prpos = c[i];
            while(b.size() && b.back().first == c[i]) {
                ++pr;
                base += abs(b.back().first - b.back().second);
                b.pop_back();
                // ini perlu dihilangkan dr a
            }
            // semakin besar l + r, semakin mungkin dipake bridge 2
            for(int j = i + 1; j < c.size(); ++j) {
                // a nanti gunanya buat binser, kita mau tau berapa yang diambil sama bridge 1, berapa yang diambil sama bridge 2
                // first in a harus <= j + i buat pake bridge 2
                // sisa pake bridge 1
                
            }
        }
    }
    // a itu isinya pair
    // bridge: semua yg dikiri lewat bridge semua yg di kanan lewat bridge
    // bridge at index idx
    // k = 1
    // r < idx -> 2 * (idx - r) penalty
    // l > idx -> 2 * (l - idx) penalty
    // coba tiap idx1 hitung r < idx dan l > idx pakai segment tree/bit
    // bridge at index idx1, idx2; idx1 < idx2
    // r < idx1 -> 2 * (idx1 - r) penalty
    // l > idx2 -> 2 * (l - idx2) penalty
    // l <= idx1 and r >= idx1 aman
    // l <= idx2 and r >= idx2 aman
    // l > idx1 and r < idx2
    // penalty -> pilih terkecil antara l - idx1 dan idx2 - r terus kali 2
    // apakah bisa ternary search???
    // teori sum ambil median???
}