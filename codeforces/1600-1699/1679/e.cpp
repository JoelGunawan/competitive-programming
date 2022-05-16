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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ada 2 kategori karakter
    // dead char
    // alive char
    // dead char -> question mark gabisa diubah jadi ini
    // alive char -> question mark bisa diubah jadi ini
    // maintain question_mark_cnt for each
    // 2^17 * n
    // how to update question mark cnt fast
    // or precompute more efficiently
    // use trie precomp?
    
    return 0;
}