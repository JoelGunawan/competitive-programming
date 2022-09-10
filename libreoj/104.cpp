// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
struct node {
    int cnt = 0, mostleft = 1e9, mostright = 0, lchild = -1, rchild = -1;
};
const int lim = 2e7 + 5;
struct dynamic_segment_tree {
    int size = lim;
    vector<node> a = {node()};
    void upd(int nd, int cl, int cr, int idx, int val) {
        a[nd].cnt += val;
        if(cl != cr) {
            int mid = (cl + cr) >> 1;
            if(idx <= mid) {
                if(a[nd].lchild == -1) {
                    a[nd].lchild = a.size(), a.push_back(node());
                }
                upd(a[nd].lchild, cl, mid, idx, val);
            }
            else {
                if(a[nd].rchild == -1) {
                    a[nd].rchild = a.size(), a.push_back(node());
                }
                upd(a[nd].rchild, mid + 1, cr, idx, val);
            }
            a[nd].mostleft = 1e9, a[nd].mostright = 0;
            if(a[nd].lchild != -1) {
                a[nd].mostleft = min(a[nd].mostleft, a[a[nd].lchild].mostleft);
                a[nd].mostright = max(a[nd].mostright, a[a[nd].lchild].mostright);
            }
            if(a[nd].rchild != -1) {
                a[nd].mostleft = min(a[nd].mostleft, a[a[nd].rchild].mostleft);
                a[nd].mostright = max(a[nd].mostright, a[a[nd].rchild].mostright);
            }
        }
        else {
            if(a[nd].cnt)
                a[nd].mostleft = idx, a[nd].mostright = idx;
            else
                a[nd].mostleft = 1e9, a[nd].mostright = 0;
        }

    }
    void upd(int idx, int val) {
        upd(0, 0, size - 1, idx, val);
    }
    int predecessor(int nd, int cl, int cr, int idx) {
        if(cl != cr) {
            int mid = (cl + cr) >> 1;
            if(idx <= mid)
                return predecessor(a[nd].lchild, cl, mid, idx);
            else {
                if(a[nd].lchild != -1)
                    return max(predecessor(a[nd].rchild, mid + 1, cr, idx), a[a[nd].lchild].mostright);
                else
                    return predecessor(a[nd].rchild, mid + 1, cr, idx);
            }
        }
        else
            return 0;
    }
    int predecessor(int idx) {
        return predecessor(0, 0, size - 1, idx);
    }
    int successor(int nd, int cl, int cr, int idx) {
        if(cl != cr) {
            int mid = (cl + cr) >> 1;
            if(idx <= mid) {
                if(a[nd].rchild != -1)
                    return min(successor(a[nd].lchild, cl, mid, idx), a[a[nd].rchild].mostleft);
                else
                    return successor(a[nd].lchild, cl, mid, idx);
            }
            else
                return successor(a[nd].rchild, mid + 1, cr, idx);
        }
        else
            return 1e9;
    }
    int successor(int idx) {
        return successor(0, 0, size - 1, idx);
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl > r || cr < l)
            return 0;
        else if(cl >= l && cr <= r)
            return a[nd].cnt;
        else {
            int mid = (cl + cr) >> 1;
            int ret = 0;
            if(a[nd].lchild != -1)
                ret += query(a[nd].lchild, cl, mid, l, r);
            if(a[nd].rchild != -1)
                ret += query(a[nd].rchild, mid + 1, cr, l, r);
            return ret;
        }
    }
    int query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }
    int query_by_rank(int nd, int cl, int cr, int target, int cur) {
        if(cl == cr)
            return cl;
        int l_cnt = cur, mid = (cl + cr) >> 1;
        if(a[nd].lchild != -1)
            l_cnt += a[a[nd].lchild].cnt;
        if(target <= l_cnt) {
            return query_by_rank(a[nd].lchild, cl, mid, target, cur);
        }
        else {
            return query_by_rank(a[nd].rchild, mid + 1, cr, target, l_cnt);
        }
    }
    int query_by_rank(int target) {
        return query_by_rank(0, 0, size - 1, target, 0);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    dynamic_segment_tree segtree;
    while(n--) {
        int t, x;
        cin >> t >> x;
        x += 1e7 + 1;
        if(t == 1) {
            // insert
            segtree.upd(x, 1);
        }
        else if(t == 2) {
            // delete
            segtree.upd(x, -1);
        }
        else if(t == 3) {
            // query rank of number
            cout << segtree.query(0, x - 1) + 1 << endl;
        }
        else if(t == 4) {
            // find kth number
            x -= 1e7 + 1;
            segtree.upd(x, 0);
            cout << segtree.query_by_rank(x) - (int)1e7 - 1 << endl;
        }
        else if(t == 5) {
            // find predecessor
            segtree.upd(x, 0);
            cout << segtree.predecessor(x) - (int)1e7 - 1 << endl;
        }
        else if(t == 6) {
            // find successor
            segtree.upd(x, 0);
            cout << segtree.successor(x) - (int)1e7 - 1 << endl;
        }
    }
    return 0;
}