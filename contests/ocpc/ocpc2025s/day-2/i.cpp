#include <bits/stdc++.h>
#define ll long long 
#define bit(x) (1LL << (x))
#define ALL(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define fi first
#define se second
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll rand(ll l, ll r) {
  return l + rd() % (r - l + 1);
}

struct Node { 
  ll sum;
  shared_ptr<Node> lef, rig;

  Node(ll sum) : sum(sum), lef(nullptr), rig(nullptr) {};
};

struct PTree {
  vector<shared_ptr<Node>> roots;
  int n;

  PTree(int n) : n(n) {
    roots.push_back(build(0, n - 1));
  };

  shared_ptr<Node> build(int l, int r) {   
    if (l == r) {
      return make_shared<Node>(0);
    }

    int mid = (l + r) >> 1;
    shared_ptr<Node> cur = make_shared<Node>(0);
    cur->lef = build(l, mid);
    cur->rig = build(mid + 1, r);
    return cur;
  }

  shared_ptr<Node> update(shared_ptr<Node> cur, int l, int r, int pos, ll val) {
    if (l > pos || r < pos) {
      return cur;
    }

    if (l == r) {
      return make_shared<Node>(cur->sum ^ val);
    }

    int mid = (l + r) >> 1;
    shared_ptr<Node> res = make_shared<Node>(0);
    res->lef = update(cur->lef, l, mid, pos, val);
    res->rig = update(cur->rig, mid + 1, r, pos, val);
    res->sum = res->lef->sum ^ res->rig->sum;
    return res;
  }

  shared_ptr<Node> update(shared_ptr<Node> cur, int pos, ll val) {
    return update(cur, 0, n - 1, pos, val);
  }
  
  ll getsum(shared_ptr<Node> cur, int l, int r, int u, int v) {
    if (l > v || r < u) {
      return 0;
    }
    
    if (l >= u && r <= v) {
      return cur->sum;
    }

    int mid = (l + r) >> 1;
    return getsum(cur->lef, l, mid, u, v) ^ getsum(cur->rig, mid + 1, r, u, v);
  }

  ll getsum(shared_ptr<Node> cur, int l, int r) {
    return getsum(cur, 0, n - 1, l, r);
  }
};

int main() {

  int q; cin >> q;

  map<int, ll> h;
  auto hashify = [&](int x) -> ll {
    if (!h.count(x)) {
      h[x] = rand(0, bit(60) - 1);
    }
    return h[x];
  };

  vector<int> old(q), tin(q), tout(q), par(q), val(q), cur, newcur;
  vector<vector<int>> adj(q);
  int n = 1;
  PTree g(n);

  auto build = [&]() -> void {
    for (int i = 0; i < n; i++) {
      old[i] = true;
    }

    for (int x : newcur) {
      cur.push_back(x);
    }
    newcur.clear();

    sort(ALL(cur), greater<int>());
    cur.resize(unique(ALL(cur)) - cur.begin());

    int timer = 0;
    auto dfs = [&](auto &&self, int u) -> void {
      tin[u] = tout[u] = timer++;
      for (int v : adj[u]) {
        self(self, v);
        tout[u] = tout[v];
      }
    };

    dfs(dfs, 0);

    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++) {
      events[i] = {val[i], i};
    }

    sort(ALL(events), greater<pair<int, int>>());
    g = PTree(n);

    for (int i = 0; i < sz(events);) {
      int j = i;
      while (j < sz(events) && events[i].fi == events[j].fi) {
        j++;
      }

      shared_ptr<Node> cur = g.roots.back();

      for (int k = i; k < j; k++) {
        int node = events[k].se;
        int val = events[k].fi;
        cur = g.update(cur, tin[node], hashify(val));
        cur = g.update(cur, tout[node] + 1, hashify(val));
        
      }

      g.roots.push_back(cur);

      i = j;
    }
  };

  int one = 0;
  const int S = 500;
  for (int i = 0; i < q; i++) {
    if (one % S == 0) {
      build();
      one++;
    }

    // cerr << i << "\n";

    int op; cin >> op;
    if (op == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      newcur.push_back(x);
      val[n] = x;
      adj[p].push_back(n);
      par[n] = p;
      n++;
      one++;
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;

      vector<int> newval;

      while (!old[a]) {
        newval.push_back(val[a]);
        a = par[a];
      }

      while (!old[b]) {
        // cerr << b << "\n";
        newval.push_back(val[b]);
        b = par[b];
      }

      auto dif = [&](int lim) -> bool {
        ll res = 0;
        for (int x : newval) {
          if (x >= lim) {
            res ^= hashify(x);
          } 
        }

        int ind = upper_bound(ALL(cur), lim, greater<int>()) - cur.begin();
        assert(ind < sz(g.roots));
        res ^= g.getsum(g.roots[ind], 0, tin[a]);
        res ^= g.getsum(g.roots[ind], 0, tin[b]);
    
        return res != 0;
      };  

      int lo = 0;
      int hi = 1e9 + 123;
      while (hi - lo > 1) {
        int mid = (lo + hi) >> 1;
        if (dif(mid)) {
          lo = mid;
        } else {
          hi = mid;
        }
      }

      if (lo == 0) {
        lo = -1;
      }
      cout << lo << endl;
    }
  }
  return 0;
}