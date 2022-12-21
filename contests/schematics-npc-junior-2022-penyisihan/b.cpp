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
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    int pr[2][s2.size()];
    memset(pr, 0, sizeof(0));
    for(int i = 1; i < s2.size(); ++i)
        pr[0][i] = 1e9;
    for(int i = 0; i < s2.size(); ++i)
        pr[1][i] = 0;
    for(int i = 1; i < s1.size(); ++i) {
        for(int j = 1; j < s2.size(); ++j) {
            // case erase -> ambil dr prev dengan plus 1
            pr[i & 1][j] = pr[!(i & 1)][j] + 1;
            // case ganti -> matching i dengan j, ambil prev
            if(s1[i] == s2[j]) {
                if(j != 1 || i == 1)
                    pr[i & 1][j] = min(pr[i & 1][j], pr[!(i & 1)][j - 1]);
            }
            else {
                if(j != 1 || i == 1)
                    pr[i & 1][j] = min(pr[i & 1][j], pr[!(i & 1)][j - 1] + 1);
            }
            // case insert -> ambil dari sebelumnya, tambah 1
            // bisa jadi i ini belum dipakai sama sekali, sehingga tidak bisa melakukan case insert langsung
            // harus ambil dari case ganti atau case erase, tidak boleh dari 0
            if(j != 1)
                pr[i & 1][j] = min(pr[i & 1][j], pr[i & 1][j - 1] + 1);
        }
    }
    cout << pr[(s1.size() - 1) & 1][s2.size() - 1];
    return 0;
}