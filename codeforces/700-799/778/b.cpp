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
struct number {
    string x;
    bool num[2][1001];
    number() {
        memset(num, 0, sizeof(num));
    }
};
bool f(bool a, bool b, string op) {
    if(op == "AND")
        return a & b;
    else if(op == "XOR")
        return a ^ b;
    else
        return a | b;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    number a[n];
    for(int i = 0; i < n; ++i) {
        //cout << i << endl;
        string var, ops;
        cin >> var >> ops;
        string x;
        cin >> x;
        number cur;
        cur.x = var;
        if(x[0] == '0' || x[0] == '1') {
            //cout << i << endl;
            // x is number
            for(int j = 0; j < x.size(); ++j) {
                cur.num[0][j] = x[j] - '0';
                cur.num[1][j] = x[j] - '0';
            }
        }
        else {
            string op;
            cin >> op;
            string y;
            cin >> y;
            if(x[0] == '?' && y[0] == '?') {
                for(int j = 0; j < m; ++j) {
                    cur.num[0][j] = f(0, 0, op); 
                    cur.num[1][j] = f(1, 1, op);
                }
            }
            else if(x[0] == '?' || y[0] == '?') {
                if(y[0] == '?')
                    swap(x, y);
                // find where y is
                int idx;
                for(int j = 0; j < i; ++j) {
                    if(y == a[j].x)
                        idx = j;
                }
                number &tmp = a[idx];
                for(int j = 0; j < m; ++j) {
                    cur.num[0][j] = f(0, tmp.num[0][j], op);
                    cur.num[1][j] = f(1, tmp.num[1][j], op);
                }
            }
            else {
                int idx1, idx2;
                for(int j = 0; j < i; ++j) {
                    if(x == a[j].x)
                        idx1 = j;
                    if(y == a[j].x)
                        idx2 = j;
                }
                number &tmp1 = a[idx1], &tmp2 = a[idx2];
                for(int j = 0; j < m; ++j) {
                    cur.num[0][j] = f(tmp1.num[0][j], tmp2.num[0][j], op);
                    cur.num[1][j] = f(tmp1.num[1][j], tmp2.num[1][j], op);
                }
            }
        }
        a[i] = cur;
    }
    // for each bit calculate sum if 1 and if 0
    // which is max and which is min
    // if 0 == 1 -> print 0 always
    string maxres = "", minres = "";
    for(int i = 0; i < m; ++i) {
        int zero = 0, one = 0;
        for(int j = 0; j < n; ++j) {
            zero += a[j].num[0][i];
            one += a[j].num[1][i];
        }
        if(zero == one)
            minres += '0', maxres += '0';
        else if(zero < one) {
            minres += '0';
            maxres += '1';
        }
        else {
            minres += '1';
            maxres += '0';
        }
    }
    cout << minres << endl << maxres << endl;
    return 0;
}