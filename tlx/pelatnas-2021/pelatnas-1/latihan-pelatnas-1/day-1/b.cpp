#include <bits/stdc++.h>
#define pb push_back
#define ins isnert
#define fi first
#define se second
#define ll long long
#define endl "\n"
#define ld long double
using namespace std;
ll n, a;
unordered_map<int, ll> memo;
ll f(ll n)
{
    //cout << n << endl;
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(memo[n])
        return memo[n];
    ll res = n;
    for(int i = 2; i <= ceil(sqrt(n)); ++i)
        res = min(res, f(ceil((double)n / i)) + i + a);
    memo[n] = res;
    return memo[n];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a;
    // theory
    // the optimal way is between 2 and sqrt(n) -> true
    // determining the optimal way can be done in O(log a) time using binary search
    // of sqrt(a) possibilities
    // we need to precalc sqrt(a) possibilities
    /*
    Misalkan kita jual bolpen X kali dan produksi sebanyak U1, U2, ..., U(X+1) kali
    Total time = AX + sum S_i, Total kugelschreiber = prod S_i
    Hence for a certain X we must find the minimum sum S_i, take p = N^(1/X) and iterate all possible p^A * (p+1)^B
    Try for all 1 <= X <= 50, as S_i > 1 for effectiveness, hence take log_2 N   
    */
    // observasi 1 -> the final run a[0]*a[1]*...*a[k] >= n
    // minimize sum A(k - 1) + sum_of(a)
    // brute for each k to
    // find the minimum by using kth root of n for optimal a values 
    return 0;
}