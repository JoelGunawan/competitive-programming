#include <bits/stdc++.h>
//#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int lim = 1e5 + 5;
struct operations {
    // 1 -> add
    // 2 -> mul
    // 3 -> mod
    // 4 -> if x y
    // 5 -> end_if
    int type, l, r, val;
    bool change;
};
operations ops[lim];
int m, mod;
int nxt[lim];
vector<uint> solve(int l, int r) {
    // use integer and use |= to make very fast
    // O(32 * n)
    vector<uint> a[2];
    a[0] = vector<uint>(1 << m, 0), a[1] = a[0];
    for(int i = 0; i < 1 << m; ++i)
        a[0][i] |= 1 << i;
    // merge in O(2^2m)    
    int cur = 1, pr = 0;
    if(l > r)
        return a[0];
    for(int i = l; i <= r; ++i) {
        for(int j = 0; j < 1 << m; ++j)
            a[cur][j] = 0;
        if(ops[i].type == 1) {
            for(int j = 0; j < 1 << m; ++j)
                a[cur][(j + ops[i].val) % mod] |= a[pr][j];
            if(ops[i].change)
                for(int j = 0; j < 1 << m; ++j)
                    a[cur][j] |= a[pr][j];
        }
        else if(ops[i].type == 2) {
            for(int j = 0; j < 1 << m; ++j)
                a[cur][(j * ops[i].val) % mod] |= a[pr][j];
            if(ops[i].change)
                for(int j = 0; j < 1 << m; ++j)
                    a[cur][j] |= a[pr][j];
        }
        else if(ops[i].type == 3) {
            for(int j = 0; j < 1 << m; ++j)
                a[cur][j % ops[i].val] |= a[pr][j];
            if(ops[i].change)
                for(int j = 0; j < 1 << m; ++j)
                    a[cur][j] |= a[pr][j];
        }
        else {
            // range yang ga merge di or langsung
            // range yang merge itu ada banyak kemungkinan, jadi coba satu per satu aja
            vector<uint> b = solve(i + 1, nxt[i] - 1);
            for(int j = 0; j < ops[i].l; ++j)
                a[cur][j] |= a[pr][j];
            for(int j = ops[i].r + 1; j < 1 << m; ++j)
                a[cur][j] |= a[pr][j];
            for(int j = ops[i].l; j <= ops[i].r; ++j) {
                for(int k = 0; k < 1 << m; ++k) {
                    if(b[k] & (1 << j))
                        a[cur][k] |= a[pr][j];
                }
            }
            i = nxt[i];
        }
        pr ^= 1, cur ^= 1;
    }
    return a[cur ^ 1];
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> m;
    mod = 1 << m;
    // add/mul -> consecutive add/mul bisa di gabung jadi 1 add aja, problem -> boleh di skip
    // mod -> reduces search space to mod only, merge nodes, problem -> boleh di skip
    // can skip? merge nodes again
    // if and end_if -> adds new possibilities for all numbers within range
    int x, y;
    for(int i = 0; i < n; ++i) {
        string op;
        cin >> op;
        operations tmp;
        if(op == "add") {
            cin >> x >> y;
            tmp.type = 1, tmp.val = x, tmp.change = !y;
        }
        else if(op == "mul") {
            cin >> x >> y;
            tmp.type = 2, tmp.val = x, tmp.change = !y;
        }
        else if(op == "mod") {
            cin >> x >> y;
            tmp.type = 3, tmp.val = x, tmp.change = !y;
        }
        else if(op == "if") {
            cin >> x >> y;
            tmp.type = 4, tmp.l = x, tmp.r = y;
        }
        else
            tmp.type = 5;
        ops[i] = tmp;
    }
    // for each if index, find corresponding end index
    vector<int> tmp;
    for(int i = 0; i < n; ++i) {
        if(ops[i].type == 4)
            tmp.push_back(i);
        else if(ops[i].type == 5) {
            nxt[tmp.back()] = i;
            tmp.pop_back();
        }
    }
    vector<uint> ans = solve(0, n - 1);
    for(int i = 0; i < 1 << m; ++i) {
        for(int j = 0; j < 1 << m; ++j)
            cout << (int)(bool)(ans[j] & (1 << i));
        cout << endl;
    }
    return 0;
}