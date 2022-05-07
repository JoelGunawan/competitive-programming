#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, c, n, q, b;
    cin >> r >> c >> n >> q >> b;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    // ada node
    // tiap node ada urutan internal di dalamnya (jadi semacam deque gitu)
    // terus tiap node nanti akan ada L dan Rnya
    // nanti di dsu
    // untuk support operasi up/down butuh cara pecahin dsunya
    
    return 0;
}