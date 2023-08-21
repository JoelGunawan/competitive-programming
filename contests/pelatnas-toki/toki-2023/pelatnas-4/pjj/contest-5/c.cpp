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
    // consider case tree dulu
    // mis sebuah node ada in dr 2 tempat
    // terlalu besar -> let be
    // kurang besar -> harus cek tambah seberapa
    // tambah optimal:
    // consider case 1 -> 2 -> 3 -> ... -> n
    // bs tambahin terserah yg mana supaya hasil akhirnya sesuai
    // for that case, coba mulai dr yg ori heightnya paling rendah/tinggi dulu
    // nanti coba change beberapa segment pakai height lain
    // coba update semuanya
    // for given cost, cari furthest dimana cost itu minimal
    return 0;
}