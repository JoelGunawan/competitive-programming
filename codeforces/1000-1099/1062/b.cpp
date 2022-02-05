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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int max_pow = 0, n, num = 1;
    vector<int> pow;
    cin >> n;
    if(n == 1)
        cout << "1 0" << endl, exit(0);
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            num *= i;
            int tmp = 0;
            while(n % i == 0)
                ++tmp, n /= i;
            max_pow = max(max_pow, tmp);
            pow.pb(tmp);
        }
    }
    if(n > 1)
        max_pow = max(max_pow, 1), pow.pb(1), num *= n;
    sort(pow.begin(), pow.end());
    int target = pow.back();
    while((target&-target) != target)
        target += target&-target;
    bool changed = 0;
    for(int i = 0; i < pow.size(); ++i) {
        if(pow[i] != target)
            changed = 1;
    }
    int div = 0;
    while(target > 1)
        ++div, target >>= 1;
    cout << num << " " << changed + div << endl;
    return 0;
}