#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define fi first
#define se second
#define ins insert
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll add(ll a, ll b)
{
    return (a + b) % mod;
}
ll mul(ll a, ll b)
{
    return (a * b) % mod;
}
ll fact[(int)1e5 + 1];
ll inv(ll a)
{
    return powmod(a, mod - 2);
}
ll c(ll a, ll b)
{
    return mul(fact[a], mul(inv(fact[a - b]), inv(fact[b])));
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // generate factorial
    fact[0] = 1;
    for(int i = 1; i <= 1e5; ++i)
        fact[i] = mul(fact[i - 1], i);
    int n;
    cin >> n;
    int p[n + 1];
    // this set<int> maintain semua angka yg udah ditentukan urutannya 
    set<int> urut;
    vector<pair<int, int>> uw;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        if(p[i] != -1)
            urut.ins(i), uw.pb(mp(p[i], i));
    }
    if(urut.size() == 0)
        cout << powmod(2, n) << endl, exit(0);
    else if(urut.size() == 1)
    {
        if(uw[0].fi == 1)
            cout << c(n - 1, uw[0].se - 1) << endl, exit(0);
        // for every valid index
        // kalo mulai di kiri
        for(int i = 1; i < uw[0].se; ++i)
        {
            
        }
        for(int i = uw[0].se + 1; i <= n; ++i)
        {

        }
    }
    sort(uw.begin(), uw.end());
    // do the first one
    ll res = 0;
    // coba di kanan
    {
        // closest right
        int cr;
        if(urut.ub(uw[0].se) != urut.end())
            cr = *urut.ub(uw[0].se);
        else
            cr = n + 1;
        // if the space in the right is enough
        if(cr - uw[0].se >= uw[0].fi)
        {
            // if there is a next uw that is to the left
            if(uw[1].se < uw[0].se)
            {
                // time >= jarak
                if(uw[1].fi - uw[0].fi >= uw[0].se - uw[1].se)
                    res = add(res, powmod(2, uw[0].fi - 2));
            }
            else
                // we can start on the right
                res = add(res, powmod(2, uw[0].fi - 2));
        }
    }
    // coba di kiri
    {
        int cl;
        if(urut.lb(uw[0].se) != urut.begin())
            cl = *--urut.lb(uw[0].se);
        else
            cl = 0;
        // if the space in the left is enough
        if(uw[0].se - cl >= uw[0].fi)
        {   
            // if there is a next uw that is to the right
            if(uw[1].se > uw[0].se)
            {
                // time >= jarak
                if(uw[1].fi - uw[0].fi >= uw[1].se - uw[0].se)
                    res = add(res, powmod(2, uw[0].fi - 2));
            }
            else
                // we can start on the left
                res = add(res, powmod(2, uw[0].fi - 2));
        }
    }
    // do transitions

    // final
    return 0;
}