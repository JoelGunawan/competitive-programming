#include <bits/stdc++.h>
using namespace std;
int f(int a, int b) {
    if(a == 0 || b == 0)
        return 1;
    int lsb; ++b;
    for(int i = 30; i >= 0; --i) {
        if(a & (1 << i)) {
            b = b / (1 << (i + 1)) * (1 << i) + min(b % (1 << (i + 1)), 1 << i);
            lsb = i;
        }
    }
    return ceil(b / (double)(1 << lsb));
}
int find(int a, int b, int d) {
    if(b == 0)
        return f(a, d);
    else
        return f(a, d) - f(a, b - 1) + (!(bool)(a & b) && !bool(a & (b - 1)));
}
int main() {
    int n, m, q, a, b, c, d;
    cin >> n >> m >> q;
    while(q--) {
        cin >> a >> b >> c >> d;
        cout << find(b, a, c) + find(a, b, d) - !bool(a & b) << endl;
    }
    return 0;
}