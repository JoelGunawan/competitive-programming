#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define ll long long
using namespace std;
const int lim = 1 << 18;
const ll inf = 1e18;
struct lazy_seg {
  ll a[lim << 1], lazy[lim << 1];
  lazy_seg() {
    fill(a, a + (lim << 1), inf);
    fill(lazy, lazy + (lim << 1), inf);
  }
  void prop(int nd, int cl, int cr) {
    if(cl != cr) {
      lazy[2 * nd] = min(lazy[2 * nd], lazy[nd]);
      lazy[2 * nd + 1] = min(lazy[2 * nd + 1], lazy[nd]);
    }
    a[nd] = min(a[nd], lazy[nd]);
    lazy[nd] = inf;
  }
  void update(int nd, int cl, int cr, int l, int r, ll val) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) {
      lazy[nd] = min(lazy[nd], val);
      prop(nd, cl, cr);
    }
    else if(cl > r || cr < l)
      return;
    else {
      int mid = (cl + cr) >> 1;
      update(nd << 1, cl, mid, l, r, val);
      update((nd << 1) + 1, mid + 1, cr, l, r, val);
      a[nd] = min(a[nd << 1], a[(nd << 1)] + 1);
    }
  }
  void update(int l, int r, ll val) {
    update(1, 0, lim - 1, l, r, val);
  }
  ll query(int nd, int cl, int cr, int l, int r) {
    prop(nd, cl, cr);
    if(cl >= l && cr <= r) 
      return a[nd];
    else if(cl > r || cr < l)
      return inf;
    else {
      int mid = (cl + cr) >> 1;
      return min(query(nd << 1, cl, mid, l, r), query((nd << 1) + 1, mid + 1, cr, l, r));
    }
  }
  ll query(int l, int r) {
    return query(1, 0, lim - 1, l, r);
  }
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k, t, p, q;
  cin >> n >> m >> k >> t >> p >> q;
  // dijkstra ez?
  // for each node maintain the min/min train to the left/right (worst case use angkot)
  // we can consider express trains as an independent edge
  // tiap naik kereta -> ada case sendiri (naik turun kereta ada cost)
  // cost naik turun kereta bisa dianggap sebagai auxiliary node (dimana indegree sm outdegreenya beda)
  // tiap node ada 2 case, dia di kereta atau dia ga di kereta
  // transisi costnya juga bakalan beda
  // 1 ... n -> kereta
  // n + 1 ... 2n -> luar kereta
  vector<pair<int, ll>> edges[2 * n + 5];
  for(int i = 1; i <= n; ++i) {
    edges[i].pb(mp(i + n, 0));
    edges[i + n].pb(mp(i, t));
  }
  // cout << "DEBUG" << endl;
  for(int i = n + 1; i < 2 * n; ++i) {
    // cout << "EDGE " << i << " " << i + 1 << " " << k << endl;
    // cout << "EDGE " << i + 1 << " " << i << " " << k << endl;
    edges[i].pb(mp(i + 1, k)), edges[i + 1].pb(mp(i, k));
  }
  
  // cout << "DEBUG" << endl;
  lazy_seg l, r;
  for(int i = 1; i <= m; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    edges[a].pb(mp(b, d));
    edges[b].pb(mp(a, d));
    // cout << "EDGE " << a << " " << b << " " << d << endl;
    // cout << "EDGE " << b << " " << a << " " << d << endl;
    // set min between a to b - 1 right as c
    // set min between a + 1 to b left as c
    r.update(a, b - 1, c);
    l.update(a + 1, b, c);
  }
  // cout << "DEBUG" << endl;
  for(int i = 1; i <= n; ++i) {
    ll cl = l.query(i, i), cr = r.query(i, i);
    if(cl != inf) {
      // cout << "EDGE " << i << " " << i - 1 << " " << cl << endl;
      edges[i].pb(mp(i - 1, cl));
    }
    if(cr != inf) {
      // cout << "EDGE " << i << " " << i + 1 << " " << cr << endl;
      edges[i].pb(mp(i + 1, cr));
    }
  }
  // dijkstra from p to q
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push(mp(0, p + n));
  ll dist[2 * n + 5];
  fill(dist, dist + 2 * n + 5, inf);
  while(pq.size()) {
    ll d = pq.top().fi; int nd = pq.top().se;
    pq.pop();
    if(dist[nd] <= d)
      continue;
    dist[nd] = d;
    for(auto x : edges[nd]) {
      if(d + x.se < dist[x.fi])
        pq.push(mp(d + x.se, x.fi));
    }
  }
  cout << min(dist[q], dist[q + n]) << endl;
}