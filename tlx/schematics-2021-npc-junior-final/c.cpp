#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
int a[8], b[4], n, mod = 1e9 + 7;
ll res = 0, way = 0;
ll powmod(ll a, ll b)
{
    if(b == 0)
        return 1;
    else
    {
        ll tmp = powmod(a, b / 2); tmp *= tmp; tmp %= mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
void brute_force(int state, ll value, set<ll> deck, set<ll> hand)
{
    if(state == n)
    {
        res += value;
        res %= mod;
        ++way;
        return;
    }
    // brute force every single card removal
    set<ll> tmp_1 = hand, tmp_2 = deck;
    for(auto i = hand.begin(); i != hand.end(); ++i)
    {
        tmp_1.erase(*i);
        // brute force every single card insertion
        for(auto j = deck.begin(); j != deck.end(); ++j)
        {
            tmp_1.insert(*j);
            tmp_2.erase(*j);
            tmp_2.insert(*i);
            brute_force(state + 1, value + a[*i - 1], tmp_2, tmp_1);
            // revert back
            tmp_1.erase(*j);
            tmp_2.insert(*j);
            tmp_2.erase(*i);
        }
        // revert back
        tmp_1.insert(*i);
    }
}
void solve()
{
    cin >> n;
    for(int i = 0; i < 8; ++i)
        cin >> a[i];
    for(int i = 0; i < 4; ++i)
        cin >> b[i];
    /*
    if(n == 1)
    {
        // output the average of the 4 integers
        // using the form p / q
        ll res = 0;
        for(int i = 0; i < 4; ++i)
            res += a[b[i] - 1];
        cout << (res * powmod(4, mod - 2)) % mod << endl;
    }
    else if(n <= 5)
    {
        // sampah pakai brute force semua kemungkinan (4^10)
        // brute force each round
        set<ll> deck, hand;
        for(int i = 0; i < 4; ++i)
            hand.insert(b[i]);
        for(int i = 1; i <= 8; ++i)
            if(hand.find(i) == hand.end())
                deck.insert(i);
        brute_force(0, 0, deck, hand);
        //cout << res << endl;
        cout << (res * powmod(way, mod - 2)) % mod << endl;
    }
    */
    if(true)
    {
        // do a O(n) approach by using the expected average of the hand deck at that moment and adding it to the result
        ll res = 0, average_pertama = 0, average_kedua = 0;
        for(int i = 0; i < 4; ++i)
            average_pertama += a[b[i] - 1];
        for(int i = 0; i < 8; ++i)
            average_kedua += a[i];
        average_kedua -= average_pertama;
        average_pertama = (average_pertama * powmod(4, mod - 2)) % mod;
        average_kedua = (average_kedua * powmod(4, mod - 2)) % mod;
        for(int i = 0; i < n; ++i)
        {
            res = (res + average_pertama) % mod;
            ll tmp_1 = average_pertama * 3 + average_kedua, tmp_2 = average_kedua * 3 + average_pertama;
            tmp_1 %= mod; tmp_2 %= mod, average_pertama = (tmp_1 * powmod(4, mod - 2)) % mod, average_kedua = (tmp_2 * powmod(4, mod - 2)) % mod;
        }
        cout << res << endl;
    }
    /*
    else
    {
        // do a[i] = a[j] test case
        cout << (1ll * n * a[0]) % mod << endl;
    }
    */
}
int main()
{
    fast_io();
    solve();
    return 0;
}