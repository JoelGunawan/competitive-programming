// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
vector<int> sieve(ll limit) {
    bool arr[limit + 1];
    memset(arr, 1, sizeof(arr));
    arr[0] = 0, arr[1] = 0;
    for(int i = 2; i <= limit; ++i) {
        if(arr[i]) {
            for(int j = 2 * i; j <= limit; j += i)
                arr[j] = 0;
        }
    }
    vector<int> res;
    for(int i = 2; i <= limit; ++i)
        if(arr[i])
            res.pb(i);
    return res;
}

vector<int> primes = sieve(1e5);
void tc() {
    int n, m;
    cin >> n >> m;
    for(int i = n; i <= m; ++i) {
        bool prime = 1;
        for(int j = 0; primes[j] * primes[j] <= i; ++j)
            if(i % primes[j] == 0)
                prime = 0;
        if(prime && i != 1)
            cout << i << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}