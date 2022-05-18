#include "baca_deskripsi.h"
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct node {
	int l = -1, r = -1;
};
struct trie {
	vector<node> a = {node()};
	void update(int nd, int depth, int val) {
		if(depth == -1)
			return;
		else {
			if((1 << depth) & val) {
				if(a[nd].r == -1)
					a[nd].r = a.size(), a.pb(node());
				update(a[nd].r, depth - 1, val);
			}
			else {
				if(a[nd].l == -1)
					a[nd].l = a.size(), a.pb(node());
				update(a[nd].l, depth - 1, val);
			}
		}
	}
	int query(int nd, int depth, int val) {
		//cout << a[nd].l << " " << a[nd].r << " " << depth << " " << val << endl;
		if(depth == -1)
			return 0;
		else {
			if((1 << depth) & val) {
				// go to 0
				//cout << "TEST " << a[nd].l << endl;
				if(a[nd].l == -1) {
					// you're forced to go right
					//cout << depth << " " << val << endl;
					return query(a[nd].r, depth - 1, val);
				}
				else {
					return (1 << depth) + query(a[nd].l, depth - 1, val);
				}
			}
			else {
				// go to 1
				//cout << "TEST " << a[nd].r << endl;
				if(a[nd].r == -1) {
					// forced to go left
					return query(a[nd].l, depth - 1, val);
				}
				else
					return (1 << depth) + query(a[nd].r, depth - 1, val);
			}
		}
	}
};

vector<int> getAnswers(int n, int m, vector<int> A, vector<int> B){
	//cout << "TEST" << endl;
	vector<int> ret;
	trie trie;
	//cout << "TEST" << endl;
	for(auto i : A)
		trie.update(0, 30, i);
	for(auto i : B) 
		ret.pb(trie.query(0, 30, i));
	return ret;
} 
