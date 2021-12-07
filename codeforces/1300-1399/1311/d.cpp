#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define lb lower_bound
#define fi first
#define se second
#define mp make_pair
#define ll long long
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        // brute force every possible b?
        // that's straight forward...
        // n * sqrt(n) :v
        int res = INT_MAX, x, y, z;
        for(int i = 1; i <= 2 * 1e4; ++i) {
            int m_dist = 1e9, num;
            for(int j = 1; j <= sqrt(i); ++j)
            {
                if(i % j == 0)
                {
                    if(abs(a - j) < m_dist)
                        num = j, m_dist = abs(a - j);
                    if(abs(i / j - a) < m_dist)
                        num = i / j, m_dist = abs(i / j - a);
                }
            }
            if(m_dist + abs(b - i) + min(c % i, i - (c % i)) < res) {
                res = m_dist + abs(b - i) + min(c % i, i - (c % i));
                x = num, y = i;
                if(c % i < i - (c % i))
                    z = c / i * i;
                else
                    z = (c / i + 1) * i;
            }
        }
        cout << res << endl << x << " " << y << " " << z << endl;
    }
    return 0;
}