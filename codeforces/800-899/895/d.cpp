#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
int main() {
    string a, b;
    cin >> a >> b;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < a.size(); ++i)
        ++cnt[a[i] - 'a'];
    if(a >= b)
        cout << 0 << endl, exit(0);
    a = " " + a;
    b = " " + b;
    ll fact[(int)1e6 + 5], inv[(int)1e6 + 5];
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i <= 1e6; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    // string c is lexico bigger than a
    // string c is lexico smaller than b
    // bound by a and b
    // prefix equals -> no variation
    // rest -> variation allowed 
    int pr = 0;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] == b[i])
            pr = i;
        else
            break;
    }
    for(int i = 1; i <= pr; ++i)
        --cnt[a[i] - 'a'];
    // start counting from pr
    // maintain equal to b
    // maintain equal to a
    int cnt2[26];
    memset(cnt2, 0, sizeof(cnt2));
    for(int i = 0; i < 26; ++i)
        cnt2[i] = cnt[i];
    int n = a.size() - 1;
    ll res = 0;
    bool low = 1, high = 1;
    for(int i = pr + 1; i <= n; ++i) {
        // first do things diff
        // after that free
        if(i == pr + 1) {
            ll tmp = fact[n - i];
            for(int j = 0; j < 26; ++j) {
                tmp = mul(tmp, inv[cnt[j]]);
            }
            for(int j = a[i] - 'a' + 1; j < b[i] - 'a'; ++j) {
                if(cnt[j]) {
                    // add to res
                    res += mul(tmp, mul(fact[cnt[j]], inv[cnt[j] - 1]));
                }
            }
        }
        else {
            ll tmp, tmp2;
            tmp = tmp2 = fact[n - i];
            for(int j = 0; j < 26; ++j) {
                tmp = mul(tmp, inv[cnt[j]]);
                tmp2 = mul(tmp2, inv[cnt2[j]]);
            }
            if(low)
                for(int j = a[i] - 'a' + 1; j < 26; ++j) {
                    if(cnt[j])
                        res += mul(tmp, mul(fact[cnt[j]], inv[cnt[j] - 1]));
                }
            //cout << res << " ";
            if(high)
                for(int j = 0; j < b[i] - 'a'; ++j) {
                    if(cnt2[j])
                        res += mul(tmp2, mul(fact[cnt2[j]], inv[cnt2[j] - 1]));
                }
            //cout << res << " ";
        }
        res %= mod;
        //cout << i << " " << res << endl;
        --cnt2[b[i] - 'a'];
        --cnt[a[i] - 'a'];
        if(cnt[a[i] - 'a'] < 0)
            low = 0;
        if(cnt2[b[i] - 'a'] < 0)
            high = 0;
    }
    cout << res << endl;
}