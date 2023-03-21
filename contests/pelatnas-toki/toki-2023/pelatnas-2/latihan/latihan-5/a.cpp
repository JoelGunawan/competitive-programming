// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef struct item * pitem;
struct item {
    int prior, value[10], cnt, mem;
    bool rev = 0;
    pitem l = NULL, r = NULL;
    item() {
        memset(value, 0, sizeof(value));
    }
};

int cnt (pitem it) {
    if(!it)
        return 0;
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if(!it)
        return;
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        for(int i = 0; i < 10; ++i) {
            it->value[i] = 0;
            if(it->l)
                it->value[i] += it->l->value[i];
            if(it->r)
                it->value[i] += it->r->value[i];
        }
        it->value[it->mem]++;
    }
}

void push (pitem it) {
    if(!it)
        return;
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l-1);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    // make prefsum of count of char
    // query count of char
    // output calc using fact and inverse fact
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    pitem treap = new item();
    treap->prior = rnd();
    treap->mem = s[0] - 'a';
    for(int i = 2; i <= n; ++i) {
        pitem tmp = new item();
        tmp->prior = rnd();
        tmp->mem = s[i - 1] - 'a';
        treap->cnt = 1;
        merge(treap, treap, tmp);
    }
    // bisa pakai segment tree yang support swap operations
    // harus treap? atau pakai sqrt juga bisa
    // buat array ukuran L, R
    // simpan nodes yang akan dipakai untuk reverse
    // coba metode sqrt, paling masuk akal
    // kalo ga harus pake treap, dimana nanti kita reverse terus simpan lazy reverse gtu :D
    ll fact[n + 5], inv[n + 5];
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % mod, inv[i] = powmod(fact[i], mod - 2);
    for(int i = 0; i < q; ++i) {
        int t, l, r;
        cin >> t >> l >> r;
        //cout << t << " " << l << " " << r << endl;
        if(t == 1) {
            reverse(treap, l, r);
        }
        else {
            pitem a, b, c;
            // ambil segment l, r
            split(treap, a, b, l - 1);
            split(b, b, c, r - l + 1);
            int res[10];
            memset(res, 0, sizeof(res));
            //cout << "A " << cnt(a) << " " << endl;
            //cout << "B " << cnt(b) << " " << endl;
            //cout << "C " << cnt(c) << " " << endl;
            if(b) {
                for(int i = 0; i < 10; ++i)
                    res[i] = b->value[i];
            }
            merge(treap, a, b);
            merge(treap, treap, c);
            int ganjil = 0;
            for(int i = 0; i < 10; ++i)
                if(res[i] & 1)
                    ++ganjil;
            if(ganjil > 1) 
                cout << 0 << endl;
            else {
                ll ans = fact[(r - l + 1) / 2];
                for(int i = 0; i < 10; ++i) 
                    ans = (ans * inv[res[i] / 2]) % mod;
                cout << ans << endl;
            }
        }
    }
    return 0;
}