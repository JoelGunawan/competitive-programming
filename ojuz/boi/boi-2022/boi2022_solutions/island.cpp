#include <bits/stdc++.h>

using namespace std;

int fnd(int u, vector<int> &p){ // performs path compression
	if(p[u] < 0) return u;
	return p[u] = fnd(p[u], p);
}

void mrg(int u, int v, vector<int> &p, vector<long long> &strength){
	u = fnd(u,p), v = fnd(v,p);
	if(u==v) return;
	if(p[u] > p[v]) swap(u,v); // performs size optimization
	p[u] += p[v];
	p[v] = u;
	strength[u] += strength[v];
}

void dfs(int u, int flag, vector<int> &canwin, vector<vector<int>> &mark){
	canwin[u] &= flag;
	for(int v : mark[u]) dfs(v, canwin[u], canwin, mark);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<int> s(N);
	for(int &x : s) cin >> x;
	vector<vector<int>> g(N);
	for(int i = 0, u, v; i < M; i++){
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v), g[v].push_back(u);
	}
	vector<int> canwin(N,1), p(N,-1), vis(N), inserted(N), rep(N);
	vector<long long> strength(N);
	vector<vector<int>> mark(N);
	vector<pair<int,int>> order(N);
	for(int i = 0; i < N; i++){
		strength[i] = s[i];
		order[i] = {s[i],i};
	}
	sort(order.begin(), order.end());
	for(auto t : order){ // insert nodes in increasing order of weight
		int u = t.second;
		for(int v : g[u]) if(inserted[v]){
			int w = rep[fnd(v,p)]; // components representant
			if(strength[fnd(v,p)] < s[u]){ // this component cannot win
				canwin[w] = 0;
			}
			if(!vis[w]){ // build structure for marking
				mark[u].push_back(w);
				vis[w] = 1;
			}
		}
		for(int v : g[u]) if(inserted[v]) vis[rep[fnd(v,p)]] = 0;
		for(int v : g[u]) if(inserted[v]) mrg(u,v,p,strength);
		rep[fnd(u,p)] = u;
		inserted[u] = 1;
	}
	dfs(order[N-1].second,1,canwin,mark); // propagate marks
	for(int i = 0; i < N; i++) cout << canwin[i];
	cout << "\n";
}
