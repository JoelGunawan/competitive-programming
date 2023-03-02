#include "secret.h"
#include <bits/stdc++.h>
using namespace std;
// create a disjoint sparse table like structure
// use nodes, recursive cari jawaban kind of
// ada fungsi query
struct node {
  node *l, *r;
  int le, re, mi;
  vector<int> a;
};
vector<int> arr;
struct disjoint_sparse_table {
  int size = 0;
  node *head = new node();
  void build(node *nd, int l, int r) {
    nd->le = l, nd->re = r, nd->mi = (l + r) >> 1;  
    if(l == r) {
      nd->a.push_back(arr[l]);
      return;
    }
    nd->l = new node(), nd->r = new node();
    int mid = (l + r) >> 1;
    build(nd->l, l, mid), build(nd->r, mid + 1, r);
    for(int i = l; i <= mid; ++i)
      nd->a.push_back(get(nd->l, i, mid));
    for(int i = mid + 1; i <= r; ++i)
      nd->a.push_back(get(nd->r, mid + 1, i));
    //cout << "L R " << l << " " << r << endl;
    //for(auto i : nd->a)
    //  cout << i << " ";
    //cout << endl;
  }
  int get(node *nd, int l, int r) {
    int cl = nd->le, cr = nd->re, mi = nd->mi;
    //cout << "GET " << l << " " << r << " " << cl << " " << cr << endl;
    if(cl == cr)
      return nd->a[0];
    if(l <= mi && r > mi) {
      // has to be in between
      return Secret(nd->a[l - cl], nd->a[r - cl]);
    }
    else {
      if(r <= mi)
        return get(nd->l, l, r);
      else
        return get(nd->r, l, r);
    }
  }
};
disjoint_sparse_table dst;
void Init(int N, int A[]) {
  for(int i = 0; i < N; ++i)
    arr.push_back(A[i]);
  dst.build(dst.head, 0, N - 1);
}

int Query(int L, int R) {
  return dst.get(dst.head, L, R);
}
