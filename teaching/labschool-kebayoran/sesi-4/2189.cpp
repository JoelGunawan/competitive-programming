#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
void tc() {
    pair<long long, long long> a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    b.x -= a.x; c.x -= a.x;
    b.y -= a.y; c.y -= a.y;
    long long cross_product = b.x * c.y - b.y * c.x;
    if(cross_product == 0)
        cout << "TOUCH" << endl;
    else if(cross_product > 0)
        cout << "LEFT" << endl;
    else
        cout << "RIGHT" << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--)
        tc();
}