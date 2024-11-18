#include <bits/stdc++.h>
using namespace std;

int a[200002];
bool needed[200002][18][2];
vector<int> dp[200002][18][2], tmp1, tmp2;

void merge(vector<int> &ret, vector<int> &l, vector<int> &r) {
	for (int i = 0, j = 1; i < l.size(); i += j, j <<= 1) {
		for (int k = i; k < i + j && k < l.size(); k++) ret.push_back(l[k]);
		for (int k = i; k < i + j && k < r.size(); k++) ret.push_back(r[k]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);

	needed[1][0][1] = 1;
	for (int node = 1; node <= n / 2; node++) {
		for (int i = 0; node >> i; i++)
			for (int j : {0, 1}) {
				if (!needed[node][i][j]) continue;

				int mn =
				    min({a[((node >> i + 1) << 1) + j], a[2 * node], a[2 * node + 1]});
				if (mn == a[((node >> i + 1) << 1) + j]) {
					needed[2 * node][0][0] = needed[2 * node + 1][0][1] = 1;
				} else if (mn == a[2 * node]) {
					needed[2 * node][i + 1][j] = needed[2 * node + 1][0][1] = 1;
				} else {
					needed[2 * node][0][0] = needed[2 * node][i + 1][j] = 1;
					needed[2 * node + 1][0][0] = needed[2 * node + 1][i + 1][j] = 1;
				}
			}
	}

	for (int node = n; node; node--) {
		for (int i = 0; node >> i; i++)
			for (int j : {0, 1}) {
				if (!needed[node][i][j]) continue;

				int p = ((node >> i + 1) << 1) + j;
				if (2 * node > n) dp[node][i][j] = {a[p]};
				else if (2 * node == n) {
					dp[node][i][j] = {min(a[p], a[2 * node]), max(a[p], a[2 * node])};
				} else {
					if (a[2 * node + 1] < min(a[p], a[2 * node])) {
						tmp1 = tmp2 = {a[2 * node + 1]};
						merge(tmp1, dp[2 * node][0][0], dp[2 * node + 1][i + 1][j]);
						merge(tmp2, dp[2 * node][i + 1][j], dp[2 * node + 1][0][0]);
						dp[node][i][j] = min(tmp1, tmp2);
					} else {
						dp[node][i][j] = {min(a[p], a[2 * node])};
						if (a[p] < a[2 * node]) {
							merge(dp[node][i][j], dp[2 * node][0][0],
							      dp[2 * node + 1][0][1]);
						} else {
							merge(dp[node][i][j], dp[2 * node][i + 1][j],
							      dp[2 * node + 1][0][1]);
						}
					}
				}
			}
		if (2 * node < n) {
			for (int i = 0; 2 * node >> i; i++)
				for (int j : {0, 1}) {
					vector<int>().swap(dp[2 * node][i][j]);
					vector<int>().swap(dp[2 * node + 1][i][j]);
				}
		}
	}

	for (int i : dp[1][0][1]) printf("%d ", i);
	return 0;
}