#include <bits/stdc++.h>
using namespace std;
typedef node* pnode;
struct node {
  int prior, size, key;
  node *l,*r;
  node(int nil): prior(rng()), size(1),
  key(nil), l(NULL), r(NULL) {}
};
int getsz(pnode t){
  return t?t->size:0;
}
// mengupdate size dari node ini
void upd_sz(pnode t){
  if(t)
    t->size=getsz(t->l)+1+getsz(t->r);
}
void split(pnode t,pnode &l,pnode &r,int x,int add=0) {
  if (!t) return void(l=r=NULL);
    int cur_key = add + getsz(t->l);
  if (cur_key<=x)
    split(t->r,t->r,r,x,cur_key+1), l=t;
  else
    split(t->l,l,t->l,x,add), r=t;
  upd_sz(t);
  operation(t);
}

void merge(pnode &t, pnode l, pnode r){
  if(!l || !r) t = l?l:r; //base case
  else if(l->prior>r->prior) 
    merge(l->r,l->r,r),t=l;
  else
    merge(r->l,l,r->l),t=r;
  upd_sz(t);
  operation(t);
}