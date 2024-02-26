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
void tc() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // find all pairs such that it's gcd has no factors that is equal to a_k
    // if there exists a[i] = 1 -> output 0
    // we can divide array by it's gcd
    int gcd = 0;
    for(int i = 1; i <= n; ++i)
        gcd = __gcd(gcd, a[i]);
    for(int i = 1; i <= n; ++i)
        a[i] /= gcd;
    // O(maxA) probably
    // when there is no a[i] = 1, therefore we must try to find things with relative primality
    // going from the smallest number, if something is a multiple of that number, therefore any two multiples
    // of that number can not form a pair
    // for each number, find all factors and those are not allowed to be used
    vector<int> b[n + 1];
    memset(b, 0, sizeof(b));
    int cnt[n + 1];
    for(int i = 1; i <= n; ++i)
        ++cnt[a[i]];
    for(int i = 1; i <= n; ++i) {
        if(cnt[a[i]] && b[a[i]].size() == 0) {
            for(int j = i; j <= n; j += i) 
                if(cnt[j])
                    b[j].pb(i);
        }
    }
    // nanti tiap ini ada isinya, yg masalah klo dia bagian dari lebih dari 1
    // tiap komponen -> tidak boleh internal pairing
    // problem: 1 angka bs masuk beberapa komponen

}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}