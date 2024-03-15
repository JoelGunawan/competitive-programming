#include <bits/stdc++.h>
using namespace std;
int f(int n) {
    // base case (case yg non rekursif)
    if(n <= 1) {
        // output 1
        return 1;
    }
    else {
        return f(n - 1) + f(n - 2);
    }
}
int gcd(int a, int b) {
    // base case
    if(b == 0) {
        return a;
    }
    // inductive step (induksi)
    else {
        // dibalik supaya b lebih kecil
        return gcd(b, a % b);
    }
}
int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    cout << gcd(12, 8) << endl;
}