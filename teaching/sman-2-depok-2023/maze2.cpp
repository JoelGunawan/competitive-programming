#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int a[N + 1][M + 1];
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; i <= M; i++) {
			cin >> a[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	
	queue<pair<int, pair<int, int>>> q;
	q.push({1, make_pair(x, y)});
	bool vis[N + 1][M + 1];
	memset(vis, 0, sizeof(vis));
	while(q.size()) {
		int dist = q.front().first; int x = q.front().second.first; int y = q.front().second.second;
		q.pop();
		if(vis[x][y] || a[x][y] == -1) {
			continue;
		} 
		vis[x][y] = 1;
		if(x == 1 || y == 1 || x == N || y == M) {
			cout << dist << endl;
			return 0;
		}
		q.push({dist + 1, make_pair(x + 1, y)});
		q.push({dist + 1, make_pair(x, y + 1)});
		q.push({dist + 1, make_pair(x - 1, y)});
		q.push({dist + 1, make_pair(x, y - 1)});
	}
}