#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, d;
    cin >> n >> d;
    int x;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(x == d)
            cout << i << endl, exit(0);
    }
    cout << -1 << endl;
    return 0;
}