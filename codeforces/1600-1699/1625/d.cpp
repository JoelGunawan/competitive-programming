#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
  node *l, *r;
  int cnt = 0;
  vector<int> v;
};
vector<int> res;
struct trie {
  node *head = new node();
  void add(int num) {
    add(head, num, 29);
  }
  vector<int> fc(node *l, node *r, int num, int depth) {
    vector<int> ret, tmp;
    if(depth == -1)
      ret = {l->v[0], r->v[0]};
    else if((1 << depth) & num) {
      // on case -> have to equal
      if(l->l && r->r) {
        tmp = fc(l->l, r->r, num, depth - 1);
        if(tmp.size() > ret.size())
          ret = tmp;
      }
      if(l->r && r->l) {
        tmp = fc(l->r, r->l, num, depth - 1);
        if(tmp.size() > ret.size())
          ret = tmp;
      }
    }
    else {
      if(l->l && r->r) {
        tmp = fc(l->l, r->r, 0, depth - 1);
        if(tmp.size() > ret.size())
          ret = tmp;
        return ret;
      }
      if(l->r && r->l) {
        tmp = fc(l->r, r->l, 0, depth - 1);
        if(tmp.size() > ret.size())
          ret = tmp;
        return ret;
      }
      if(l->l && r->l) {
        tmp = fc(l->l, r->l, num, depth - 1);
        if(tmp.size() > ret.size())
          ret = tmp;
      }
      if(l->r && r->r) {
        tmp = fc(l->r, r->r, num, depth - 1);
        if(tmp.size() > ret.size())
          ret = tmp;
      }
    }
    return ret;
  }
  void add(node *nd, int num, int depth) {
    ++nd->cnt;
    if(depth == -1) {
      nd->v.pb(num);
      return;
    }
    if((1 << depth) & num) {
      // go right
      if(!nd->r)
        nd->r = new node();
      add(nd->r, num, depth - 1);
    }
    else {
      // go left
      if(!nd->l)
        nd->l = new node();
      add(nd->l, num, depth - 1);
    }
  }
  int calc(int dur) {
    return calc(head, dur, 29);
  }
  int calc(node *nd, int dur, int depth) {
    // cerr << dur << " " << depth << endl;
    int ldp = 0, rdp = 0;
    int ret = 0;
    if((1 << depth) > dur) {
      if(nd->l)
        ldp = calc(nd->l, dur, depth - 1);
      if(nd->r)
        rdp = calc(nd->r, dur, depth - 1);
      ret = ldp + rdp;
    }
    else {
      // find left and right that complements each other
      if(nd->l && nd->r) {
        vector<int> cur = fc(nd->l, nd->r, dur, depth - 1);
        ret = cur.size();
        for(auto x : cur)
          res.pb(x);
        if(ret == 0) 
          goto L2; 
      }
      else if(nd->l || nd->r) {
        L2:
        node *tmp = nd;
        while(tmp->l || tmp->r) {
          if(tmp->l)
            tmp = tmp->l;
          else if(tmp->r)
            tmp = tmp->r;
        }
        res.pb(tmp->v[0]);
        ret = 1;
      }
      else
        ret = 0;
    }
    if(nd->cnt && ret == 0) {
      res.pb(nd->v[0]);
      ret = 1;
    }
    return ret;
  }
  void del(node *nd) {
    if(nd->l)
      del(nd->l);
    if(nd->r)
      del(nd->r);
    nd->v.clear();
    delete nd;
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  trie t;
  for(int i = 1; i <= n; ++i)
    cin >> a[i], t.add(a[i]);
  if(k == 0) {
    cout << n << endl;
    for(int i = 1; i <= n; ++i)
      cout << i << " ";
    cout << endl;
    return 0;
  }
  // > msb -> left and right are completely disjoint, only internal matters. just sum 
  // <= msb -> left and right are not disjoint, if left exists, then right must be a "complement" of it same thing works in opposite
  // case bit on: AT MOST one left and AT MOST one right
  // then when = msb, try find left and right that are complements of each other. if yes -> 2, no -> 1, none exists -> 0
  int mx = t.calc(k);
  if(mx < 2) {
    cout << -1 << endl;
  }
  else {
    t.del(t.head);
    map<int, int> memo;
    for(int i = 1; i <= n; ++i)
      memo[a[i]] = i;
    cout << mx << endl;
    vector<int> ans;
    for(auto x : res)
      ans.pb(memo[x]);
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    for(auto x : ans)
      cout << x << " ";
    cout << endl;
  }
  return 0;
}