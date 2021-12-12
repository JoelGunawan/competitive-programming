#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
using namespace std;
int mod = 1e9 + 7;
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll add(ll a, ll b, ll c) {
    return (a + b + c) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
    must be non decreasing
    and then non increasing
    as long as there are no holes in the middle
    do using dp?
    dp state
    has always been non decreasing
    has decreased before (which means it can only be non increasing)
    problem -> there can be multiple increasing states that are duplicates of each other?
    dp states n^3
    dp transitions n^2  
    */
    int n;
    cin >> n;
    // this is not a 2d prefix sum, it's just n prefix sums
    int prefix[n + 1][n + 1];
    memset(prefix, 0, sizeof(prefix));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            char a;
            cin >> a;
            prefix[i][j] = prefix[i][j - 1] + a - '0';
        }
    }
    // check for each subarray
    // dp 3 macem
    // non decreasing
    // sudah decrease dari kanan -> gaboleh increasing ke kanan
    // sudah decrease dari kiri -> gaboleh increasing ke kiri
    // sudah dua"nya -> gaboleh increasing dua"nya
    ll nd[2][n + 1][n + 1], dkanan[2][n + 1][n + 1], dkiri[2][n + 1][n + 1], d[2][n + 1][n + 1];
    memset(nd, 0, sizeof(nd));
    memset(dkanan, 0, sizeof(dkanan));
    memset(dkiri, 0, sizeof(dkiri));
    memset(d, 0, sizeof(d));
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int k = j; k <= n; ++k) {
                if(prefix[i][k] - prefix[i][j - 1] == k - j + 1) {
                    // transisi non decreasing
                    nd[i % 2][j][k] = 1;
                    for(int a = j; a <= k; ++a) {
                        for(int b = a; b <= k; ++b) {
                            nd[i % 2][j][k] = add(nd[i % 2][j][k], nd[(i + 1) % 2][a][b]); 
                        }
                    }
                    dkiri[i % 2][j][k] = dkiri[(i + 1) % 2][j][k];
                    dkanan[i % 2][j][k] = dkanan[(i + 1) % 2][j][k];
                    // transisi decrease dari kanan
                    for(int a = j; a <= k; ++a) {
                        for(int b = k + 1; b <= n; ++b) {
                            dkiri[i % 2][j][k] = add(dkiri[i % 2][j][k], dkiri[(i + 1) % 2][a][b], nd[(i + 1) % 2][a][b]);
                        }
                    }
                    // transisi decrease dari kiri
                    for(int a = 1; a < j; ++a) {
                        for(int b = j; b <= k; ++b) {
                            dkanan[i % 2][j][k] = add(dkanan[i % 2][j][k], dkanan[(i + 1) % 2][a][b], nd[(i + 1) % 2][a][b]);
                        }
                    }
                    // decreasing both
                    // subarray of decreasing dari kanan yang kirinya ga penuh
                    // subarray of decreasing dari kiri yang kanannya ga penuh
                    // decreasing kiri dan kanan
                    // transisi increasing -> decreasing both
                    // transisi non decreasing yg ngebug
                    d[i % 2][j][k] = 0;
                    for(int a = 1; a < j; ++a) {
                        for(int b = k + 1; b <= n; ++b) {
                            d[i % 2][j][k] = add(d[i % 2][j][k], nd[(i + 1) % 2][a][b]);
                        }
                    }
                    // transisi dari decreasing kiri dan kanan
                    for(int a = 1; a <= j; ++a) {
                        for(int b = k; b <= n; ++b)
                            d[i % 2][j][k] = add(d[i % 2][j][k], d[(i + 1) % 2][a][b]);
                    }
                    // transisi dari decrease dari kiri
                    for(int a = 1; a <= j; ++a) {
                        for(int b = k + 1; b <= n; ++b) {
                            d[i % 2][j][k] = add(d[i % 2][j][k], dkiri[(i + 1) % 2][a][b]);
                        }
                    }
                    // transisi dari decrease dari kanan
                    for(int a = 1; a < j; ++a) {
                        for(int b = k; b <= n; ++b) {
                            d[i % 2][j][k] = add(d[i % 2][j][k], dkanan[(i + 1) % 2][a][b]);
                        }
                    }
                    res = (res + nd[i % 2][j][k] + dkanan[i % 2][j][k] + dkiri[i % 2][j][k] + d[i % 2][j][k]) % mod;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}