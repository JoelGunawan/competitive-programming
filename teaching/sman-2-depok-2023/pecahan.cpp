#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long lcm(long long a, long long b) {
    return a * (b / __gcd(a, b));
}
int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll kpk = lcm(b, d);
    ll atas = a * (kpk / b) + c * (kpk / d);
    ll gcd = __gcd(atas, kpk);
    cout << atas / gcd << " " << kpk / gcd << endl;
}