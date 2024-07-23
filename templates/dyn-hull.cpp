struct pt {
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

bool ccw(pt p, pt q, pt r) { // counter-clockwise
	return (q-p)^(r-q) > 0;
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

		if (it != se.end()) while (next(it) != se.end() and !ccw(*next(it), *it, p))
			it = se.erase(it);
		if (it != se.begin()) while (--it != se.begin() and !ccw(p, *it, *prev(it)))
			it = se.erase(it);

		se.insert(p);
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