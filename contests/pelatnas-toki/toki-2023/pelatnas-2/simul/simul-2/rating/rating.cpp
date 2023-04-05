#include "rating.h"

#include <bits/stdc++.h> 
#define fi first
#define se second
#define ll long long
#define mp make_pair
using namespace std;
/*
struct node {
  long long val = 0;
  node *l, *r;
};
const int lim = 1e5;
struct segment_tree {
  vector<node*> head;
  void build(node *nd, int cl, int cr) {
    if(cl == cr)
      return;
    nd->l = new node(), nd->r = new node();
    int mid = (cl + cr) / 2;
    build(nd->l, cl, mid);
    build(nd->r, mid + 1, cr);
  }
  void update(node *old, node *nd, int cl, int cr, int idx, int val) {
    nd->val = old->val;
    if(cl == cr) {
      nd->val += val;
      return;
    }
    int mid = (cl + cr) / 2;
    if(idx <= mid) {
      nd->l = new node();
      update(old->l, nd->l, cl, mid, idx, val);
      nd->r = old->r;
    }
    else {
      nd->r = new node();
      update(old->r, nd->r, mid + 1, cr, idx, val);
      nd->l = old->l;
    }
    nd->val = nd->l->val + nd->r->val;
  }
  ll query(node *nd, int cl, int cr, int l, int r) {
    if(cl >= l && cr <= r)
      return nd->val;
    else if(cl > r || cr < l)
      return 0;
    else {
      int mid = (cl + cr) / 2;
      return query(nd->l, cl, mid, l, r) + query(nd->r, mid + 1, cr, l, r);
    }
  }
  ll query(int idx, int cl, int cr) {
    return query(head[idx], 0, 1e5, cl, cr);
  }
};
*/
const int lim = 1e5 + 5;
struct fenwick {
  ll a[lim];
  fenwick() {
    memset(a, 0, sizeof(a));
  }
  void upd(int idx, int val) {
    ++idx;
    while(idx < lim) {
      a[idx] += val;
      idx += idx&-idx;
    }
  }
  ll query(int idx) {
    ++idx;
    ll res = 0;
    while(idx) {
      res += a[idx];
      idx -= idx&-idx;
    }
    return res;
  }
};
// buat 2 persistent seg, lsum dan rsum segment tree
// nanti di range [l...r] cari tengah"nya kemudian di kurangin aja
// trial pake seg tree biasa dulu, kalo udah bs di impl pake pers pasti AC :D
std::vector<long long> get_ratings(int N, int Q,
    std::vector<int> P, std::vector<int> A, std::vector<int> B, 
    std::vector<int> L, std::vector<int> R
) {
  // sub 1...4
  // sort by lowest p[i]
  // lowest p[i] -> choose smallest
  // second lowest -> ngikutin optimizationnya (harusnya lmyn obvious, just get max from the rest and find whether it is opt to take minimum or some other number)
  vector<long long> ret(Q, -1);
  fenwick lsum, rsum;
  // memo prl, prr, crl, crr dan target untuk tiap query
  // buat tiap index, memo untuk query mana, mb nya berapa, start atau end
  vector<pair<pair<int, int>, bool>> v[100005];
  int lb[Q], rb[Q];
  ll prl[Q], prr[Q], crl[Q], crr[Q];
  for(int i = 0; i < Q; ++i)
    lb[i] = 0, rb[i] = 1e5;
  for(int ad = 0; ad < 18; ++ad) {
    memset(prl, 0, sizeof(prl));
    memset(prr, 0, sizeof(prr));
    memset(crl, 0, sizeof(crl));
    memset(crr, 0, sizeof(crr));
    //cout << "TEST" << endl;
    for(int i = 0; i < Q; ++i) {
      if(lb[i] <= rb[i]) {
        int mb = (lb[i] + rb[i]) / 2;
        if(L[i] != 1)
          v[L[i] - 1].push_back(mp(mp(i, mb), 0));
        v[R[i]].push_back(mp(mp(i, mb), 1));
      }
    }
    for(int i = 1; i <= N; ++i) {
      lsum.upd(P[i - 1], A[i - 1]);
      rsum.upd(P[i - 1], B[i - 1]);
      for(auto j : v[i]) {
        int qnum = j.fi.fi, mb = j.fi.se;
        //cout << "PROC " << i << " " << qnum << " " << mb << " " << (int)j.se << endl;
        if(!j.se) {
          // is start
          prl[qnum] -= lsum.query(mb - 1);
          prr[qnum] -= rsum.query(1e5) - rsum.query(mb);
          crl[qnum] -= lsum.query(mb) - lsum.query(mb - 1);
          crr[qnum] -= rsum.query(mb) - rsum.query(mb - 1);
        }
        else {
          // start jadi kasih -
          prl[qnum] += lsum.query(mb - 1);
          prr[qnum] += rsum.query(1e5) - rsum.query(mb);
          crl[qnum] += lsum.query(mb) - lsum.query(mb - 1);
          crr[qnum] += rsum.query(mb) - rsum.query(mb - 1);
        }
      }
      v[i].clear();
    }
    for(int i = 1; i <= N; ++i) {
      lsum.upd(P[i - 1], -A[i - 1]);
      rsum.upd(P[i - 1], -B[i - 1]);
    }
    for(int i = 0; i < Q; ++i) {
      if(lb[i] > rb[i])
        continue;
      //cout << "RIGHT TILL HERE" << endl;
      ll mb = (lb[i] + rb[i]) / 2
      , target = (R[i] - L[i] + 1) * mb
      , cur = prl[i] + prr[i];
      cur += min(crr[i], max(crl[i], target - cur));
      //cout << lb << " " << rb << endl;
      //cout << crl[i] << " " << crr[i] << " " << prl[i] << " " << prr[i] << endl;
      //cout << lb[i] << " " << rb[i] << " " << mb << endl;
      //cout << i << " " << target << " " << cur << endl;
      if(target - cur >= R[i] - L[i] + 1) {
        // ke bawah aja
        rb[i] = mb - 1;
      }
      else if(cur - target >= R[i] - L[i] + 1) {
        lb[i] = mb + 1;
      }
      else {
        ret[i] = cur, lb[i] = 2e5;
      }
    }
  }
  // paralel binser pake fenwick
  return ret;
  // cuma 1 yg ga pakai min/max
  // nanti binser aja di range itu
  // persistent segtree?
  // mau tau jumlah L yg < p[x] ada berapa di range L, R
  // mau tau jumlah R yg > p[x] ada berapa di range L, R
  // mau tau jumlah L yg = p[x]
  // mau tau jumlah R yg = p[x]
  // belum tentu yg = p[x] exist
  // jadi harus cari yg exist" aja
  // problemnya gmn cari tau dia pake yg mana
  // kalo habis dikurangi min masih terlalu besar, maka answernya pasti di next
  // atau bs paralel binser? jadi segtree di rolling tiap query
  // semua akan pakai max/min kecuali 1 grup tertentu yg pake non max/min
  // bisa pakai 2d sparse seg
  // atau bs pake persistent seg?
  // pers seg -> O(log^2)
}
