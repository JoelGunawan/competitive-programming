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
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
  if(b < 0)
    return 0;
  if(b == 0) 
    return 1;
  else {
    ll tmp = powmod(a, b >> 1);
    tmp = (tmp * tmp) % mod;
    return b & 1 ? (tmp * a) % mod : tmp;
  }
}
struct pt {
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ll c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

bool ccw(pt p, pt q, pt r) { // counter-clockwise
	return ((q-p)^(r-q)) > 0;
}
ll res = 0;
ll mul(ll a, ll b) {
  return (a * b) % mod;
}
ll cost(pt x, pt y) {
  // calculate cost from pt x to pt y
  // fi -> diff in time
  // se -> test case
  ll time_diff = abs(x.x - y.x);
  ll test_case = abs(x.y - y.y);
  if(time_diff == 0) 
    return 0;
  ll a = test_case / time_diff, b = test_case % time_diff;
  // cout << "add to cost: " << time_diff << " " << test_case << endl;
  // cout << "init times: " << x.x << " " << y.x << endl;
  // cout << "init test cases: " << x.y << " " << y.y << endl;
  // b has to be a + 1, time_diff - b has to be a
  return (mul(b, powmod(3, a)) + mul(time_diff - b, powmod(3, a - 1))) % mod;
}
struct upper {
	set<pt> se;
	set<pt>::iterator it;

	int is_under(pt p) { // 1 -> inside ; 2 -> border
		it = se.lower_bound(p);
		if (it == se.end()) return 0;
		if (it == se.begin()) return p == *it ? 2 : 0;
		if (ccw(p, *it, *prev(it))) return 1;
		return ccw(p, *prev(it), *it) ? 0 : 2;
	}
	void insert(pt p) {
		if (is_under(p)) return;

		if (it != se.end()) while (next(it) != se.end() and !ccw(*next(it), *it, p)) {
      // do deletion steps
      auto pr = it, nx = it;
      if(it != se.begin()) {
        --pr, ++nx;
        assert(nx != se.end() && it != se.begin());
        res -= cost(*it, *nx);
        res += cost(*pr, *nx);
        res -= cost(*pr, *it);
        res %= mod;
      }
			it = se.erase(it);
    }
		if (it != se.begin()) while (--it != se.begin() and !ccw(p, *it, *prev(it))) {
      // do deletion steps
      auto pr = it, nx = it;
      --pr;
      assert(it != se.begin());
      if(it != se.end() && ++nx != se.end()) {
        assert(nx != se.end());
        res += cost(*pr, *nx);
        res -= cost(*pr, *it);
        res -= cost(*it, *nx);
      }
      else{
        res -= cost(*pr, *it);
      }
      res %= mod;
			it = se.erase(it);
    }
    if(se.size()) {
      // do insertion steps
      it = se.lb(p);
      auto pr = it;
      if(it != se.begin()) {
        --pr, res += cost(*pr, p);
        if(it != se.end())
          res -= cost(*pr, *it);
      }
      if(it != se.end())
        res += cost(p, *it);
      res %= mod;
    }
		se.insert(p);
    while(se.size() >= 2 && (*--(--se.end())).y >= (*--se.end()).y) {
      // do deletion steps
      res -= cost(*--(--se.end()), *--se.end());
      res %= mod;
      se.erase(--se.end());
    }
	}
};

struct dyn_hull { // 1 -> inside ; 2 -> border
	upper U, L;

	int is_inside(pt p) {
		int u = U.is_under(p), l = L.is_under({-p.x, -p.y});
		if (!u or !l) return 0;
		return max(u, l);
	}
	void insert(pt p) {
		U.insert(p);
		L.insert({-p.x, -p.y});
	}
	int size() {
		int ans = U.se.size() + L.se.size();
		return ans <= 2 ? ans/2 : ans-2;
	}
};
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  // calculate cost using dynamic convex hull, when deleting a line, delete the costs associated with that line too
  int d;
  cin >> d;
  upper uh;
  uh.insert(pt(0, 0));
  for(int i = 1; i <= d; ++i) {
    ll x, y;
    cin >> x >> y;
    uh.insert(pt(x, y));

    ll a = res;
    a %= mod;
    if(res < 0)
      a += mod;
    cout << a << endl;
  }
  return 0;
}