#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
using namespace std;
ll combin(ll a, ll b)
{
    lll res = 1;
    for(int i = a; i > max(a - b, b); --i)
        res *= i;
    for(int i = min(a - b, b); i >= 2; --i)
        res /= i;
    return (ll)res;
}
void test_case()
{
    // resever the first fifty
    ll k;
    cin >> k;
    vector<ll> cp(5 * 1e4 + 1, 0);
    for(int i = 4; i <= 5 * 1e4; ++i)
        // cari combin C(i, 4) * i
        cp[i] = combin(i - 1, 3) * i;
    // binser cp
    vector<pair<int, pair<int, int>>> operations;
    int cur = 1;
    while(k >= 4)
    {
        // cari prefix kombin pertama
        // strongly connected e butuh brapa cari sg paling gede yg <= 
        ll cur_size = --ub(cp.begin(), cp.end(), k) - cp.begin();
        for(int i = cur; i <= cur + cur_size - 1; ++i)
            operations.push_back(mp(i, mp(cur, cur + cur_size - 1)));
        cur += cur_size;
        k -= cp[cur_size];
    }
    while(k > 0)
    {
        // tambah 1
        operations.push_back(mp(cur, mp(cur, cur + 3)));
        cur += 4;
        --k;
    }
    cout << operations.size() << endl;
    for(int i = 0; i < operations.size(); ++i)
        cout << operations[i].first << " " << operations[i].second.first << " " << operations[i].second.second << endl;
}
int main()
{
    fast_io();
    test_case();
    return 0;
}