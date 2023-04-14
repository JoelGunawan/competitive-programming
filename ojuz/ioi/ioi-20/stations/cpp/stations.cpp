#include "stations.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
int subtree[lim];
bool vis[lim];
vector<int> edges[lim];
void get_subtree(int nd) {
	vis[nd] = 1;
	subtree[nd] = 1;
	for(auto i : edges[nd]) {
		if(!vis[i]) {
			get_subtree(i);
			subtree[nd] += subtree[i];
		}
	}
	//cout << nd << " " << subtree[nd] << endl;
}
vector<int> ret;
void dfs(int nd, int l, int r, bool pos) {
	vis[nd] = 1;
	if(!pos) {
		ret[nd] = l, ++l;
	}
	else {
		ret[nd] = r, --r;
	}
	//cout << nd << " " << l << " " << r << " " << ret[nd] << endl;
	for(auto i : edges[nd]) {
		if(!vis[i]) {
			dfs(i, l, l + subtree[i] - 1, pos ^ 1);			
			//assert(l + subtree[i] - 1 <= r);
			l += subtree[i];
		}
	}
}
vector<int> label(int n, int k, vector<int> u, vector<int> v) {
	for(int i = 0; i < n; ++i)
		edges[i].clear();
	for(int i = 0; i < u.size(); ++i) {
		edges[u[i]].push_back(v[i]);
		edges[v[i]].push_back(u[i]);
	}
	memset(vis, 0, sizeof(vis));
	memset(subtree, 0, sizeof(subtree));
	get_subtree(0);
	ret.resize(n, -1);
	memset(vis, 0, sizeof(vis));
	dfs(0, 0, n - 1, 0);
	// alternate tiap depth
	// ada yg node merupakan r ada yg node merupakan l
	// jadi nanti bisa cari l/r di depth tiap node
	// determine root?
	// always set root to 0 and l
	// depth 1 is set to right
	// depth 2 is set to left and so on
	// 0 child ke border kanan
	// 1 child ke border kiri
	// gimana klo border kiri/kanan conflict dengan child?
	// childnya ngalah
	// jika di l
	// maka child dan par semua di kanan
	// par otomatis merupakan yang paling besar labelnya
	// jika di r
	// maka child dan par semua di kiri
	// par otomatis merupakan yang paling kecil
	return ret;
}

int find_next_station(int s, int t, vector<int> c) {
	// cek c nya
	// kalo s 0 itu base case
	// berarti nanti cari childnya
	// kalo misal bukan, cek c nya itu lebih dari s atau semua kurang dari s
	if(s == 0) {
		// semua childnya r
		for(int i = 0; i < c.size(); ++i) {
			if(t <= c[i])
				return c[i];
		}
	}
	bool small = c[0] < s;
	if(small) {
		// if c < s berarti s ini r terus sisanya l
		// yang paling kecil itu par
		// childnya indicate left
		vector<pair<int, pair<int, int>>> seg;
		int pr = s - 1; 
		for(int i = c.size() - 1; i >= 1; --i) {
			seg.push_back(make_pair(c[i], make_pair(c[i], pr)));
			pr = c[i] - 1;
		}
		for(int i = 0; i < seg.size(); ++i) {
			if(t >= seg[i].second.first && t <= seg[i].second.second)
				return seg[i].first;
		}
		return c.front();
	}
	else {
		// s ini l sisanya r
		// yg par yang paling besar
		vector<pair<int, pair<int, int>>> seg;
		int pr = s + 1;
		for(int i = 0; i < c.size() - 1; ++i) {
			seg.push_back(make_pair(c[i], make_pair(pr, c[i])));
			pr = c[i] + 1;
		}
		for(int i = 0; i < seg.size(); ++i) {
			if(t >= seg[i].second.first && t <= seg[i].second.second)
				return seg[i].first;
		}
		return c.back();
	}
}
