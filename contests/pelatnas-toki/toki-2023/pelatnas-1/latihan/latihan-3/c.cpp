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
const int lim = 1e5 + 5;
struct disjoint_set {
    int head[lim], sz[lim];
    set<int> a[lim], b[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    void merge(int x, int y, bool enem) {
        if(sz[fh(x)] < sz[fh(y)])
            swap(x, y);
        int orix = x, oriy = y;
        x = fh(x), y = fh(y);
        sz[x] += sz[y];
        head[y] = x;
        if((a[y].find(oriy) != a[y].end()) != enem) {
            if(a[x].find(orix) != a[x].end()) {
                for(auto i : a[y])
                    a[x].ins(i);
                for(auto i : b[y])
                    b[x].ins(i);
            }
            else {
                for(auto i : a[y])
                    b[x].ins(i);
                for(auto i : b[y])
                    a[x].ins(i);
            }
        }
        else {
            if(a[x].find(orix) != a[x].end()) {
                for(auto i : a[y])
                    b[x].ins(i);
                for(auto i : b[y])
                    a[x].ins(i);
            }
            else {
                for(auto i : a[y])
                    a[x].ins(i);
                for(auto i : b[y])
                    b[x].ins(i);
            }
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    disjoint_set dsu;
    for(int i = 0; i < n; ++i)
        dsu.a[i].ins(i);
    for(;q--;) {
        int c, x, y;
        cin >> c >> x >> y;
        //cout << dsu.fh(x) << " " << dsu.fh(y) << endl;
        //cout << (int)(dsu.a[dsu.fh(x)].find(x) != dsu.a[dsu.fh(x)].end()) << " " << (int)(dsu.a[dsu.fh(y)].find(y) != dsu.a[dsu.fh(y)].end()) << endl;
        if(c == 1) {
            // setfriends
            if(dsu.fh(x) != dsu.fh(y)) {
                dsu.merge(x, y, 0);
                cout << 1 << endl;
            }
            else {
                int h = dsu.fh(x);
                if((dsu.a[h].find(x) != dsu.a[h].end()) == (dsu.a[h].find(y) != dsu.a[h].end()))
                    cout << 1 << endl;
                else
                    cout << -1 << endl;
            }
        }
        else if(c == 2) {
            // set enem
            if(dsu.fh(x) != dsu.fh(y)) {
                dsu.merge(x, y, 1);
                cout << 1 << endl;
            }
            else {
                int h = dsu.fh(x);
                if((dsu.a[h].find(x) != dsu.a[h].end()) != (dsu.a[h].find(y) != dsu.a[h].end()))
                    cout << 1 << endl;
                else
                    cout << -1 << endl;
            }
        }
        else if(c == 3) {
            // arefriend
            if(dsu.fh(x) != dsu.fh(y))
                cout << 0 << endl;
            else {
                int h = dsu.fh(x);
                cout << (int)((dsu.a[h].find(x) != dsu.a[h].end()) == (dsu.a[h].find(y) != dsu.a[h].end())) << endl;
            }
        }
        else {
            if(dsu.fh(x) != dsu.fh(y))
                cout << 0 << endl;
            else {
                int h = dsu.fh(x);
                cout << (int)((dsu.a[h].find(x) != dsu.a[h].end()) != (dsu.a[h].find(y) != dsu.a[h].end())) << endl;
            }
        }
    }
    return 0;
}