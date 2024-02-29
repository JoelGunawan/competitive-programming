  // header file
  #include <bits/stdc++.h>
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>
  // pragma
  #pragma GCC optimize("Ofast")
  #pragma GCC optimize("unroll-loops")
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
  typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
  const int inf = 1e9;
  struct state {
    int dist, rep, x, y, last, form;
    state(int e, int r, int a, int b, int c, int d) {
      dist = e, rep = r, x = a, y = b, last = c, form = d;
    }
    friend bool operator< (const state& l, const state &r) {
      return tie(l.dist, l.rep) > tie(r.dist, r.rep);
    }
  };
  int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
        cin >> a[i][j];
    pair<int, int> pos[n * n + 1];
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        pos[a[i][j]] = mp(i, j);
      }
    }
    // observe: for every state, it is at most 2 moves, change to rook, 2 moves, change to something else
    // -> dist[n][n][final]
    // observe: it is never optimal to change in the middle except for bishop to knight or knight to bishop
    // changing in the middle to rooks is never optimal because it is always better to just change it at a coord
    // for bishops, it has to be the same parity, otherwise have to change to rook or knight
    // for sequence: bishop bishop change knight -> never optimal (just can use rook for same effect)
    // triple knight -> allowed
    // double bishop -> allowed
    // for sequence: bishop change knight -> can be optimal -> bishop has same diagonal that contains a square reachable by knight
    // for sequence: knight change bishop -> can be optimal -> knight can go somewhere that is same diagonal as resulting point
    // -> dist[n][n][n*n][3] -> 1e4
    // x, y, final, cur
    pair<int, int> dist[n + 1][n + 1][n * n + 1][3];
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        for(int k = 1; k <= n * n; ++k) {
          for(int l = 0; l < 3; ++l)
            dist[i][j][k][l] = mp(inf, inf);
        }
      }
    }
    priority_queue<state> q;
    q.push(state(0, 0, pos[1].fi, pos[1].se, 1, 0));
    q.push(state(0, 0, pos[1].fi, pos[1].se, 1, 1));
    q.push(state(0, 0, pos[1].fi, pos[1].se, 1, 2));
    // 0 -> rook, 1 -> bishop, 2 -> knight
    vector<pair<int, int>> k = {mp(2, 1), mp(2, -1), mp(-2, 1), mp(-2, -1)};
    for(int i = 0; i < 4; ++i)
      k.pb(mp(k[i].se, k[i].fi));
    while(q.size()) {
      state s = q.top();
      q.pop();
      if(s.x < 1 || s.x > n || s.y < 1 || s. y > n || dist[s.x][s.y][s.last][s.form] != mp(inf, inf))
        continue;
      if(mp(s.x, s.y) == pos[s.last + 1]) {
        ++s.last;
      }
      if(dist[s.x][s.y][s.last][s.form] != mp(inf, inf))
        continue;
      dist[s.x][s.y][s.last][s.form] = mp(s.dist, s.rep);
      if(s.last == n * n)
        continue;
      for(int i = 0; i < 3; ++i) {
        q.push(state(s.dist + 1, s.rep + 1, s.x, s.y, s.last, i));
      }
      if(s.form == 0) {
        // rook
        for(int i = 1; i <= n; ++i) {
          q.push(state(s.dist + 1, s.rep, i, s.y, s.last, s.form));
          q.push(state(s.dist + 1, s.rep, s.x, i, s.last, s.form));
        }
      }
      else if(s.form == 1) {
        // bishop
        for(int i = -n + 1; i < n; ++i) {
          q.push(state(s.dist + 1, s.rep, s.x + i, s.y + i, s.last, s.form));
          q.push(state(s.dist + 1, s.rep, s.x + i, s.y - i, s.last, s.form));
        }
      }
      else {
        // knight
        for(auto p : k) {
          q.push(state(s.dist + 1, s.rep, s.x + p.fi, s.y + p.se, s.last, s.form));
        }
      }
    }
    pair<int, int> res = mp((int)inf, (int)inf);
    for(int i = 0; i < 3; ++i)
      res = min(res, dist[pos[n * n].fi][pos[n * n].se][n * n][i]);
    cout << res.fi << " " << res.se << endl;
    return 0;
  }