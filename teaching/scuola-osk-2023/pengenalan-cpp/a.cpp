#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < i; ++j) {
            cout << " ";
        }
        for(int j = i; j < 5; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; ++i) {
        // 1 -> true
        // 0 -> false
        // sqrt(i) -> square root(i) -> akar(i)
        bool prime = true;
        for(int j = 2; j <= sqrt(i); ++j) {
            // i mod j = 0
            // i mod j -> sisa pembagian i dengan j
            if(i % j == 0) {
                prime = false;
            }
        }
        // j =< 5 -> tidak boleh
        // j <= 5
        // && -> dan/and
        // || -> atau/or
        if(prime && i != 1)
            cout << i << " ";
    }
    cout << endl;
    // ini merupakan tes
    // i++ -> i = i + 1 (di dalam for loop sama aja)
    // i-- -> i = i - 1
    // j++/++j -> sama
    // j--/--j -> sama
    // a = a * j
    int a  = 5;
    for(int j = 1; j <= 4; ++j) {
        a = a * j;
    }
    cout << a << endl;
    return 0;
}