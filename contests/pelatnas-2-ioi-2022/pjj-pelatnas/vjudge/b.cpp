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
struct node {
    int lchild = -1, rchild = -1;
    int cnt = 0;
    int number = -1;
};
struct trie {
    vector<node> a = {node()};
    int k, msb, lsb;
    ll res = 0;
    void update(int nd, int depth, int val) {
        //cout << nd << " " << a[nd].cnt << endl;
        ++a[nd].cnt;
        if(depth == -1)
            return;
        // go to rchild
        if(val & (1 << depth)) {
            // have code to update
            if(a[nd].rchild == -1)
                a[nd].rchild = a.size(), a.pb(node()), a.back().number = a.size() - 1;
            update(a[nd].rchild, depth - 1, val);
        }
        // go to lchild
        else {
            if(a[nd].lchild == -1)
                a[nd].lchild = a.size(), a.pb(node()), a.back().number = a.size() - 1;
            update(a[nd].lchild, depth - 1, val);
        }
    }
    void upd(int val) {
        update(0, 30, val);
    }
    ll get_ans(int nd, int depth, int val) {
        // lchild mati, rchild nyala
        ll res = 0;
        if(depth == -1)
            return 0;
        if(depth > msb) {
            if((1 << depth) & val) {
                if(a[nd].lchild != -1)
                    res += a[a[nd].lchild].cnt;
                if(a[nd].rchild != -1)
                    res += get_ans(a[nd].rchild, depth - 1, val);
            }
            else {
                if(a[nd].rchild != -1)
                    res += a[a[nd].rchild].cnt;
                if(a[nd].lchild != -1)
                    res += get_ans(a[nd].lchild, depth - 1, val);
            }
        }
        else if(depth == lsb) {
            if((1 << depth) & val) {
                if(a[nd].lchild != -1)
                    res += a[a[nd].lchild].cnt;
            }
            else {
                if(a[nd].rchild != -1)
                    res += a[a[nd].rchild].cnt;
            }
        }
        else if((1 << depth) & k) {
            if((1 << depth) & val) {
                if(a[nd].lchild != -1)
                    res += get_ans(a[nd].lchild, depth - 1, val);
            }
            else {
                if(a[nd].rchild != -1)
                    res += get_ans(a[nd].rchild, depth - 1, val);
            }
        }
        else {
            if((1 << depth) & val) {
                if(a[nd].lchild != -1)
                    res += a[a[nd].lchild].cnt;
                if(a[nd].rchild != -1)
                    res += get_ans(a[nd].rchild, depth - 1, val);
            }
            else {
                if(a[nd].rchild != -1)
                    res += a[a[nd].rchild].cnt;
                if(a[nd].lchild != -1)
                    res += get_ans(a[nd].lchild, depth - 1, val);
            }
        }
        return res;
    }
};
trie t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    t.k = k;
    for(int i = 30; i >= 0; --i) 
        if((1 << i) & k) {
            t.msb = i;
            break;
        }
    for(int i = 0; i <= 30; ++i)
        if((1 << i) & k) {
            t.lsb = i;
            break;
        }
    int a[n];
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i < n; ++i)
        a[i] = a[i - 1] ^ a[i];
    t.upd(0);
    // we can simplify the problem to finding how many pairs of numbers xor to bigger than or equal to k
    for(auto i : a) {
        res += t.get_ans(0, 30, i);
        t.upd(i);
        //cout << endl;
    }
    cout << res << endl;
    return 0;
}