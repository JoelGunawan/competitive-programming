// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string a = "osn", b = "2022";
    // penjumlahan string, string digabung
    cout << a + b << endl;
    // jika idx terlalu besar, bisa RTE/WA/dan semacamnya
    // fungsi substr
    cout << b.substr(1, 3) << endl;;
    int idx = 1;
    a.erase(idx, 1);
    b.erase(idx, 2);
    // fungsi erase
    // str.erase(idx_awal, banyak yang mau dihapus)
    cout << a << " " << b << endl;
    // string ditambah karakter
    a += 'a';
    cout << a << endl;
    // manipulasi karakter
    // ascii
    cout << (char)('a' + 4) << endl;
    // a...z -> a
    // pakai modulo
    // di modulo 26
    // z + 15
    // ('z' - 'a' + 15) % 26 + 'a';
    cout << (char)(('z' - 'a' + 15) % 26 + 'a') << endl;
    // palindrome
    // palindrome -> sebuah bilangan/string/tergantung soal yang kalo dibaca dari depan itu sama dengan kalo dibaca dari belakang
    // katak -> katak palindrome
    // palindrome -> emordnilap bukan palindrome
    // 150 -> 051 bukan palindrome
    // 100050001 -> 100050001 -> palindrome
    string x;
    cin >> x;
    bool is_palindrome = 1;
    for(int i = 0; i < x.size() / 2; ++i) {
        if(x[i] != x[x.size() - i - 1])
            is_palindrome = 0;
    }
    cout << (int)is_palindrome << endl;
    return 0;
}