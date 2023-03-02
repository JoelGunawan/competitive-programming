#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int pr[17][n + 1];
    memset(pr, 0, sizeof(pr));
    vector<int> prime_occur[(int)1e5 + 5];
    for(int i = 1; i <= n; ++i) {
        vector<int> primes;
        int tmp = a[i];
        for(int j = 2; j <= sqrt(tmp); ++j) {
            if(tmp % j == 0) {
                while(tmp % j == 0)
                    tmp /= j;
                primes.push_back(j);
            }
        }
        int l = pr[0][i - 1];
        if(tmp > 1)
            primes.push_back(tmp);
        for(auto j : primes) {
            if(prime_occur[j].size())
                l = max(l, prime_occur[j].back());
            prime_occur[j].push_back(i);
        }
        pr[0][i] = l;
    }
    for(int i = 1; i <= 16; ++i) {
        for(int j = 1; j <= n; ++j) {
            //cout << i << " " << j << " " << pr[i - 1][j] << " ";
            pr[i][j] = pr[i - 1][pr[i - 1][j]];
            //cout << pr[i][j] << endl;
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        int res = 0;
        for(int i = 16; i >= 0; --i) {
            //cout << l << " " << r << " " << pr[i][r] << endl;
            if(pr[i][r] >= l)
                res += 1 << i, r = pr[i][r];
        }
        cout << res + 1 << endl;
    }
}