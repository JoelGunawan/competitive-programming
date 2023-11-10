// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int query(int x, int y) {
    cout << x << " " << y << endl;
    string s;
    cin >> s;
    return s == "white";
}
int main() {
    // buat 20 di x axis, terus 10 di y axis (atau similar)
    int n;
    cin >> n;
    int ctr = 1e9 / 2;
    if(n <= 20) {
        // make along the x axis only
        int l = 0, r = 1e9;
        for(int i = 0; i < n; ++i) {
            int mid = (l + r) / 2;
            int c = query(mid, ctr);
            if(c)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << (l + r) / 2 << " " << 0 << " " << (l + r) / 2 << " " << 1 << endl;
    }
    else {
        int l = 0, r = 1e9;
        for(int i = 0; i < 20; ++i) {
            int mid = (l + r) / 2;
            int c = query(mid, 0);
            if(c)
                l = mid + 1;
            else
                r = mid - 1;
        }
        int cl = l, cr = r;
        ctr = (l + r) / 2;
        l = 0, r = 1e9;
        for(int i = 0; i < n - 20; ++i) {
            int mid = (l + r) / 2;
            int c = query(ctr, mid);
            if(!c)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << cl + 1 << " " << 0 << " " << ctr << " " << l + 1 << endl;
    }
    return 0;
}