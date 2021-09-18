#include <bits/stdc++.h>
using namespace std;
vector<int> generate_primes(int number) {
    bool a[number]; memset(a, 1, sizeof(a)), a[0] = 0, a[1] = 0;
    for(int i = 2; i <= number / 2; ++i)
        if(a[i]) {
            for(int j = 2 * i; j <= number; j += i)
                a[j] = 0;
        }
    vector<int> res;
    for(int i = 0; i <= number; ++i)
        if(a[i])
            res.push_back(i);
    return res;
}
int main() {
    int t;
    cin >> t;
    vector<int> primes = generate_primes(500);
    vector<bool> nearly_prime(1001, 0);
    for(int i = 0; i < primes.size(); ++i)
        for(int j = i; j < primes.size() && primes[i] * primes[j] <= 1000; ++j)
            nearly_prime[primes[i] * primes[j]] = 1;
    while(t--) {
        int a, b, res = 0;
        cin >> a >> b;
        for(int i = a; i <= b; ++i)
            if(nearly_prime[i])
                ++res;
        cout << res << endl;
    }
}