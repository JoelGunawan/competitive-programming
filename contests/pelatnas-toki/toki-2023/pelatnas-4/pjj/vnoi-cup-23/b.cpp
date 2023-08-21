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
    int p[n + 1], q[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> p[i];
    for(int i = 1; i <= n; ++i)
        cin >> q[i];
    // one type of table, one type of monitor
    // berapa unique values, berarti buat sampe segitu
    int unq = 0;
    int mon[n + 1], tab[n + 1];
    memset(mon, -1, sizeof(mon));
    memset(tab, -1, sizeof(tab));
    for(int i = 1; i <= n; ++i) {
        if(mon[p[i]] == -1 && tab[q[i]] == -1)
            mon[p[i]] = q[i], tab[q[i]] = p[i], ++unq;
        else {
            if(mon[p[i]] != q[i]) {
                cout << "NO" << endl;
                return 0;
            }
            if(tab[q[i]] != p[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    int a[n + 1], b[n + 1];
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
    int done = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[p[i]] == -1) {
            a[p[i]] = done + 1;
            b[q[i]] = unq - done;
            ++done;
        }
    }
    int e = unq, f = unq;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == -1)
            a[i] = ++e;
        if(b[i] == -1)
            b[i] = ++f;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; ++i)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}