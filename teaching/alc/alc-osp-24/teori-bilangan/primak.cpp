#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // sieve di sini
    vector<int> primes;
    int lim = 1e6 + 5;
    bool prime[lim];
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i < lim; ++i) {
        if(prime[i]) {
            for(int j = 2 * i; j < lim; j += i) {
                prime[j] = 0;
            }
        }
    }
    for(int i = 2; i < lim; ++i) {
        if(prime[i])    
            primes.push_back(i);
    }
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        // bilangan prima ke-x?
        // sieve di sini
        // 20000 * sieve
        // 20000 * 10^6
        // 2 * 10^4 * 10^6
        // 2 * 10^10
        // kurang lebih komputer dalam 1 detik bisa menjalankan -> 10^8 sampai 5 * 10^8 operasi
        // dikurangi 1 karena x yg diberi 1 based, tapi array primes 0 based
        cout << primes[x - 1] << endl;
    }
}