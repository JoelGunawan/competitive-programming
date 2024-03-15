#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 17;
struct segment_tree {
    int a[2 * lim], arr_size;
    // vektor
    // multiset
    // set
    // map
    // dll
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        idx += arr_size;
        a[idx] = val;
        idx >>= 1;
        bool b = 0;
        while(idx != 0) {
            if(b == 0)
                a[idx] = a[2 * idx] | a[2 * idx + 1];
            else
                a[idx] = a[2 * idx] ^ a[2 * idx + 1];
            b = !b;
            idx >>= 1;
        }
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    segment_tree segtree;
    segtree.arr_size = 1 << n;
    for(int i = 0; i < 1 << n; ++i) {
        int x;
        cin >> x;
        segtree.update(i, x);
    }
    for(int i = 0; i < m; ++i) {
        int p, b;
        cin >> p >> b;
        --p;
        segtree.update(p, b);
        cout << segtree.a[1] << endl;
    }
}