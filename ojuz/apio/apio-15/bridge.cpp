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
        // buat double pivot
        // nanti l di kiri pivot 1 -> ambil bridge 1
        // nanti r di kanan pivot 2 -> ambil bridge 2
        // buat suffix l dan r yg di kiri/kanan bridge 1/2 total costnya berapa
        // yang masalah -> di mid
        // dia ambil either left or right bridge depending on closest distance
        // iterate tiap kemungkinan bridge pakai two pointers
        // observasi lanjutan: optimal point membentuk kurva kuadrat (sifat yg bs ternary) -> harusnya true
        // ke kanan hingga ketemu optimal
        // ga mungkin ke kiri
        // jadi nanti O(N) aja + O(MlogM) buat sorting
        int l = 1, r = 0;
        while(l <= n) {
            
        }
    }
}