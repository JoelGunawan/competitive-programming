#include <bits/stdc++.h>
using namespace std;
// void -> tidak ada nilai yang mau di return
bool f(int a) {
    // 5
    if(a == 1)
        return false;
    // 
    for(int i = 2; i <= sqrt(a); ++i) {
        // i = 2
        // i = 3
        if(a % i == 0) {
            return false;
        }   
    }
    // a = 5
    return true;
}

int main() {
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; ++i) {
        if(f(i)) {
            cout << i << " ";
        }
    }
    return 0;
}