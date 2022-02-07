#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define ll long long
#define ld long double
#define si short int
#define i8 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define psi pair<si, si>
#define pi8 pair<i8, i8>
#define pq priority_queue
#define fi first
#define se second
 
#define sqr(x) ((x)*(x))
#define pow2(x) (1ll << (x))
#define debug(x) cout << #x << " = " << (x) << '\n';
#define debugV(x, a) cout << #x << "[" << (a) << "] = " << (x[a]) << '\n';
 
#define yume using
#define wo namespace
#define kanaeyo std
 
yume wo kanaeyo;
 
const ll ModA = 998244353;
const ll ModC = 1e9 + 7;
const ll INF = 1e18;
const ll iINF = 1e9;
const ld EPS = 1e-9;
const ld iEPS = 1e-6;

// solution by albert yr

struct Node {
	ll lenL, lenR, charL, charR, val;
	bool oneSegment;
 
	Node (ll _lenL, ll _lenR, ll _charL, ll _charR, ll _val, bool _oneSegment) : lenL(_lenL), lenR(_lenR), charL(_charL), charR(_charR), val(_val), oneSegment(_oneSegment) {}
 
	void print() {
		debug(lenL);
		debug(lenR);
		debug(charL);
		debug(charR);
		debug(val);
		debug(oneSegment);
		cout << '\n';
	}
};
 
Node Zero = Node(1, 1, 0, 0, 1, 1);
Node One = Node(1, 1, 1, 1, 1, 1);
Node Dummy = Node(-1, -1, -1, -1, -1, 0);
 
inline ll fsum(ll x) {
	return ((1ll * x * (x+1)) >> 1);
}
 
struct SegtreeLazy {
	vector<Node> seg;
	vector<ll> lazy;
 
	SegtreeLazy(ll sz) {
		seg.assign(sz << 2, Dummy);
		lazy.assign(sz << 2, 0);
	}
 
	Node merge(Node le, Node ri) {
		if (le.val == -1) {return ri;}
		if (ri.val == -1) {return le;}
 
		Node ret = Node(le.lenL, ri.lenR, le.charL, ri.charR, le.val + ri.val, 0);
 
		if (le.charR != ri.charL) {
			// new segment
			ret.val -= fsum(le.lenR);
			ret.val -= fsum(ri.lenL);
			ret.val += fsum(le.lenR + ri.lenL);
 
			if (le.oneSegment) {
				ret.lenL = le.lenR + ri.lenL;
			}
			if (ri.oneSegment) {
				ret.lenR = le.lenR + ri.lenL;
			}
			if (le.oneSegment && ri.oneSegment) {
				ret.oneSegment = 1;
			}
		}
 
		return ret;
	}
 
	void buildv(ll pos, ll l, ll r, vector<ll> &v) {
		if (l == r) {
			if (v[l] == 0) {
				seg[pos] = Zero;
			} else {
				seg[pos] = One;
			}
			return;
		}
 
		ll m = (l+r) >> 1, lc = pos << 1, rc = lc + 1;
		buildv(lc, l, m, v);
		buildv(rc, m+1, r, v);
		seg[pos] = merge(seg[lc], seg[rc]);
 
		/*
		debug(pos);
		debug(l);
		debug(r);
		seg[pos].print();
		*/
	}
 
	void updateNode(Node &dest) {
		dest.charL = 1 - dest.charL;
		dest.charR = 1 - dest.charR;
	}
 
	void checkLazy(ll pos) {
		if (lazy[pos]) {
			ll lc = pos << 1, rc = lc + 1;
			lazy[lc] += lazy[pos];
			lazy[rc] += lazy[pos];
	
			if (lazy[pos] & 1ll) {
				updateNode(seg[lc]);
				updateNode(seg[rc]);
			}
 
			lazy[pos] = 0;
		}
	}
 
	void update(ll pos, ll l, ll r, ll ul, ll ur) {
		if (ur < l || r < ul) return;
 
		if (ul <= l && r <= ur) {
			updateNode(seg[pos]);
			lazy[pos]++;
			return;
		}
 
		ll m = (l+r) >> 1ll, lc = pos << 1ll, rc = lc + 1;
		checkLazy(pos);
		update(lc, l, m, ul, ur);
		update(rc, m+1, r, ul, ur);
		seg[pos] = merge(seg[lc], seg[rc]);
	}
 
	Node query(ll pos, ll l, ll r, ll ul, ll ur) {
		if (ur < l || r < ul) return Dummy;
 
		if (ul <= l && r <= ur) {
			return seg[pos];
		}
 
		ll m = (l+r) >> 1ll, lc = pos << 1ll, rc = lc + 1;
		checkLazy(pos);
 
		return merge(query(lc, l, m, ul, ur), query(rc, m+1, r, ul, ur));
	}
};
 
const ll maxN = 2e5 + 5;
ll n, q;
vector<ll> a(1, 2);
SegtreeLazy S = SegtreeLazy(maxN);
 
void solve() {
	cin >> n >> q;
	for (ll x, i = 1; i <= n; i++) {
		cin >> x;
		a.push_back(x);
	}
 
	S.buildv(1, 1, n, a);
 
	for (ll t, l, r, i = 1; i <= q; i++) {
		cin >> t >> l >> r;
		if (t == 1) {
			S.update(1, 1, n, l, r);
		} else {
			Node ans = S.query(1, 1, n, l, r);
			cout << ans.val << '\n';
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int tc;
	//cin >> tc;
	tc = 1;
	while (tc--) {solve();}
}
