#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        // first coba langsung ke tempatnya, ke ujung kiri, atau ke ujung kanan
        // coba terus 3 kali, kalo gabisa ke ujung kiri/kanan/ga sampe tempat ans no
        int l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        if(a == b) {
            cout << 0 << endl;
            continue;
        }
        bool ans = 1;
        if(abs(a - b) >= x) {
            cout << 1 << endl;
            continue;
        }
        else {
            // coba cari yang terjauh dr b
            if(abs(l - b) >= abs(r - b)) {
                // prefer l
                if(abs(l - a) >= x)
                    a = l;
                else if(abs(r - a) >= x)
                    a = r;
                else
                    ans = 0;
            }
            else {
                // prefer r
                if(abs(r - a) >= x)
                    a = r;
                else if(abs(l - a) >= x)
                    a = l;
                else
                    ans = 0;
            }
        }
        if(!ans) {
            cout << -1 << endl;
            continue;
        }
        if(abs(a - b) >= x) {
            cout << 2 << endl;
            continue;
        }
        else {
            if(a == l)
                a = r;
            else
                a = l;
        }
        if(abs(a - b) >= x)
            cout << 3 << endl;
        else
            cout << -1 << endl;
    }
}