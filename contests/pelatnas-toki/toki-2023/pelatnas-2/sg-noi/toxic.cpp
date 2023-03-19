#include "toxic.h"
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
//#define endl "\n"
using namespace std;

void determine_type(int n){
	// query_sample(vector<int>())
	// answer_type(int x, char c (R, S, T))
	// base sampah: cari has_toxic
	// determine strong using binary number to query up to 9 at once
	// 210
	// determine has_toxic more efficiently?
	// how??? :sob:
	// determine barengan
	// make groups of size 
	// divide into groups of size 9
	vector<vector<int>> groups;
	for(int i = 1; i <= n; ++i) {
		if(groups.size() == 0 || groups.back().size() >= 8)
			groups.pb({});
		groups.back().pb(i);
	}
	int query_cnt = 0;
	// determine strong ada berapa
	// kalo gada strong ga worth buat bagi jadi kelompok
	// kalo lebih banyak strong, then bagi jadi kelompok worth it else def not worth it?
	//cout << "TEST" << endl;
	vector<vector<int>> has_toxic, no_toxic;
	vector<int> strong, norm, toxic, query;
	for(auto i : groups) {
		query.clear();
		for(int j = 0; j < i.size(); ++j) {
			for(int k = 0; k < (1 << j); ++k) 
				query.pb(i[j]);
		}
		//cout << query.size() << endl;
		//for(auto j : query)
		//	cout << j << " ";
		//cout << endl;
		int res = query_sample(query);
		++query_cnt;
		//cout << res << endl;
		//cout << "SUCC" << endl;
		if(res == (1 << (int)i.size()) - 1) {
			no_toxic.pb(i);
		}
		else {
			vector<int> tmp;
			for(int j = 0; j < i.size(); ++j) {
				if((1 << j) & res) {
					strong.pb(i[j]);
				}
				else
					tmp.pb(i[j]);
			}
			has_toxic.pb(tmp);
		}
	}
	// dari yang has_toxic coba binser
	int found_toxic = has_toxic.size();
	while(has_toxic.size()) {
		vector<int> cur = has_toxic.back();
		has_toxic.pop_back();
		// kita mau determine cur ini toxicnya berapa
		// get half
		//for(auto i : cur)
		//	cout << i << " ";
		//cout << endl;
		if(cur.size() == 1) {
			toxic.pb(cur[0]);
			continue;
		}
		else if(cur.size() == 0) {
			continue;
		}
		query.clear();
		for(int i = 0; i < cur.size() / 2; ++i) {
			query.pb(cur[i]);
		}
		int res = query_sample(query);
		++query_cnt;
		if(res == query.size()) {
			// all in query is not toxic
			for(auto i : query)
				norm.pb(i);
			query.clear();
			for(int i = cur.size() / 2; i < cur.size(); ++i)	
				query.pb(cur[i]);
			has_toxic.pb(query);
		}
		else {
			has_toxic.pb(query);
			query.clear();
			for(int i = cur.size() / 2; i < cur.size(); ++i)	
				query.pb(cur[i]);
			if(found_toxic == 30) {
				// go arah satunya aja
				for(auto i : query)
					norm.pb(i);
			}
			else {
				int res = query_sample(query);
				++query_cnt;
				if(res != query.size()) {
					++found_toxic;
					has_toxic.pb(query);
				}
				else {
					for(auto i : query)
						norm.pb(i);
				}
			}
		}
	}
	// determine toxic dulu, baru determine lainnya
	// determine toxic
	for(auto i : no_toxic) {
		query.clear();
		for(int j = 0; j < i.size(); ++j) {
			for(int k = 0; k < (1 << j); ++k) 
				query.pb(i[j]);
		}
		query.pb(toxic.back());
		int res = query_sample(query);
		++query_cnt;
		for(int j = 0; j < i.size(); ++j) {
			if((1 << j) & res) {
				strong.pb(i[j]);
			}
			else
				norm.pb(i[j]);
		}
	}
	//for(auto i : strong)
	//	cout << i << " ";
	//cout << endl;
	//for(auto i : norm)
	//	cout << i << " ";
	//cout << endl;
	//for(auto i : toxic)
	//	cout << i << " ";
	//cout << endl;
	bool vis[n + 1];
	memset(vis, 0, sizeof(vis));
	for(auto i : strong)
		answer_type(i, 'S'), vis[i] = 1;
	for(auto i : norm)
		answer_type(i, 'R'), vis[i] = 1;
	for(auto i : toxic)
		answer_type(i, 'T'), vis[i] = 1;
	for(int i = 1; i <= n; ++i)
		assert(vis[i]);
	return;
}