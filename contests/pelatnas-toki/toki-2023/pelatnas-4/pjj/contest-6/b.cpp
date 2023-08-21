#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 2001;
struct fenwick {    
    int a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    int query(int idx) {
        int ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    void update(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    int a[2001];
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> factors[2001];
    for(int i = 1; i <= 2000; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(i % j == 0)
                factors[i].push_back(j);
        }
    }
    fenwick value[2001];
    for(int i = 2; i <= n; ++i) {
        for(auto j : factors[i - 1])
            value[j].update(i, a[i]);
    }
    int sz = n;
    while(q--) {
        string type;
        cin >> type;
        if(type == "JUMP") {
            int res = 0;
            if(sz <= 3) {
                cout << a[1] << endl;
                continue;
            }
            //cout << sz << " " << factors[sz].size() << endl;
            for(auto i : factors[sz]) {
                //cout << value[i].query(sz) << " ";
                if((sz == 6 || sz == 4) && i == 1)
                    continue;
                res = max(res, value[i].query(sz));
            }
            //cout << endl;
            cout << max(res + a[1], a[1]) << endl;
        }
        else if(type == "RESIZE") {
            // change size
            // change valid factors
            cin >> sz;
        }
        else {
            int idx, val;
            cin >> idx >> val;
            // tambahin di tiap faktor
            for(auto i : factors[idx - 1]) {
                value[i].update(idx, -a[idx]);
            }
            for(auto i : factors[idx - 1]) {
                value[i].update(idx, val);
            }
            a[idx] = val;
        }
    }
    // operasi resize -> just change everything related to factors
}