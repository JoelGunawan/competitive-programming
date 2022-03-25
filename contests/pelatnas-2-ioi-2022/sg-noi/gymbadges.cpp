#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> X, L;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int x;
		cin >> x;
		X.push_back(x);
		// write code here
	}
	for(int i = 0; i < N; i++){
		int l;
		cin >> l;
		L.push_back(l);
	}
	// similar to that greedy CF problem
	// in that virtual contest
	// do greedy by a[i] + b[i]
	// is choosing smallest x[i] always optimal?
	// no
	// di cf -> butuh minimal x, dikurangi y, gaboleh non negatif
	// di sini -> maksimal x, ditambah y, no upper bound
	// greedy by choosing smallest l[i] + x[i] for a given configuration
	// that determines whether a configuration is possible or not
	// to find the dp, we can use a knapsack ish algo
	// and check whether the given configuration is valid
	// dp states -> dp[pos][taken][prevx]
	pair<int, pair<int, int>> g[N];
	for(int i = 0; i < N; ++i) 
		g[i] = make_pair(L[i] + X[i], make_pair(X[i], L[i]));
	sort(g, g + N);
	ll prev = 0;
	int res = 0;
	for(int i = 0; i < N; ++i) {
		if(prev <= g[i].second.second)	
			prev += g[i].second.first, ++res;
	}
	/*
	// dp knapsack based on dp[2][taken] and the dp state is the minimum x
	int dp[2][N + 1];
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	dp[1][0] = 0;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j <= N; ++j) {
			dp[i % 2][j] = dp[(i + 1) % 2][j];
			if(j > 0 && dp[(i + 1) % 2][j - 1] <= g[i].second.second && dp[(i + 1) % 2][j - 1] != -1) {
				if(dp[i % 2][j] == -1) 
					dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + g[i].second.first;
				else 
					dp[i % 2][j] = min(dp[i % 2][j], dp[(i + 1) % 2][j - 1] + g[i].second.first);
			}
		}
	}
	*/
	/*
	for(int i = 0; i <= N; ++i)
		if(dp[(N - 1) % 2][i] != -1)
			res = i;
	*/
	cout << res << endl;
	return 0;
}
