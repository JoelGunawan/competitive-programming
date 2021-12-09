#include <bits/stdc++.h>
#define endl "\n"
#define sqr(a) (a) * (a)
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << sqr(max(2 * min(a, b), max(a, b))) << endl;
    }
    return 0;
}