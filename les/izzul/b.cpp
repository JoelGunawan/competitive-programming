#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll powmod(ll a, ll b) {
    if(b == 0) {
        return 1;
    }
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        if(b % 2 == 1)
            return (tmp * a) % mod;
        else
            return tmp;
    }
}
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a, b, c;
        cin >> a >> b >> c;
        if(n % 2 == 1) {
            cout << 0 << endl;
            continue;
        }
        swap(a, c);
        // a <= 100, b <= 100, c <= 100, n <= 10^5, t <= 100
        bool hasfound = 0;
        for(ll i = a; i >= 0; --i) {
            for(ll j = b; j >= 0; --j) {
                if(i % 2 == 0 && j % 2 == 0 && n - i * 5 - j * 3 >= 0 && (n - i * 5 - j * 3) % 2 == 0 && c >= n - i * 5 - j * 3) {
                    /*
                    for(ll k = 0; k < (n - i * 5 - j * 3) / 2; ++k)
                        cout << 1 << " ";
                    for(ll k = 0; k < j / 2; ++k)
                        cout << 3 << " ";
                    for(ll k = 0; k < i / 2; ++k)
                        cout << 5 << " ";
                    cout << "- - - ";
                    for(ll k = 0; k < i / 2; ++k)
                        cout << 5 << " ";
                    for(ll k = 0; k < j / 2; ++k)
                        cout << 3 << " ";
                    for(ll k = 0; k < (n - i * 5 - j * 3) / 2; ++k)
                        cout << 1 << " ";
                    cout << endl;
                    */
                    vector<ll> ans;
                    for(ll k = 0; k < (n - i * 5 - j * 3) / 2; ++k)
                        ans.push_back(1);
                    for(ll k = 0; k < j / 2; ++k)
                        ans.push_back(3);
                    for(ll k = 0; k < i / 2; ++k)
                        ans.push_back(5);

                    for(auto k : ans) {
                        cout << k << " ";
                    }
                    cout << "- - - ";
                    reverse(ans.begin(), ans.end());
                    for(auto k : ans)
                        cout << k << " ";
                    cout << endl;
                    hasfound = 1;
                    break;
                }
            }
            if(hasfound)
                break;
        }
        if(!hasfound)
            cout << 0 << endl;
    }
}