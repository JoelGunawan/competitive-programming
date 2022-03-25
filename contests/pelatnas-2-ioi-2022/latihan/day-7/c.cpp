// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
const int lim = 500000;
/*
struct bit {
    int a[200005];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void reset() {
        memset(a, 0, sizeof(a));
    }
    void update(int l, int r, int val) {
        upd(l, val);
        upd(r + 1, -val);
    }
    void upd(int idx, int val) {
        while(idx < 200005)
            a[idx] += val, idx += (idx&-idx);
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx], idx -= (idx&-idx);
        }
        return res;
    }
};
*/
struct bit {
    int a[lim];
    bit() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            //cout << idx << endl;
            a[idx] += val, idx += (idx&-idx);
        }
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
};
struct xor_bit {
    int a[lim];
    xor_bit() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        while(idx < lim) {
            //cout << "XOR " << idx << endl;
            a[idx] ^= val, idx += (idx&-idx);
        }
    }
    int query(int l, int r) {
        return query(r) ^ query(l - 1);
    }
    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res ^= a[idx];
            idx -= (idx&-idx);
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // query 1 l = r -> simpan aja indeks yang sudah di visit
    // query 2 -> cari apakah semua indeks dalam range query sudah divisit
    int q;
    cin >> q;
    vector<vector<int>> queries;
    map<int, int> mapping;
    set<int> tmp;
    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            vector<int> x(4);
            x[0] = t;
            cin >> x[1] >> x[2] >> x[3];
            tmp.ins(x[1]);
            tmp.ins(x[2]);
            queries.pb(x);
        }
        else {
            vector<int> x(3);
            x[0] = t;
            cin >> x[1] >> x[2];
            tmp.ins(x[1]);
            tmp.ins(x[2]);
            queries.pb(x);
        }
    }
    int tmp2 = 0;
    for(auto i : tmp) {
        mapping[i] = ++tmp2;
    }
    for(int i = 0; i < q; ++i) {
        queries[i][1] = mapping[queries[i][1]];
        queries[i][2] = mapping[queries[i][2]];
    }
    bit bit;
    xor_bit xor_bit;
    for(auto i : queries) {
        if(i[0] == 1) {
            //cout << i[1] << " " << i[2] << " " << i[3] << endl;
            if(bit.query(i[1], i[1]) == 0)
                bit.update(i[1], 1), xor_bit.update(i[1], i[3]);
        }
        else {
            //cout << i[1] << " " << i[2] << " " << bit.query(i[1], i[2]) << endl;
            if(bit.query(i[1], i[2]) == i[2] - i[1] + 1) {
                cout << xor_bit.query(i[1], i[2]) << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}