#include "dna.h"
#include <bits/stdc++.h>
using namespace std;
int n;
const int lim = 1e5 + 5;
int cnt[2][3][lim];
int pref[3][3][lim];
char av[] = {'A', 'C', 'T'};
void init(std::string a, std::string b) {
	n = a.size();
	// init count of c a t
	// ac
	// ca
	// at
	// ta
	// tc
	// ct
	for(int i = 0; i < n; ++i) {
		if(i != 0) {
			for(int j = 0; j < 3; ++j)
				for(int k = 0; k < 2; ++k)
					cnt[k][j][i] = cnt[k][j][i - 1];
		}
		for(int j = 0; j < 3; ++j) {
			if(av[j] == a[i])
				++cnt[0][j][i];
			if(av[j] == b[i])
				++cnt[1][j][i];
		}
		for(int j = 0; j < 3; ++j) {
			for(int k = 0; k < 3; ++k) {
				if(i != 0)
					pref[j][k][i] = pref[j][k][i - 1];
				if(av[j] == a[i] && av[k] == b[i])
					++pref[j][k][i];
			}
		}
	}
}

int get_distance(int x, int y) {
	vector<int> cura, curb;
	for(int i = 0; i < 3; ++i) {
		int tmp1 = cnt[0][i][y], tmp2 = cnt[1][i][y];
		if(x != 0)
			tmp1 -= cnt[0][i][x - 1], tmp2 -= cnt[1][i][x - 1];
		cura.push_back(tmp1), curb.push_back(tmp2);
	}
	if(cura != curb)
		return -1;
	int cur[3][3];
	memset(cur, 0, sizeof(cur));
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			int tmp = pref[i][j][y];
			if(x != 0)
				tmp -= pref[i][j][x - 1];
			cur[i][j] = tmp;
		}
	}
	int ans = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(i == j) {
				cur[i][j] = 0;
			}
			int tmp = min(cur[i][j], cur[j][i]);
			ans += tmp;
			cur[i][j] -= tmp;
			cur[j][i] -= tmp;
		}
	}
	int sisa = 0;
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			sisa += cur[i][j];
		}
	}
	return ans + 2 * sisa / 3;
}
