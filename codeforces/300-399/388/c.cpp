#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n + 1][101], s[n + 1];
    vector<int> x;
    int l = 0, r = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
        for(int j = 1; j <= s[i]; ++j)
            cin >> a[i][j];
        if(s[i] & 1)
            x.push_back(a[i][(s[i] >> 1) + 1]);
        for(int j = 1; j <= s[i] >> 1; ++j)
            l += a[i][j];
        for(int j = (s[i] >> 1) + 1 + (s[i] & 1); j <= s[i]; ++j)
            r += a[i][j];
    }
    sort(x.begin(), x.end(), greater<int>());
    for(int i = 0; i < x.size(); ++i) {
        if(i & 1)
            r += x[i];
        else
            l += x[i];
    }
    cout << l << " " << r << endl;
}