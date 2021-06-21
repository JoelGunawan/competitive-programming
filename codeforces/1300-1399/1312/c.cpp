#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
void test_case()
{
    ll n, k;
    cin >> n >> k;
    multiset<ll> a;
    for(int i = 0; i < n; ++i)
    {
        ll num;
        cin >> num;
        a.insert(num);
    }
    ll exp = k;
    while(a.size() > 0 && exp < *--a.end())
        exp *= k;
    while(a.size() > 0 && exp > 0)
    {
        ll tmp = *--a.end();
        if(tmp >= exp)
        {
            a.erase(--a.end());
            tmp -= exp;
            a.insert(tmp);
        }
        if(a.lower_bound(exp) != a.end())
        {
            cout << "NO" << endl;
            return;
        }
        exp /= k;
    }
    while(a.size() > 0 && *a.begin() == 0)
        a.erase(a.begin());
    if(a.size() == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}