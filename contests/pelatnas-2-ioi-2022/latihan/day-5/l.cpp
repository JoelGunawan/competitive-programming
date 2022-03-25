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
const int lim = 1e7;
int pr[lim + 1];
void sieve() {
    fill(pr, pr + lim + 1, 1);
    for(int i = 2; i <= lim; ++i) {
        if(pr[i] == 1) {
            for(int j = 2 * i; j <= lim; j += i) {
                pr[j] = i;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sieve();
    // a lucky pair is if
    // y^k mod x = 0 and x^k mod y = 0
    // syarat -> y mempunyai faktor prima yang sama dengan x
    // maintain all prime factors of a number
    // not a lot of possible prime factors
    // maintain all possible prime factors using trie?
    // lucky pair -> same prime factors
    // pregenerate primes between 1 and 1e4?
    // precalculate tiap angka antara 1 sampe 1e7?
    // sieve pr idx?
    // 521 
    // sieve previous prime -> 1e7log1e7
    // use previous sieve
    // find prime factors for each number manually
    // which one is more optimal
    // each number max 8 faktor prima
    // x * y
    // which means x^k mod y = 0 x^k mod x = 0, y^k mod y = 0, y^k mod x = 0
    // faktor prima tidak sama
    // ex (3, 5)
    // -> 8 34
    // faktor prima sama pasti bisa
    // (2, 10)
    // divisible by 20
    // never possible
    // (12, 18)
    // (12 + 18) / (12 * 18)
    // 216
    map<vector<int>, int> x;
    ll res = 0;
    // pr is largest prime factor
    for(int i = 0; i < n; ++i) {
        set<int> tmp;
        while(a[i] > 1) {
            if(pr[a[i]] == 1) {
                tmp.ins(a[i]);
                break;
            }
            else
                tmp.ins(pr[a[i]]), a[i] /= pr[a[i]];
        }
        vector<int> tmp2;
        for(auto i : tmp)
            tmp2.pb(i);
        res += x[tmp2];
        ++x[tmp2];
    }
    cout << res << endl;
    return 0;
}