#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        pair<long long, long long> a = {x2 - x1, y2 - y1}, b = {x3 - x1, y3 - y1};
        long long cross_product = a.first * b.second - a.second * b.first;
        if(cross_product == 0)
            cout << "TOUCH" << endl;
        else if(cross_product < 0)
            cout << "RIGHT" << endl;
        else
            cout << "LEFT" << endl;
    }
}