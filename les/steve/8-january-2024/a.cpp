#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    // setiap kelipatan ke-k aku tdk print
    // break -> stop for loop
    // continue -> skip sisa code untuk loop ini
    // exit(0); // stop seluruh program

    for(int i = 1; i <= n; ++i) {
        cout << "TEST " << i << endl;
        if(i % k == 0)
            continue;
        cout << i << endl;
    }
    cout << endl;
}