#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> generate_primes(ll max) {
    // O(NlogN)
    // sieve of eratosthenes
    bool prime[max + 1];
    // set semua prime ke 1
    // memset hati" pakenya
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i <= max; ++i) {
        if(prime[i]) {
            for(ll j = 1ll * i * i; j <= max; j += i) {
                prime[j] = 0;
            }
        }
    }
    vector<ll> ret;
    for(int i = 2; i <= max; ++i) {
        if(prime[i])
            ret.push_back(i);
    }
    return ret;
}
bool is_prime(ll number) {
    for(int i = 2; i <= sqrt(number); ++i) {
        if(number % i == 0)
            return false;
    }
    return true;
}
// pake bilangan prima
bool is_prime_fast(ll number, vector<ll> &primes) {
    for(int i = 0; i < primes.size() && primes[i] <= sqrt(number); ++i) {
        // cout << "TEST" << endl;
        if(number % primes[i] == 0) {
            // cout << primes[i] << endl;
            return false;
        }
    }
    return true;
}
int main() {
    // cout << "TEST" << endl;
    vector<ll> v = generate_primes(1e5);
    // cout << "GENERATE" << endl;
    if(is_prime_fast(1e9 + 13, v))
        cout << "PRIME" << endl;
    else
        cout << "NOT PRIME" << endl;
}