#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    bool prime[n + 5];
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i <= n; ++i) {
        if(prime[i]) {
            for(int j = i * 2; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(prime[i])
            cout << i << " ";
    }
    cout << endl;
}