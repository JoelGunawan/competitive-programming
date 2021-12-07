#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n / 2; ++i) {
        for(int j = 0; j < m; ++j)
        {
            cout << i + 1 << " " << j + 1 << endl;
            cout << n - i << " " << m - j << endl;
        }
    }
    if(n & 1) {
        for(int j = 0; j < m / 2; ++j)
        {
            cout << n / 2 + 1 << " " << j + 1 << endl;
            cout << n / 2 + 1 << " " << m - j << endl;
        }
        if(m & 1)
            cout << n / 2 + 1 << " " << m / 2 + 1 << endl;
    }
    return 0;
}