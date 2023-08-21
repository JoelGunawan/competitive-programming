#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<bitset>

using namespace std;

int n,k;
vector<int> degree;
vector<vector<int> > G;

vector<bool> done;
vector<int> current;

vector<int> degOrdering;
vector<int> degOrderingPos;


//for debugging;
vector<int> maxCliqueFound;


void readInput() {
	scanf("%d%d", &n, &k);
	degree = vector<int> (n,0);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &(degree[i]));
		G.push_back(vector<int> (degree[i], 0));
		for(int j = 0; j < degree[i]; ++j) {scanf("%d", &(G[i][j]));}
	}
	done = vector<bool> (n, false);
	current = vector<int> (n, -1);
}

void makeDegeneracyOrdering() {
		queue<int> Q;
		vector<int> reducedDegree(degree);
		
		for(int i = 0; i < n; ++i) {if(reducedDegree[i] <= k) Q.push(i);}
		
		while(!Q.empty()) {
			int v = Q.front(); Q.pop();
			degOrdering.push_back(v);
			for(int i = 0; i < G[v].size(); ++i) {
				int u = G[v][i];
				reducedDegree[u]--;
				if(reducedDegree[u] == k) Q.push(u);
		}}
		
		degOrderingPos = vector<int> (n,0);
		for(int i = 0; i < n; ++i) {degOrderingPos[degOrdering[i]] = i;}
}
		
int maxCliqueSize(int pos) {
	// filter out active vertices
	vector<int> zactive(G[pos]);
	zactive.push_back(pos);
		
	vector<int> active;
	for(int i = 0; i < zactive.size(); ++i) {if(!done[zactive[i]]) active.push_back(zactive[i]);}
	int t = active.size();
	
	// set current
	for(int i = 0; i < t; ++i) current[active[i]] = i;
		
	//cerr << "num active vertices " << t << endl;
	
	// make adjacency matrix as bitmask
	vector<int> adj(t, 0);
	for(int i = 0; i < t; ++i) {
		adj[i] |= 1 << i;
		
		int u = active[i];
		for(int j = 0; j < G[u].size(); ++j) {
				int v = G[u][j];
				adj[i] |= current[v] != -1 ? 1 << current[v] : 0;
		}
	}	
	
	int ans = 0;
	int N = 1 << t;
	for(int s = 0; s < N; ++s) {
		// check if s is a clique:
		int isSet = s;
		for(int p = 0; p < t; ++p) {if(s & (1 << p)) isSet &= adj[p];}
		if(isSet != s) continue;
		
		int card = bitset<12>(s).count();
		ans = max(ans, card);
		
		// keep largest clique for debugginf
		if(card > maxCliqueFound.size()) {
			maxCliqueFound.clear();
			for(int i = 0; i < t; ++i) {if(s & (1 << i)) maxCliqueFound.push_back(active[i]);}
		}
	}
	
	// clear current
	for(int i = 0; i < t; ++i) current[active[i]] = -1;
	
	return ans;
}

// ensure that the max clique found is actually a clique.
void assertClique() {
	for(int i = 0; i < maxCliqueFound.size(); ++i) {
		for(int j = 0; j < maxCliqueFound.size(); ++j) {
			if(i==j) continue;
			bool found = false;
			for(int p = 0; p < G[maxCliqueFound[j]].size(); ++p) {
				found |= G[maxCliqueFound[j]][p] == maxCliqueFound[i];
			}
			if(!found) {
				cerr << "WTF" << endl;
}}}}


int main() {
	readInput();
	makeDegeneracyOrdering();
	
	int best = 0;
	for(int i = 0; i < n; ++i) {
		int v = degOrdering[i];
		int c = maxCliqueSize(v); 
		best = max(best, c);
		done[v] = true;		
	}
	
	assertClique();
	
	printf("%d\n", best);
	return 0;
}