// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool ans[2][2][2];
    ans[0][0][0] = 0;
    ans[0][0][1] = 0;
    ans[0][1][0] = 0;
    ans[1][0][0] = 1;
    ans[0][1][1] = 1;
    ans[1][0][1] = 0;
    ans[1][1][0] = 0;
    ans[1][1][1] = 0;
    string s;
    cin >> s;
    int c[s.size() + 1], o[s.size() + 1], w[s.size() + 1];
    memset(c, 0, sizeof(c));
    memset(o, 0, sizeof(o));
    memset(w, 0, sizeof(w));
    for(int i = 1; i <= s.size(); ++i) {
        c[i] = c[i - 1];
        o[i] = o[i - 1];
        w[i] = w[i - 1];
        if(s[i - 1] == 'C')
            ++c[i];
        else if(s[i - 1] == 'O')
            ++o[i];
        else
            ++w[i];
    }
    //for(int i = 1; i <= s.size(); ++i)
    //    cout << c[i] << " " << o[i] << " " << w[i] << endl;
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        int x = c[r] - c[l - 1], y = o[r] - o[l - 1], z = w[r] - w[l - 1];
        x %= 2, y %= 2, z %= 2;
        //cout << x << " " << y << " " << z << endl;
        if(ans[x][y][z])
            cout << "Y";
        else
            cout << "N";
    }
    cout << endl;
    return 0;
}