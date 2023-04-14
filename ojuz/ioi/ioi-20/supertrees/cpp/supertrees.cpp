#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1e3 + 5;
struct disjoint_set {
	int h[lim], sz[lim];
	disjoint_set() {
		fill(sz, sz + lim, 1);
		memset(h, -1, sizeof(h));
	}
	int fh(int nd) {
		return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
	}
	bool merge(int x, int y) {
		x = fh(x), y =fh(y);
		if(x != y) {
			if(sz[x] < sz[y])
				swap(x, y);
			h[y] = x;
			sz[x] += sz[y];
		}
		return x != y;
	}
};
int construct(std::vector<std::vector<int>> p) {
	int n = p.size();
	std::vector<std::vector<int>> answer(n, vector<int>(n, 0));
	bool ans = 1;
	disjoint_set one, two;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; ++j) {
			if(p[i][j] == 3) {
				return 0;
			}
			else if(p[i][j] == 2) {
				two.merge(i, j);
			}	
			else if(p[i][j] == 1) {
				// jadiin 1 group
				one.merge(i, j);
				two.merge(i, j);
			}
		}
	}
	// harus exactly one
	// yg path 1 jadiin 1 grup, tempel ke 1 node
	// nanti jadiin groups banyak
	// group 2 -> harus connected component ish style
	// nanti cek tiap grup yg ter konek bs atau ngga
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			if(p[i][j] == 1) {

			}
			else if(p[i][j] == 2) {
				if(one.fh(i) == one.fh(j)) {
					return 0;
				}
			}
			else {
				if(one.fh(i) == one.fh(j) || two.fh(i) == two.fh(j))
					return 0;
			}
		}		
	}
	// every one group connect ke 1, inside two group nanti buat cycle
	// minimal one group inside 2 harus ada 3
	bool vis[n];
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; ++i) {
		//cout << i << " " << one.fh(i) << endl;
		if(i != one.fh(i))
			answer[i][one.fh(i)] = answer[one.fh(i)][i] = 1;
	}
	for(int i = 0; i < n; ++i) {
		if(vis[i])
			continue;
		set<int> onegroup;
		for(int j = i; j < n; ++j) {
			if(two.fh(j) == two.fh(i)) {
				vis[j] = 1;
				onegroup.insert(one.fh(j));
			}
		}
		if(onegroup.size() == 2)
			return 0;
		if(onegroup.size() == 1)
			continue;
		vector<int> tmp;
		for(auto j : onegroup)
			tmp.push_back(j);
		for(int i = 0; i < tmp.size(); ++i) {
			answer[tmp[i]][tmp[(i + 1) % tmp.size()]] = answer[tmp[(i + 1) % tmp.size()]][tmp[i]] = 1;
		}
	}
	build(answer);
	return 1;
}
