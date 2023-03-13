#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct node {
    int lseg = 0, rseg = 0, val = 0;
    node *l = NULL, *r = NULL;
};
struct segment_tree {
    node *head = new node();
    void update(node *nd, node *old, int idx, int val) {
        int cl = nd->lseg, cr = nd->rseg;
        if(old)
            nd->l = old->l, nd->r = old->r;
        if(cl == cr) {
            //cout << "UPD " << idx << " " << val << " " << nd->lseg << " " << nd->rseg << endl;
            nd->val = val;
            return;
        }
        int mid = (cl + cr) / 2;
        if(idx <= mid) {
            nd->l = new node();
            nd->l->lseg = cl, nd->l->rseg = mid;
            if(old)
                update(nd->l, old->l, idx, val);
            else
                update(nd->l, old, idx, val);
            nd->val = 0;
            nd->val += nd->l->val;
            if(nd->r)
                nd->val += nd->r->val;
        }
        else {
            nd->r = new node();
            nd->r->lseg = mid + 1, nd->r->rseg = cr;
            if(old)
                update(nd->r, old->r, idx, val);
            else
                update(nd->r, old, idx, val);
            nd->val = 0;
            nd->val += nd->r->val;
            if(nd->l)
                nd->val += nd->l->val;
        }
        //cout << "UPD RES " << nd->lseg << " " << nd->rseg << " " << nd->val << endl;
    }
    int query(node *nd, int l, int r) {
        //cout << "Q " << nd->lseg << " " << nd->rseg << " "  << l << " " << r << endl;
        int cl = nd->lseg, cr = nd->rseg;
        if(cl >= l && cr <= r) {
            //cout << "POS 1" << endl;
            //cout << "QUERY " << cl << " " << cr << " " << nd->val << endl;
            return nd->val;
        }
        else if(cl > r || cr < l) {
            //cout << "POS 2" << endl;
            return 0;
        }
        else {
            //cout << "POS 3" << endl;
            int res = 0;
            if(nd->l)
                res += query(nd->l, l, r);
            if(nd->r)
                res += query(nd->r, l, r);
            return res;
        }   
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    segment_tree seg[100005], inv[100005];
    seg[0].head->lseg = 1, seg[0].head->rseg = m * (n + 1);
    inv[0].head->lseg = 1, inv[0].head->rseg = n;
    int res[100005];
    memset(res, 0, sizeof(res));
    int last_upd = 0;
    for(int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        //cout << "TYPE " << t << endl;
        res[i] = res[i - 1];
        seg[i].head->l = seg[i - 1].head->l;
        seg[i].head->r = seg[i - 1].head->r;
        seg[i].head->lseg = seg[i - 1].head->lseg;
        seg[i].head->rseg = seg[i - 1].head->rseg;
        seg[i].head->val = seg[i - 1].head->val;
        inv[i].head->l = inv[i - 1].head->l;
        inv[i].head->r = inv[i - 1].head->r;
        inv[i].head->lseg = inv[i - 1].head->lseg;
        inv[i].head->rseg = inv[i - 1].head->rseg;
        inv[i].head->val = inv[i - 1].head->val;
        if(t == 1) {
            int x, y;
            cin >> x >> y;
            //cout << "TYPE 1 " << x << " " << y << " " << seg[x].query(seg[x].head.back(), y, y) << " " << seg[x].inv.back().second << endl;
            //cout << seg[i].query(seg[i].head, x * m + y, x * m + y) << " " << inv[i].query(inv[i].head, x, x) << endl;
            if(seg[i].query(seg[i].head, x * m + y, x * m + y) ^ inv[i].query(inv[i].head, x, x) ^ 1) {
                seg[i].update(seg[i].head, seg[i - 1].head, x * m + y, inv[i].query(inv[i].head, x, x) ^ 1);
                //cout << seg[i].query(seg[i].head, x * m + y, x * m + y) << endl;
                ++res[i];
            }
        }
        else if(t == 2) {
            int x, y;
            cin >> x >> y;
            if(seg[i].query(seg[i].head, x * m + y, x * m + y) ^ inv[i].query(inv[i].head, x, x)) {
                seg[i].update(seg[i].head, seg[i - 1].head, x * m + y, inv[i].query(inv[i].head, x, x));
                --res[i];
            }
        }
        else if(t == 3) {
            int x;
            cin >> x;
            // maintain segment tree untuk tau elemen mana paling terakhir yang diketahui statenya yang mana, terus habis itu cari taun elemen mana yang paling terakhir di call
            // kalo ngga ada, berarti 
            // update new based on that
            //cout << "TYPE 3 " << seg[x].query(seg[x].head.back(), 1, m) << " " << seg[x].inv.back().second << endl;
            inv[i].update(inv[i].head, inv[i - 1].head, x, inv[i].query(inv[i].head, x, x) ^ 1);
            if(inv[i].query(inv[i].head, x, x))
                res[i] += m - 2 * seg[i].query(seg[i].head, m * x + 1, m * x + m);
            else
                res[i] += 2 * seg[i].query(seg[i].head, m * x + 1, m * x + m) - m;
        }
        else {
            int k;
            cin >> k;
            res[i] = res[k];
            seg[i].head->l = seg[k].head->l;
            seg[i].head->r = seg[k].head->r;
            seg[i].head->lseg = seg[k].head->lseg;
            seg[i].head->rseg = seg[k].head->rseg;
            seg[i].head->val = seg[k].head->val;
            inv[i].head->l = inv[k].head->l;
            inv[i].head->r = inv[k].head->r;
            inv[i].head->lseg = inv[k].head->lseg;
            inv[i].head->rseg = inv[k].head->rseg;
            inv[i].head->val = inv[k].head->val;
        }
        cout << res[i] << endl;
    }
}