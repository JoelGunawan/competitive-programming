#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int pow(int a, int b) {
    if(b == 0)
        return 1;
    else {
        int tmp = pow(a, b / 2);
        return b & 1 ? tmp * tmp * a : tmp * tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, in;
        cin >> n >> m;
        bool zero = 0;
        for(int i = 0; i < n; ++i)
            cin >> in, zero = (zero || (in == 0));
        int res = 0;
        if(zero) {
            int current = n - 1; res = n;
            for(int i = 1; i < m; ++i)
                current *= n, res += current;
        }
        else {
            for(int i = 1; i <= m; ++i)
                res += pow(n, i);
        }
        cout << res << endl;
    }
    return 0;
}