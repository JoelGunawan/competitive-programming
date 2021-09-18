#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, l;
        cin >> a >> b >> l;
        cout << a + max(l - 2000, 0) / 100 * b << endl;
    }
    return 0;
}