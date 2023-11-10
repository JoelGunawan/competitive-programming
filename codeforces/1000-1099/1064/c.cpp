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
    // yg odd, 1 boleh dipake di tengah
    // sisanya pasti dibuang aja
    // even buat bentuk:
    // abcdeffedcba
    // step ini dibuat berlevel"
    // jadi klo gada yg odd, lgsg bagi 2
    // nanti pake rekursi aja, krn observasinya selalu kebagi 2 minimal, jadi cmn nlogn
    int n;
    string s;
    cin >> n >> s;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i)
        ++cnt[s[i] - 'a'];
    string res = "";
    for(int i = 0; i < 26; ++i)
        for(int j = 0; j < cnt[i]; ++j)
            res += (char)(i + 'a');
    cout << res << endl;
    return 0;
}