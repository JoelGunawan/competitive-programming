#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
ll mod = 1e9 + 7;
 
int main()
{
    int n, x, pos;
    cin >> n >> x >> pos;
    int smaller = x - 1, larger = n - x, l = 0, r = n, up = 0, down = 0;
    // ada x - 1 posisi less than (le) x dan n - x posisi greater than or equal to (geq) x
    // kita bagi 2 bagian ini, sebenarnya kita cukup tracing path yang akan dilewati selama binser
    // dan di tempat" tersebut, kita harus pilih antara le/geq agar jawaban yang diberikan sesuai
    // untuk mencari ini, dapat dilakukan semacam simulasi binser agar kita tahu perlu pakai le/geq x
    // di akhir, kita pilih dahulu untuk posisi yang penting ada berapa cara
    // kemudian untuk sisanya pilih terserah (pakai faktorial saja)
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(mid <= pos)
        {
            l = mid + 1;
            if(mid != pos) ++down;
        }
        else
        {
            r = mid;
            ++up;
        }
        --n;
    }
    ll res = 1;
    for(ll i = larger; i > larger - up; --i) res = (res * i) % mod;
    for(ll i = smaller; i > smaller - down; --i) res = (res * i) % mod;
    for(ll i = 2; i <= n; ++i) res = (res * i) % mod;
    cout << res << endl;
    return 0;
}