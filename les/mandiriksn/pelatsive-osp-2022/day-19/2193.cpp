#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int n;
    cin >> n;
    pair<ll, ll> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
    ll luas = 0;
    for(int i = 0; i < n; ++i)
        luas += a[i].x * a[(i + 1) % n].y - a[i].y * a[(i + 1) % n].x;
    luas = abs(luas);
    ll boundary = 0;
    for(int i = 0; i < n; ++i) {
        boundary += gcd(abs(a[(i + 1) % n].x - a[i].x), abs(a[(i + 1) % n].y - a[i].y));
    }
    ll inside = luas - boundary + 2;
    inside /= 2;
    cout << inside << " " << boundary << endl;
}