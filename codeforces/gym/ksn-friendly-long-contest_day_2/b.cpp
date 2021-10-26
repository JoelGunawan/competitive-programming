#include <bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;
vector<ll> fib = {1, 2};
map<ll, int> memo;
ll solve(ll a, int depth)
{
    if(binary_search(fib.begin(), fib.end(), a))
        return 1;
    else if(memo[a] == 0)
        memo[a] = 1 + min(solve(a - *--lower_bound(fib.begin(), fib.end(), a), depth + 1), solve(*lower_bound(fib.begin(), fib.end(), a) - a, depth + 1));
    return memo[a];
}
void test_case()
{
    ll n;
    cin >> n;
    // try to find any combination of the four numbers
    // it will always be one lower or one higher than the current
    cout << solve(n, 0) << endl;
}
int main()
{
    int q;
    cin >> q;
    while(fib.back() <= 4 * 1e17)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    while(q--)
        test_case();
    return 0;
}