#include <bits/stdc++.h>
using namespace std;
int fpb(int x, int y) {
    if(x == 0)
        return y;
    else if(y == 0)
        return x;
    else {
        return fpb(y, x % y);
    }
}
int main() {
    int x, y;
    cin >> x >> y;
    cout << fpb(x, y) << endl;
}