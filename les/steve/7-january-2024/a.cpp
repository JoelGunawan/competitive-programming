#include <bits/stdc++.h>
using namespace std;
int main() {
    // contoh sintaks for loop
    for(int i = 1; i <= 5; ++i) { 

    }
    // contoh sintaks while loop
    while(false) {

    }

    int a;
    cin >> a;
    int mn = 1e9, mx = -1e9;
    for(int i = 1; i <= a; ++i) {
        int b;
        cin >> b;
        // proses mn sm mx
        mn = min(mn, b);
        mx = max(mx, b);
    }
    
}