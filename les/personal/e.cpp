#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int limit) {
    bool prime[limit + 1];
    memset(prime, 1, sizeof(prime));
    // true -> bilangan prima
    // false -> bukan bilangan prima
    prime[0] = 0, prime[1] = 0;
    for(int i = 2; i <= limit; ++i) {
        if(prime[i]) {
            for(int j = 2; j * i <= limit; ++j)
                prime[j * i] = 0;
        }
    }
    vector<int> ans;
    for(int i = 2; i <= limit; ++i)
        if(prime[i])
            ans.push_back(i);
    return ans;
}
int main() {
    int number;
    cin >> number;
    for(int i = 2; i <= sqrt(number); ++i) {
        if(number % i == 0) {
            cout << "NOT PRIME" << endl;
            return 0;
        }
    }
    cout << "PRIME" << endl;
    vector<int> x = sieve(sqrt(number));
    bool prime = 1;
    for(int i = 0; i < x.size() && x[i] <= sqrt(number); ++i) {
        if(number % x[i] == 0) {
            cout << x[i] << endl;
            prime = 0;
        }
    }
    cout << (int)prime << endl;
    // apakah 10^9+9 prima?
    // cek sampai akar 10^9+9
    // cari pembagi prima aja
}