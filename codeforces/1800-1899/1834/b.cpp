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
void tc() {
    string a, b;
    cin >> a >> b;
    // selalu min/max aja
    // buat 2 string supaya bisa min/max
    while(a.size() < b.size())
        a = "0" + a;
    // cari first difference, mulai consider dr first difference aja, second difference gaperlu di consider
    // min/max, max/min strateginya?
    int fi_idx = -1;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] != b[i]) {
            fi_idx = i;
            break;
        }
    }
    if(fi_idx == -1) {
        cout << 0 << endl;
        return;
    }
    int res = b[fi_idx] - a[fi_idx];
    for(int i = fi_idx + 1; i < a.size(); ++i) {
        res += 9;
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}