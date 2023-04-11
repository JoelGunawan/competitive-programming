#include "shoes.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a > b;
}

const int lim = 2e5 + 5;

struct fenwick {
	int a[lim];
	fenwick() {
		memset(a, 0, sizeof(a));
	}
	void upd(int idx, int val) {
		idx++;
		while(idx < lim) {
			a[idx] += val;
			idx += idx&-idx;
		}
	}
	int q(int idx) {
		idx++;
		int res = 0;
		while(idx) {
			res += a[idx];
			idx -= idx&-idx;
		}
		return res;
	}
};

long long count_swaps(std::vector<int> s) {
	// cari element yg distancenya paling kecil dr 0
	// based on left terkecil dan right terkecil
	ll res = 0;
	// buat vektor posisi
	// di kanan x -> mendekat
	// di kiri x -> sama aja
	// gmn handle case ini?
	// find pair with min cost but have issue of deletion handling
	// as deletion handling can cause a pair to be more efficient compared to before
	// ex
	// 2 y y 1 1 x x x x 2	
	// deletion of x can cause to be more eff?
	// all shoes same size -> ez
	// shoes i sm type i + n sama -> jadi i + n ke i + 1
	// problem: recalculate greedy buat di awal (atau ga butuh ya)
	// coba aja deh :"D
	int n = s.size();
	vector<int> l[n + 1], r[n + 1];
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] < 0)
			l[-s[i]].push_back(i);
		else
			r[s[i]].push_back(i);
	}	
	priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(comp);
	for(int i = 1; i <= n; ++i) {
		if(l[i].size()) {
			reverse(l[i].begin(), l[i].end());
			reverse(r[i].begin(), r[i].end());
			pq.push(make_pair(l[i].back() + r[i].back(), i));
		}
	}
	int curpos = 0;
	fenwick bit;
	while(pq.size()) {
		int idx = pq.top().second;
		pq.pop();
		res += abs(l[idx].back() - bit.q(l[idx].back()));
		bit.upd(l[idx].back(), 1);
		res += abs(r[idx].back() - bit.q(r[idx].back()));
		bit.upd(r[idx].back(), 1);
		l[idx].pop_back();
		r[idx].pop_back();
		if(l[idx].size())
			pq.push(make_pair(l[idx].back() + r[idx].back(), idx));
	}
	return res;
}
