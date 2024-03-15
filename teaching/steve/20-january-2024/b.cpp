#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    int q;
    cin >> q;
    while(q--) {
        char p, q;
        int x, y;
        cin >> p >> x >> q >> y;
        if(p == 'A') {
            if(q == 'A')
                swap(a[x], a[y]);
            else {           
                swap(a[x], b[y]);
            }
        }
        else {
            // p == 'B'
            if(q == 'A')
                swap(b[x], a[y]);
            else
                swap(b[x], b[y]);
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; ++i)
        cout << b[i] << " ";
    cout << endl;
}