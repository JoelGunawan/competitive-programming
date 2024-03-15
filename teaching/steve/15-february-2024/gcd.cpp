#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {
    // int -> -2^31...2^31-1
    // 2^60 dan 2^58
    cout << __gcd(1ll << 60, 1ll << 58) << endl;
}