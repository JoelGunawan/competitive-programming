#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 1e5 + 5;
int st[lim], en[lim], par[17][lim], depth[lim];
vector<int> tour, edges[lim];
bool vis[lim];

int t;
void dfs(int nd) {
  st[nd] = t++;
  tour.pb(nd);
  vis[nd] = 1;
  for (int i = 1; i < 17; ++i) {
    par[i][nd] = par[i - 1][par[i - 1][nd]];
  }
  for (auto c : edges[nd]) {
    if (!vis[c]) {
      depth[c] = depth[nd] + 1;
      par[0][c] = nd;
      dfs(c);
    }
  }
  tour.pb(nd);
  en[nd] = t++;
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);

  for (int i = 16; i >= 0; --i) {
    if (depth[par[i][u]] >= depth[v]) u = par[i][u];
  }

  if (u == v) return u;

  for (int i = 16; i >= 0; --i) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }

  return par[0][u];
}

struct Query {
  int l, r;
  int special = -1; // special additional point query

  int num;
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int n;
  cin >> n;

  vector<int> compress;
  bool boy[n + 5];
  vector<int> number(n + 5, 0);
  for (int i = 1; i <= n; ++i) {
    int val;
    cin >> val;
    boy[i] = val;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> number[i];
    compress.push_back(number[i]);
  }
  sort(compress.begin(), compress.end());
  compress.resize(unique(compress.begin(), compress.end()) - compress.begin());

  for (int i = 1; i <= n; ++i) {
    number[i] = lb(compress.begin(), compress.end(), number[i]) - compress.begin();
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].pb(v);
    edges[v].pb(u);
  }

  depth[1] = 1;
  dfs(1);

  // two cases, either: 
  // - parent case: do one range query
  // - non-parent case: one range query + additional small case
  int q;
  cin >> q;
  // cerr << "DEB " << q << endl;
  vector<Query> queries;
  for (int i = 1; i <= q; ++i) {
    int u, v;
    cin >> u >> v;
    if (st[u] > st[v]) swap(u, v);
    Query que;
    if (u == lca(u, v)) {
      que.l = st[u];
      que.r = st[v];
    } else {
      que.l = en[u];
      que.r = st[v];
      // point query on this thing
      que.special = st[lca(u, v)];
    }
    que.num = i;
    queries.push_back(que);
  }

  vector<int> cnt_boy(n + 5, 0), cnt_girl(n + 5, 0), cnt(n + 5, 0);
  // sort by block, then by r
  int blk_sz = sqrt(n);
  sort(queries.begin(), queries.end(), [blk_sz] (const auto &lhs, const auto &rhs) {
    return lhs.l / blk_sz == rhs.l / blk_sz ? lhs.r < rhs.r : lhs.l / blk_sz < rhs.l / blk_sz;
  });

  int cl = 0, cr = -1;
  ll res = 0;
  ll ans[q + 5];
  auto ck = [&res, &cnt_boy, &cnt, &cnt_girl, &boy, &number] (int val) {
    ++cnt[val];
    if (cnt[val] & 1) {
      // add
        if (boy[val]) {
          ++cnt_boy[number[val]];
          res += cnt_girl[number[val]];
        } else {
          ++cnt_girl[number[val]];
          res += cnt_boy[number[val]];
        }
    } else {
        // remove
        if (boy[val]) {
          --cnt_boy[number[val]];
          res -= cnt_girl[number[val]];
        } else {
          --cnt_girl[number[val]];
          res -= cnt_boy[number[val]];
        }
      }
  };

  // cerr << __LINE__ << endl;

  for (auto q : queries) {
    // cerr << __LINE__ << endl;
    while (cr < q.r) {
      // go right
      ++cr;
      ck(tour[cr]); 
    }
    // cerr << __LINE__ << endl;

    while (cr > q.r) {
      // go left
      ck(tour[cr]);
      --cr;
    }
    // cerr << __LINE__ << endl;

    while (cl < q.l) {
      // go right
      ck(tour[cl]); 
      ++cl;
    }
    // cerr << __LINE__ << endl;

    while (cl > q.l) {
      // go left
      --cl;
      ck(tour[cl]);
    }
    // cerr << __LINE__ << endl;

    auto print = [&res, &cnt_boy, &cnt_girl, &n, &q, &tour] () {
      return;
      cerr << "Query details: " << q.l << " " << q.r << " " << q.special << endl;
      cerr << "Result is: " << res << endl;
      cerr << "Boys:" << endl;
      for (int i = 0; i < n; ++i) {
        cerr << cnt_boy[i] << " ";
      }
      cerr << endl;
      cerr << "Girls:" << endl;
      for (int i = 0; i < n; ++i) {
        cerr << cnt_girl[i] << " ";
      }
      cerr << endl;
      for (auto val : tour) {
        cerr << val << " ";
      }
      cerr << endl;
    };
    if (q.special != -1) {
      print();
      ck(tour[q.special]);
      ans[q.num] = res;
      print();
      ck(tour[q.special]);
    } else {
      ans[q.num] = res;
      print();
    }
    // cerr << __LINE__ << endl;
  }

  for (int i = 1; i <= q; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
}