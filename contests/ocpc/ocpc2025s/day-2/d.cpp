#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;

struct node {
  node *c[2];
  int cnt = 0;
  node() {
    c[0] = c[1] = nullptr;
  }
};

struct trie {
  node* head = new node();

  void update(node *nd, int d, int num) {
    ++nd->cnt;
    if(d == -1) {
      return;
    }

    bool nx = num & (1 << d);
    if(!nd->c[nx])
      nd->c[nx] = new node();
    
    update(nd->c[nx], d - 1, num);
  }

  int query(node *nd, int d, int num, int value) {
    if(d == -1) {
      return 0;
    }
  
    bool req = (1 << d) & value;
    bool cur = num & (1 << d);
    if(req) {
      if(nd->c[!cur]) {
        return query(nd->c[!cur], d - 1, num, value);
      }
      else {
        return 0;
      }
    }
    else {
      int ret = 0;
      if(nd->c[!cur]) {
        ret += nd->c[!cur]->cnt;
      }

      if(nd->c[cur]) {
        ret += query(nd->c[cur], d - 1, num, value);
      }

      return ret;
    }
  }
};

const int lim = 4e5 + 5;
const int depth = 20;
int a[lim];
ll res = 0;
map<pair<int, int>, int> pivot;
trie* tries[lim];

void solve(int l, int r) {
  int pv = pivot[mp(l, r)];
  // cerr << "SOLVING " << l << " " << r << endl;
  // cerr << "DEB " << l << " " << r << " " << pivot[mp(l, r)] << endl;
  if(l > r)
    return;
  if(l + 1 == r) {
    if((a[l] ^ a[r]) > max(a[l], a[r])) {
      ++res;
    }
    // cerr << "MAKE " << pv << endl;
    tries[pv] = new trie();
    tries[pv]->update(tries[pv]->head, depth, a[l]);
    tries[pv]->update(tries[pv]->head, depth, a[r]);
    return;
  }
  else if(l == r) {
    // cerr << "MAKE " << pv << endl;
    tries[pv] = new trie();
    tries[pv]->update(tries[pv]->head, depth, a[l]);
    return;
  }
  solve(l, pv - 1), solve(pv + 1, r);
  // cerr << "START " << l << " " << r << " " << res << endl;
  int lpivot = pivot[mp(l, pv - 1)], rpivot = pivot[mp(pv + 1, r)];
  // cerr << l << " " << r << " " << pv << endl;
  if(pv - l <= r - pv) {
    tries[pv] = tries[rpivot];
    // iterate left side
    if(tries[lpivot]) {
      // cerr << lpivot << " " << l << " " << pv - 1 << endl;
      // cerr << "HERE" << endl;
      res += tries[lpivot]->query(tries[lpivot]->head, depth, a[pv], a[pv]);
    }
    for(int i = l; i <= pv; ++i) {
      // cerr << "ADDING " << i << " " << tries[pv]->query(tries[pv]->head, depth, a[i], a[pv]) << endl;
      res += tries[pv]->query(tries[pv]->head, depth, a[i], a[pv]);
    }

    for(int i = l; i <= pv; ++i) {
      tries[pv]->update(tries[pv]->head, depth, a[i]);
    }
  }
  else {
    tries[pv] = tries[lpivot];
    // iterate right side
    if(tries[rpivot])
      res += tries[rpivot]->query(tries[rpivot]->head, depth, a[pv], a[pv]);
    for(int i = pv; i <= r; ++i) {
      res += tries[pv]->query(tries[pv]->head, depth, a[i], a[pv]);
    }

    for(int i = pv; i <= r; ++i) {
      tries[pv]->update(tries[pv]->head, depth, a[i]);
    }
  }
  // cerr << "END " << l << " " << r << " " << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i)
    cin >> a[i];

  tries[0] = nullptr;
  
  vector<int> s;
  int nr[n + 5], nl[n + 5];
  fill(nr, nr + n + 5, n + 1);
  fill(nl, nl + n + 5, 0);

  a[0] = a[n + 1] = 1e9;
  s.push_back(0);
  for(int i = 1; i <= n; ++i) {
    while(a[s.back()] <= a[i]) {
      s.pop_back();
    }

    nl[i] = s.back();
    s.push_back(i);
  }

  s.push_back(n + 1);
  for(int i = n; i >= 1; --i) {
    while(a[s.back()] < a[i])
      s.pop_back();

    nr[i] = s.back();
    s.push_back(i);
  }

  // for(int i = 1; i <= n; ++i) {
  //   cout << nl[i] << " " << nr[i] << endl;  
  // }

  for(int i = 1; i <= n; ++i) {
    pivot[{nl[i] + 1, nr[i] - 1}] = i;
  }

  solve(1, n);

  cout << res << endl;
}