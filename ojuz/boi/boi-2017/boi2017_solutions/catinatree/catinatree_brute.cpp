// brute force solution using the greedy approach
// i believe that greedy (level by level, starting from the bottom) should work, but this implementation should be too slow - O(n^2) in the worst case

#include <iostream>
#include <climits>
#include <iomanip>
#include <vector>
#include <array>

using namespace std;

int n, d;
int depth[201010];
int par[201010];
vector<int> G[201010];
vector<int> byd[201010];
bool removed[201010];

void rm(int v, int r, int p = -1, int de = 0) {
	removed[v] = true;
	if(r > 1) {
		for(int x : G[v]) {
			if(x == p) continue;
			rm(x, r - 1, v, de + 1);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> d;
	byd[0].push_back(0);
	for(int i = 1; i < n; ++i) {
		cin >> par[i];
		depth[i] = depth[par[i]] + 1;
		byd[depth[i]].push_back(i);
		G[par[i]].push_back(i);
		G[i].push_back(par[i]);
	}
	
	int ret = 0;
	for(int x = n + 5; x >= 0; --x) {
		for(int v : byd[x]) {
			if(removed[v]) continue;
			++ret;
			rm(v, d);
		}
	}
	
	cout << ret << '\n';
	
	return 0;
}
