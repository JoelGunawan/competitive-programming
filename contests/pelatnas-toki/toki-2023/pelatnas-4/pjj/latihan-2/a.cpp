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
#define ull unsigned long long
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
    ull a[n + 1];
    for(int i = 1; i <= n; ++i) {
        // 2 sama, 2 lainnya harus sama
        cin >> a[i];
    }
    if(n > 100)
        cout << "Dapat" << endl, exit(0);
    // beda cuman 1 bit antar sebelah
    // coba tiap sebelahan, dia pasti hasil xornya cuman 1 doang

    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            for(int l = j + 1; l <= n; ++l) {
                for(int k = l + 1; k <= n; ++k) {
                    //cout << (a[i] ^ a[j] ^ a[l] ^ a[k]) << endl;
                    if((a[i] ^ a[j] ^ a[l] ^ a[k]) == 0)
                        cout << "Dapat" << endl, exit(0);
                }
            }
        }
    }
    cout << "Tidak" << endl;
    return 0;
}