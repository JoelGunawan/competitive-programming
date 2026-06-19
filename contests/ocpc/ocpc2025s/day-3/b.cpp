#include <bits/stdc++.h>
#define bit(x) (1LL << (x))
#define getbit(x, i) (((x) >> (i)) & 1)
#define ALL(x) x.begin(), x.end()
#define ll long long
using namespace std;

struct node {
  node* child[2] = {nullptr, nullptr};
  ll mx = 0;
};

const ll min_lim = -1e16, max_lim = 1e16;
struct pers_segtree {
  vector<node*> roots;

  void update(node *cur, node* old, ll cl, ll cr, ll idx, ll val) {
    if (old) {
      cur->child[0] = old->child[0];
      cur->child[1] = old->child[1];
    }
    cur->mx = max(cur->mx, val);
    if(cl == cr)
      return;
    ll mid = (cl + cr) >> 1;
    if (idx <= mid) {
      if (!cur->child[0]) {
        cur->child[0] = new node();
      }

      update(cur->child[0], old ? old->child[0] : nullptr, cl, mid, idx, val);
    } else {
      if (!cur->child[1]) {
        cur->child[1] = new node();
      }

      update(cur->child[1], old ? old->child[1] : nullptr, mid + 1, cr, idx, val);
    }
  }

  void update(ll idx, ll val) {
    roots.push_back(new node());
    update(roots.back(), roots.size() > 1 ? roots[roots.size() - 2] : nullptr, min_lim, max_lim, idx, val);
  }

  ll query(node *nd, ll cl, ll cr, ll l , ll r) {
    if (!nd || cl > r || cr < l) {
      return 0;
    } else if (cl >= l && cr <= r) {
      return nd->mx;
    } else {
      ll mid = (cl + cr) >> 1;
      return max(query(nd->child[0], cl, mid, l, r), query(nd->child[1], mid + 1, cr, l, r));
    }
  }

  ll query(ll root, ll l, ll r) {
    if (l > r) {
      return 0;
    }
    return query(roots[root], min_lim, max_lim, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;
  ll a[n + 5];
  for(ll i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  pers_segtree seg;
  ll suff[n + 5];
  memset(suff, 0, sizeof(suff));
  seg.update(0, n + 1);
  for(ll i = n; i >= 1; --i) {
    suff[i] = a[i] + suff[i + 1];
    seg.update(suff[i], i);
  }

  ll res = 0;
  ll mn = 0, pr = 0;
  for(ll i = 1; i < n; ++i) {
    pr += a[i];
    ll sf = suff[i + 1];
    if (pr - mn > 0) {
      ll cur = seg.query(n - i - 1, sf - (pr - mn), sf - 1);
      // cerr << "DEBUG " << i << " " << cur - i - 1 << endl;
      res = max(res, cur - i - 1);
    }
    mn = min(mn, pr);
  }

  if(res == 0) {
    cout << -1 << endl;
  } else {
    cout << res << endl;
  }
}