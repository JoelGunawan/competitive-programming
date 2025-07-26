#include <bits/stdc++.h>
#define fi first 
#define se second 
#define mp make_pair
using namespace std;
const int N = 5e5 + 5;
const int M = 3005;

template<typename T1, typename T2>
bool mini(T1 &a, T2 b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T1, typename T2>
bool maxi(T1 &a, T2 b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int a[M][M];
pair<int, int> shop[N];

int n, m, k, q;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int numtest = 0;
    while (cin >> n >> m >> k >> q) {
        if (n == 0) {
            break;
        }

        numtest++;

        cout << "Case " << numtest << ":\n";

        for (int i = 0; i < k; i++) {
            cin >> shop[i].fi >> shop[i].se;
        }

        int lim = max(n, m);
        auto solve = [&](int d) -> void {
            for (int i = 0; i <= 3 * lim; i++) {
                for (int j = 0; j <= 3 * lim; j++) {
                    a[i][j] = 0;
                }   
            }

            auto update = [&](int x, int y, int u, int v) -> void {
                x += lim, y += lim;
                u += lim, v += lim;

                maxi(x, 0);
                maxi(y, 0);
                mini(u, 3 * lim);
                mini(v, 3 * lim);

                // cerr << x << " " << y << " " << u << " " << v << "\n";

                if (x > u || y > v) {
                    return;
                }

                a[x][y]++;
                a[x][v + 1]--;
                a[u + 1][y]--;
                a[u + 1][v + 1]++;
            };

            for (int i = 0; i < k; i++) {
                auto [x, y] = shop[i];
                x--, y--;

                update(x + y - d, x - y - d, x + y + d, x - y + d);
            }

            for (int i = 0; i <= 3 * lim; i++) {
                for (int j = 0; j <= 3 * lim; j++) {
                    if (i > 0) {
                        a[i][j] += a[i - 1][j];
                    }

                    if (j > 0) {
                        a[i][j] += a[i][j - 1];
                    }

                    if (i > 0 && j > 0) {
                        a[i][j] -= a[i - 1][j - 1];
                    }
                }
            }

            int ans = 0;
            pair<int, int> pos = {-1, -1};
            for (int j = 0; j < m; j++) {
                for (int i = 0; i < n; i++) {
                    if (maxi(ans, a[lim + i + j][lim + i - j])) {
                        pos = {i, j};
                    }
                }
            }

            cout << ans << " (" << pos.fi + 1 << "," << pos.se + 1 << ")" << "\n";
        };

        for (int i = 0; i < q; i++) {
            int d; cin >> d;

            solve(d);
        }
    }
    return 0;
}