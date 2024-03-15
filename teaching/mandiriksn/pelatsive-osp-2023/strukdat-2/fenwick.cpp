#include <bits/stdc++.h>
using namespace std;
const int lim = 2e5 + 5;
struct fenwick {
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    // 1...n
    int query(int idx) {
        int res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
// fenwick -> update O(logn), query O(logn)
// RSQ, tp bs jauh lbh cepet dr segtree dgn kompleksitas sama
int main() {

}