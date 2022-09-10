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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int b = 0, w = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'B')
            ++b;
        else
            ++w;
    }
    if(b & 1 && w & 1) {
        cout << -1 << endl;
    }
    else if(b & 1) {
        // jadi b semua
        // cari semua w
        // geser supaya kelompok berpasangan
        vector<int> operasi;
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] == 'W' && s[i + 1] == 'W') {
                s[i] = 'B';
                s[i + 1] = 'B';
                operasi.pb(i + 1);
            }
            else if(s[i] == 'W' && s[i + 1] == 'B') {
                swap(s[i], s[i + 1]);
                operasi.pb(i + 1);
            }
        }
        cout << operasi.size() << endl;
        for(auto i : operasi)
            cout << i << " ";
        cout << endl;
    }
    else {
        // b genap w ganjil
        // b genap w genap
        // jadi w semua
        vector<int> operasi;
        for(int i = 0; i < n - 1; ++i) {
            if(s[i] == 'B' && s[i + 1] == 'B') {
                s[i] = 'W';
                s[i + 1] = 'W';
                operasi.pb(i + 1);
            }
            else if(s[i] == 'B' && s[i + 1] == 'W') {
                swap(s[i], s[i + 1]);
                operasi.pb(i + 1);
            }
        }
        cout << operasi.size() << endl;
        for(auto i : operasi)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}