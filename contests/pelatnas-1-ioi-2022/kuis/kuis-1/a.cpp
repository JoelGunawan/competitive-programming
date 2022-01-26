#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int mod = 1e9 + 7;
ll fact[100001];
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
ll mulmod(ll a, ll b)
{
    return (a * b) % mod;
}
ll combinmod(ll a, ll b)
{
    if(a < 0 || b < 0)
        return 0;
    return (((fact[a] * powmod(fact[a - b], mod - 2)) % mod) * powmod(fact[b], mod - 2)) % mod;
}
void invalid()
{
    cout << 0 << endl, exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i <= 100000; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    ll res;
    // start dari yg paling awal
    // the start itu g mesti
    // bisa dari kanan atau dari kiri
    // tapi tergantung move keduanya juga
    // after the last non -1, we can do any random sequence of L and R
    // before the firt non -1, we need to consider how many ways we can make it
    // if the distance between it is > then the time difference, then we must do at least x amount to the right
    // if there is no non -1, do special case
    // if there is only 1 non -1, do special case
    // else we can do a general case solution
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(p[i] != -1)
            ++cnt;
    if(cnt == 0)
    {
        res = 0;
        for(int i = 0; i < n; ++i)
            res = (res + combinmod(n - 1, i)) % mod;
    }
    else if(cnt == 1)
    {
        // find cnt
        res = 0;
        int first_index = 0;
        for(int i = 0; i < n; ++i)
            if(p[i] != -1)
                first_index = i;
        int value = p[first_index];
        ++first_index;
        if(value == 1)
            res = combinmod(n - 1, first_index - 1);
        if(first_index >= value)
        {
            // calc buat mulai kiri
            for(int i = 0; i < value - 1; ++i)
                res = (res + mulmod(combinmod(value - 2, i), combinmod(n - value, first_index - value))) % mod;
        }
        if(n - first_index + 1 >= value)
        {
            // calc buat mulai kanan
            for(int i = 0; i < value - 1; ++i)
                res = (res + mulmod(combinmod(value - 2, i), combinmod(n - value, n - first_index + 1 - value))) % mod;
        }
    }
    else
    {
        // find the first and the second
        // this is kind of case bashy
        // check if it is possible
        // for the first we need to casebash
        // find the first and the second
        vector<pair<int, int>> a;
        set<int> blocked;
        for(int i = 0; i < n; ++i)
            if(p[i] != -1)
                a.pb({p[i], i + 1}), blocked.insert(i + 1);
        sort(a.begin(), a.end());        
        int cur_left, cur_right;
        if(a[0].se < a[1].se)
        {
            cur_left = a[1].se - a[1].fi + 1, cur_right = a[1].se;
            // check collision
            if(*blocked.upper_bound(a[0].se) != a[1].se)
                invalid();
            // check within range
            if(cur_left < 1 || cur_right > n || a[0].se < cur_left || a[0].se > cur_right)
                invalid();
        }
        else
        {
            cur_left = a[1].se, cur_right = a[1].se + a[1].fi - 1;
            // check collision
            
            // check within range
        }
        for(int i = 2; i < a.size(); ++i)
        {
            if(a[i].se < cur_left)
            {
                // check collision
                if(*blocked.upper_bound(a[i].se) < cur_right)
                    invalid();
                cur_left = a[i].se;
                // check distance
                if(cur_right - cur_left + 1 > a[i].fi)
                    invalid();
                
            }
            else
            {
                // check collision
                if(*blocked.upper_bound(cur_left) != a[i].se)
                    invalid();
                // check distance
                cur_right = a[i].se;
                if(cur_right - cur_left + 1 > a[i].fi)
                    invalid();
            }
            blocked.erase(a[i].se);
        }
    }
    cout << res << endl;
    return 0;
}