#include <bits/stdc++.h>
using namespace std;
const int lim = 1 << 17;
struct segment_tree {
    int a[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        bool state = 1;
        idx += lim;
        a[idx] = val;
        while(idx) {
            idx >>= 1;
            if(state) {
                a[idx] = a[2 * idx] | a[2 * idx + 1];
                //cout << idx << " " << a[idx] << endl;
            }
            else {
                a[idx] = a[2 * idx] ^ a[2 * idx + 1];
                //cout << idx << " " << a[idx] << endl;
            }
            state ^= 1;
        }
    }
};
int main() {
    segment_tree seg;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 1 << n; ++i) {
        int x;
        cin >> x;
        seg.update(i, x);
    }
    for(int i = 0; i < m; ++i) {
        int k, u;
        cin >> k >> u;
        seg.update(k - 1, u);
        cout << seg.a[1] << endl;
    }
}