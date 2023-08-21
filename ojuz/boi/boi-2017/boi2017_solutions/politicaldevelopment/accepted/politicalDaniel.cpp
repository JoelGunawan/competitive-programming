#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<bitset>

using namespace std;

int n,k;
vector<int> degree;
vector<vector<int> > G, Gshort;
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

void makeReducedAdjacencyList() {
	Gshort = vector<vector<int> > (n);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < G[i].size(); ++j) {
			int u = G[i][j];
			if(degOrderingPos[i] < degOrderingPos[u]) Gshort[i].push_back(u);
}}}			

int isAdjacent(int i, int j) {
	if(degOrderingPos[i] > degOrderingPos[j]) return isAdjacent(j, i);
	if(i==j) return 1;
	for(int p = 0; p < Gshort[i].size(); ++p) {if(Gshort[i][p] == j) return 1;}
	return 0;
}

		
int maxCliqueSize(int pos) {
	// filter out active vertices
	vector<int> active(Gshort[pos]);
	active.push_back(pos);
	int t = active.size();
	//cerr << "num active vertices " << t << endl;
	
	// make adjacency matrix as bitmask
	vector<int> adj(t, 0);
	for(int i = 0; i < t; ++i) {
		for(int j = 0; j < t; ++j) {
			adj[i] |= isAdjacent(active[i],active[j]) << j;
	}}
	
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
	makeReducedAdjacencyList();
	
	int best = 0;
	for(int i = 0; i < n; ++i) {
		int c = maxCliqueSize(i); 
		best = max(best, c);	
	}
	
	assertClique();
	
	printf("%d\n", best);
	return 0;
}