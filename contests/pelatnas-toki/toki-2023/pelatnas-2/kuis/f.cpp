// aku nyalain do not disturb :D
#include <bits/stdc++.h>
#define endl "\n"
#define ins insert
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // ideas:
    // use persistent ds (hampir pasti pakai)
    // masalah: gmn cara determine closest active sekarang
    // ide 1: pakai segment tree, karena stack tidak bisa
    // observasi: cari maximum closest that is active
    // transisi active ribet karena bisa transisi n / 2 element
    // 
    // coba pahami soal by sampah sub 1, 2
    // sub 1, find closest active manually, nanti ubah activenya jg manual
    int n, sub;
    cin >> n >> sub;
    int val[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for(int i = n; i >= 1; --i) {
        // berarti 
        // cari closest undo yang memenuhi
        // closest di kanan < 0
        // bisa pakai binser on segtree
        // try to find closest undo to the right
        // kalo ga ada, berarti elemen ini berdiri sendiri di dsunya
        // coba buat sub 3, last element yg nyala
        // from the last number, cari closest undonya dmn
        // segtree based on val
        // simpan
        // gimana kalo semuanya ternyata yg kt pilih inactive?
        // masalah lanjutan:
        // obs:
        // cari index ter depan yang bs
        // nanti index ter depan di update jadi 0
        // closest <= yg aktif
        // how?
        // problem -> determine activenya
        // nanti tiap elemen bs dipasangin ke lainnya yg lebih besar
        // cari closest active -> easier said than done
        // updating active -> nightmare fuel
        // active -> constantly decreasing up to edit point
    }
}