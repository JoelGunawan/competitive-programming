#include "horses.h"
#include <bits/stdc++.h>
#define ll long long
#define lll __int128_t
using namespace std;
const int lim = 1 << 19;
int mod = 1e9 + 7;
struct max_segment_tree {
	int a[2 * lim];
	max_segment_tree() {
		memset(a, 0, sizeof(a));
	}
	void update(int idx, int val) {
		idx += lim;
		a[idx] = val;
		while(idx) {
			idx >>= 1;
			a[idx] = max(a[2 * idx], a[2 * idx + 1]);
		}
	}
	int query(int nd, int cl, int cr, int l, int r) {
		if(cl >= l && cr <= r) 
			return a[nd];
		else if(cl > r || cr < l)
			return 0;
		else {
			int mid = (cl + cr) / 2;
			return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
		}
	}
};
struct mul_segment_tree {
	int a[2 * lim];
	mul_segment_tree() {
		fill(a, a + 2 * lim, 1);
	}
	void update(int idx, int val) {
		idx += lim;
		a[idx] = val;
		while(idx) {
			idx >>= 1;
			a[idx] = (1ll * a[2 * idx] * a[2 * idx + 1]) % mod;
		}
	}
	int query(int nd, int cl, int cr, int l, int r) {
		if(cl >= l && cr <= r) {
			return a[nd];
		}
		else if(cl > r || cr < l)
			return 1;
		else {
			int mid = (cl + cr) / 2;
			return (1ll * query(2 * nd, cl, mid, l, r) * query(2 * nd + 1, mid + 1, cr, l, r)) % mod;
		}
	}
};
max_segment_tree mxx, mxy;
mul_segment_tree valx;
set<int> nz;
vector<int> x, y;
int n;
int recalc() {
	vector<int> v;
	if(nz.empty()) {
		return mxy.query(1, 0, lim - 1, 0, n - 1);
	}
	auto it = --nz.end();
	ll prmul = 1;
	while(true) {
		v.push_back(*it);
		prmul *= x[v.back()];
		if(prmul >= 1e9)
			break;
		if(it == nz.begin())
			break;
		--it;
	}
	// jadi sekarang isinya v itu indices tp inverted
	reverse(v.begin(), v.end());
	prmul = 1;
	lll res = mxy.query(1, 0, lim - 1, 0, n - 1);
	for(int i = 0; i < v.size(); ++i) {
		prmul = (1ll * prmul * x[v[i]]);
		//cout << i << " " << prmul << " " << mxy.query(1, 0, lim - 1, v[i], (i == v.size() - 1 ? n - 1 : v[i + 1] - 1)) << endl;
		// nanti di sini kita "upgrade" ke next nya
		res = max(res, (lll)prmul * mxy.query(1, 0, lim - 1, v[i], (i == v.size() - 1 ? n - 1 : v[i + 1] - 1)));
	}
	res %= mod;
	return (valx.query(1, 0, lim - 1, 0, v.front() - 1) * res) % mod;
}
int init(int N, int X[], int Y[]) {
	x.resize(N), y.resize(N);
	n = N;
	for(int i = 0; i < N; ++i) {
		mxx.update(i, X[i]), mxy.update(i, Y[i]);
		valx.update(i, X[i]);
		x[i] = X[i];
		y[i] = Y[i];
		if(X[i] != 1)
			nz.insert(i);
	}
	// simpan index yg bukan 1
	// nanti di iterate dr belakang isinya
	// simpan iterator current last element?
	// pakai lower_bound aja, terus dikurangin terus iteratornya
	// maximum per operasi update cmn log (karena sekali panggil lower_bound, sisanya -- O(1))
	return recalc();
}
int updateX(int pos, int val) {	
	// nanti re calculate ulang nilainya :))
	// cmn count lastzero sampe nilai nya > int_mx aja :D
	x[pos] = val;
	int tmp = mxx.query(1, 0, lim - 1, pos, pos);
	if(tmp != 1)
		nz.erase(nz.lower_bound(pos));
	mxx.update(pos, val);
	valx.update(pos, val);
	if(val != 1)
		nz.insert(pos);
	return recalc();
}

int updateY(int pos, int val) {
	y[pos] = val;
	mxy.update(pos, val);
	return recalc();
}
