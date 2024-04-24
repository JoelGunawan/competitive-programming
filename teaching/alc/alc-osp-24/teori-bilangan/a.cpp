#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << "NOT PRIME" << endl;
        // return 0 di fungsi main, stop program (KHUSUS DI FUNGSI/SUBPROGRAM MAIN)
        return 0;
    }
    // sqrt(x) -> mengembalikan nilai dari akar(n)
    bool prime = true;
    // 2 .. sqrt(n)
    // 1ll * i * i -> buat hasilnya long long
    // yang penting ada 1ll nya dikali sesuatu akan otomatis jadi long long
    // 2 ... sqrt(n) -> O(sqrt(N))
    for(int i = 2; 1ll * i * i <= n; ++i) {
        if(n % i == 0) {
            // n punya faktor, maka n bukan prima
            prime = false;
        }
    }
    if(prime) {
        cout << "PRIME" << endl;
    }
    else {
        cout << "NOT PRIME" << endl;
    }
}