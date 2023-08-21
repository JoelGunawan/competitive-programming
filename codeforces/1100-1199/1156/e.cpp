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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int p[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    // simpan stack bigger than cur di kiri
    // terus nnti simpan sebuah counter untuk cek 
    // pop stack -> gabungin ke range yg skrg (paling akhir)
    // max tambah sebanyak stack element
    // coba sorting setelah di pop (di merge O(N))
    // problem -> klo tidak "hoki" tiap segment bisa di merge N kali?
    // kalo misal jumlah stack sedikit, bs brute force aja per stack
    // kalo misal jumlah stack banyak, bs memo
    // obs: 
    // klo misal stack sizenya kecil (<= sqrt) memo ke var global posisinya
    // klo misal stack size besar (> sqrt) manual tiap stack 
    // dsu merging? -> gabisa krn klo size besar yg dirubah, maka var globalnya gabisa berubah
    // size besar berubah -> ubah pakai padding aja
    // size kecil berubah -> ubah manual semua, tambahin ke var global
    int nl[n + 1], nr[n + 1];
    fill(nl, nl + n + 1, 0);
    fill(nr, nr + n + 1, n + 1);
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        while(v.size() && p[v.back()] < p[i])
            v.pop_back();
        if(v.size())
            nl[i] = v.back();
        v.pb(i);
    }
    v.clear();
    for(int i = n; i >= 1; --i) {
        while(v.size() && p[v.back()] < p[i])
            v.pop_back();
        if(v.size())
            nr[i] = v.back();
        v.pb(i);
    }
    int pos[n + 1];
    for(int i = 1; i <= n; ++i) 
        pos[p[i]] = i;
    int res = 0;
    for(int i = 1; i <= n; ++i) {
        if(abs(nl[i] - i) <= abs(nr[i] - i)) {
            // choose to iterate left
            for(int j = nl[i] + 1; j < i; ++j) {
                if(pos[p[i] - p[j]] > i && pos[p[i] - p[j]] < nr[i])
                    ++res;
            }
        }
        else {
            for(int j = i + 1; j < nr[i]; ++j) {
                if(pos[p[i] - p[j]] > nl[i] && pos[p[i] - p[j]] < i)
                    ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}