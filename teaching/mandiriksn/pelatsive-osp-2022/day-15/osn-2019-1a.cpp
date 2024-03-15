#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, c;
    cin >> r >> c;
    int pref[r + 1][c + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            char x;
            cin >> x;
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (x == '0');
        }
    }
    int sum = r * c - pref[r][c];
    vector<int> a;
    for(int i = 1; i <= sum; ++i) {
        if(sum % i == 0)
            a.push_back(i);
    }
    int res = 2e9;
    for(auto sz : a) {
        //cout << sz << endl;
        for(int i = 1; i + sz - 1 <= r; ++i) {
            for(int j = 1; j + sum / sz - 1 <= c; ++j) {
                res = min(res, pref[i + sz - 1][j + sum / sz - 1] - pref[i - 1][j + sum / sz - 1] - pref[i + sz - 1][j - 1] + pref[i - 1][j - 1]);
                //cout << i << " " << j << " " << res << endl;
            }
        }
    }
    if(res == 2e9)
        cout << -1 << endl;
    else
        cout << res << endl;
}