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
bool solve(string a, string b) {
    if(a.size() > b.size())
        return 0;
    for(int i = 0; i <= b.size() - a.size(); ++i) {
        // b[i.. i + a.size()] == a
        // kita cek semua digit diluar range sekarang, apakah ada 0
        // kalo tidak ada 0 berarti memenuhi
        if(b.substr(i, a.size()) == a) {
            //cout << a << " " << b << endl;
            bool ans = 1;
            for(int j = 0; j < i; ++j)
                if(b[j] == '0')
                    ans = 0;
            for(int j = i + a.size(); j < b.size(); ++j)
                if(b[j] == '0')
                    ans = 0;
            return ans;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x, y;
    cin >> x >> y;
    string a, b;
    a = bitset<70>(x).to_string();
    b = bitset<70>(y).to_string();
    while(a[0] == '0')
        a.erase(0, 1);
    while(b[0] == '0')
        b.erase(0, 1);
    // 111110000111
    // akhir 1, operasi 0 dan operasi 1
    // 111110000111 -> 1111100001110 -> 111000011111
    // 111110000111 -> 1111100001111 -> 111100001111
    // kesimpulan kita boleh balik, tambahkan 0 ke kiri dan kanan
    // a belakangnya 1
    // a dalam representasi biner itu dalam bentuk 1b1 -> bisa
    // jika reverse a dalam representasi biner itu dalam bentuk 1b1 -> bisa
    // akhir 0, operasi 0 dan operasi 1
    // 100 -> 1000 -> 0001 -> 1
    // 1010 -> 10100 -> 00101 -> 101
    // 10110 -> 101100 -> 001101 -> 1101
    // operasi pertama -> operasi 0 atau operasi 1
    // kita cek manual dua"nya itu dalam bentuk 1b1 atau bukan
    // kalo iya, kita output yes
    // kalo bukan, kita output no
    if(x == y) {
        cout << "YES" << endl;
        return 0;
    }
    string c = a;
    while(c.back() == '0')
        c.pop_back();
    string d = a + '1';
    string e = c, f = d;
    reverse(e.begin(), e.end());
    reverse(f.begin(), f.end());
    if(solve(c, b) || solve(d, b) || solve(e, b) || solve(f, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}