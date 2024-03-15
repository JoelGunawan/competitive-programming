#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
long long cross_product(pair<long long, long long> a, pair<long long, long long> b) {
    return a.x * b.y - b.x * a.y;
}
pair<long long, long long> sub(pair<long long, long long> a, pair<long long, long long> b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
bool intersect(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
    long long dres = cross_product(sub(b, a), sub(d, a)), cres = cross_product(sub(b, a), sub(c, a));
    if(dres < 0)
        dres = -1;
    else if(dres > 0)
        dres = 1;
    if(cres < 0)
        cres = -1;
    else if(cres > 0)
        cres = 1;
    long long ares = cross_product(sub(c, d), sub(a, d)), bres = cross_product(sub(d, c), sub(b, d));
    if(ares < 0)
        ares = -1;
    else if(ares > 0)
        ares = 1;
    if(bres < 0)
        bres = -1;
    else if(bres > 0)
        bres = 1;
    return ares == -bres && cres == -dres;
}
int main() {
    int n, m;
    cin >> n >> m;
    pair<long long, long long> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    pair<long long, long long> b[m];
    for(int i = 0; i < m; ++i)
        cin >> b[i].x >> b[i].y;
    for(int i = 0; i < m; ++i) {
        pair<long long, long long> uji = {b[i].x + 2e9 + 2, b[i].y + 2e9 + 3};
        int cnt = 0;
        bool boundary = 0;
        for(int j = 0; j < n; ++j) {
            if(cross_product(sub(a[(j + 1) % n], a[j]), sub(b[i], a[j])) == 0 && min(a[j], a[(j + 1) % n]) <= b[i] && max(a[j], a[(j + 1) % n]) >= b[i]) {
                boundary = 1;
            }
            else if(intersect(b[i], uji, a[j], a[(j + 1) % n]))
                ++cnt;
        }
        if(boundary)
            cout << "BOUNDARY" << endl;
        else if(cnt & 1)
            cout << "INSIDE" << endl;
        else
            cout << "OUTSIDE" << endl;
    }
}