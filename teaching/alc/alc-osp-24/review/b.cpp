#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int v[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    // faktorisasi prima a_1, a_n, ...
    vector<int> p;
    for(int i = -1; i <= 1; ++i) {
        int cur = v[1] + i;
        for(int j = 2; 1ll * j * j <= cur; ++j) {
            if(cur % j == 0) {
                while(cur % j == 0)
                    cur /= j;
                p.push_back(j);
            }
        }
        if(cur > 1) 
            p.push_back(cur);
        cur = v[n] + i;
        for(int j = 2; 1ll * j * j <= cur; ++j) {
            if(cur % j == 0) {
                while(cur % j == 0)
                    cur /= j;
                p.push_back(j);
            }
        }
        if(cur > 1)
            p.push_back(cur);
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin()); // hilangkan elemen duplikat di p
    // p ini pasti bener
    long long res = 1e18;
    for(auto f : p) {
        // fpb = f
        // yg g valid di mana aja
        int inval_min = n + 1, inval_max = 0;
        for(int i = 1; i <= n; ++i) {
            if((v[i] - 1) % f && v[i] % f && (v[i] + 1) % f) {
                inval_min = min(inval_min, i);
                inval_max = max(inval_max, i);
            }
        }
        if(inval_min == n + 1) {
            // handle corner case
            long long mx = 0, pref = 0;
            long long mn = 0;
            long long init_cost = 0;
            for(int i = 1; i <= n; ++i) {
                if(v[i] % f)
                    init_cost += b;
            }
            for(int i = 1; i <= n; ++i) {
                pref += a;
                if(v[i] % f) 
                    pref -= b;
                mx = max(mx, pref);
                mn = min(mn, pref - mx);
            }
            // cout << f << " " << init_cost << " " << mn << endl;
            res = min(res, init_cost + mn);
            continue;
        }
        // gada yg invalid (coba di handle nanti aja)
        // prefix dan suffix cost
        long long pref = 1e18, pre_cost = 0, suff_cost = 0, suff = 1e18;
        for(int i = 1; i < inval_min; ++i) {
            // prefix cost
            // bisa langsung bagi -> tidak kena biaya
            // tidak bisa langsung bagi -> kena biaya
            // elemen terakhir yg fpb = f itu di posisi i
            if(v[i] % f) {
                pre_cost += b; // harus di +-1
            }
            pref = min(pref, pre_cost + 1ll * (inval_min - i - 1) * a);
        }
        for(int i = n; i > inval_max; --i) {
            if(v[i] % f) {
                suff_cost += b;
            }
            suff = min(suff, suff_cost + 1ll * (i - inval_max - 1) * a);
        }
        long long tmp = min(pref + suff, min(suff + 1ll * (inval_min - 1) * a, pref + 1ll * (n - inval_max) * a));
        res = min(res, tmp + 1ll * (inval_max - inval_min + 1) * a);
    }
    cout << res << endl;
}