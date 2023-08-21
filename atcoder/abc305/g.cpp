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
int mod = 998244353;
struct obj {
    int size;
    ll pref[1 << 6], suff[1 << 6];
    obj() {
        size = 0;
        memset(pref, 0, sizeof(pref));
        memset(suff, 0, sizeof(suff));
    }
};
obj combine(obj a, obj b) {

}
obj powmod(int b) {

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // bisa gabungkan 2 L, R, terus nanti tinggal cek di zona penggabungan apakah ada substring s di sana?
    ll n; int m;
    cin >> n >> m;
    string a[m];
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    // generate substring of length 6
    // later try every combination, check how many are true
    // total combinations -> 2^6 * 2^6 -> can check using trie
    // maintain start and end
    // kalo ada yg kurang, berarti nanti tambahkan sama kali 1?
    // yes
    
    return 0;
}