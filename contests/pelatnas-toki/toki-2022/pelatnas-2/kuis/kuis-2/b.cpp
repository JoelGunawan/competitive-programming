#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fi first
#define se second
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].se >> a[i].fi;
    sort(a, a + n);
    ll res = 0;
    multiset<int> val;
    for(int i = 0; i < n; ++i) {
        ll tmp = 1ll * a[i].fi * (n - i);
        ll cnt = val.size();
        ll tmp2 = 0;
        // bagian ini yang di optimize
        // j itu konstan
        // cnt itu dynamic
        // cnt di range update
        // dynamic cht on segment tree?
        for(auto j : val) {
            if(j <= a[i].fi)
                tmp2 = max(tmp2, 1ll * cnt * j);
            --cnt;
        }
        val.insert(a[i].se);
        res = max(res, tmp + tmp2);
    }
    cout << res << endl;
    // binser harusnya tidak bisa?
    // nilai R meningkat, jumlah orang menurun
    // nilai L meningkat, jumlah orang menurun
    // cari dimana L*x itu maksimal dimana x itu jumlah orang sekarang
    // x bisa dicari menggunakan range query
    // L kita harus cari untuk tiap nilai L
    // apakah menggunakan dp dyn cht?
    // atau dp cht biasa?
    // untuk tiap R, kita perlu cek L, tetapi kita tahu urutan persamaan yang akan ditambah
    // 1 subtask gampang
    // subtask n^2 juga relatif mudah
    // kalo l[i] = 0 semua, maka bisa pakai sweep line on r
    // kalo l[i] = r[i], kita precalculate sweep line l[i] sama r[i] sama caranya
    // jadi tinggal precalculate sweep linenya 2 kali
    //sort(a, a + n);
    //ll res = 0;
    //for(int i = 0; i < n; ++i) {
    //    res = max(res, 1ll * (n - i) * a[i].se);
    //}
    //cout << res << endl;
    // pikirkan case l[i] = r[i]
    // kalo ketemu harusnya bisa AC
    // kita cuma perlu update di l[i]
    // persamaan -> x[i] = l[i] * person_cnt[l[i]...r[i] - 1]
    // kenapa kok ada sub nsqrtn?
    // buat dp cek square root?
    // range update indeks ke i ditambah i
    // impos
    // coba instead klo kita ambil nilai l, kita simpen r yang bertabrakan -> O(n^2) x
    // buat representasi pakai garis terus di range update gradien garisnya
    // persamaan garis -> m(l[i] which is constant) * person_cnt(dynamic, need range update)
    // person_cnt itu caranya dibuat segment tree of lines
    // terus buat dp dyn cht yang bisa range update
    // sort by gradien garis terus range updatenya pake lazy segment tree
    // tiap indeks ditambah 1 orangnya terus merge dari childnya maksimalnya berapa
    // masalahnya kita bisa tambahkan person_cnt
    return 0;
}