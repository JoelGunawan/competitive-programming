#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,D;
vector<vector<int> > T;
vector<int> opt, optdist, sacrdist;

void DFS(int pos) {
	// Base case: pos is a leaf
	if(T[pos].size() == 0) {
		opt[pos] = 1;
		optdist[pos] = 0;
		sacrdist[pos] = D;
		return;
	}
	
	int v = T[pos][0];
	DFS(v);
	if(optdist[v] + 1 >= D) {
		opt[pos] = opt[v] + 1;
		optdist[pos] = 0;
		sacrdist[pos] = optdist[v] + 1;
	} else {
		opt[pos] = opt[v];
		optdist[pos] = optdist[v] + 1;
		sacrdist[pos] = sacrdist[v] + 1;
	}
	
	for(int i = 1; i < T[pos].size(); ++i) {
		int v = T[pos][i];
		DFS(v);
		
		// distance between closest points and 
		// distance to root
		// in the 4 possible solution combinations. 
		int doo = optdist[pos] + optdist[v] + 1;
		int mdoo = min(optdist[pos], optdist[v] + 1);
		
		int dos = optdist[pos] + sacrdist[v] + 1;
		int mdos = min(optdist[pos], sacrdist[v] + 1);

		int dso = sacrdist[pos] + optdist[v] + 1;
		int mdso = min(sacrdist[pos], optdist[v] + 1);

		int dss = sacrdist[pos] + sacrdist[v] + 1;
		int mdss = min(sacrdist[pos], sacrdist[v] + 1);
		
		if(doo >= D) {
			opt[pos] += opt[v];
			optdist[pos] = mdoo;
			sacrdist[pos] = max(mdos, mdso);
		} else if (dos >= D || dso >= D) {
			opt[pos] += opt[v] - 1;
			if(dos >= D) optdist[pos] = mdos; else optdist[pos] = 0;
			if(dso >= D) optdist[pos] = max(optdist[pos], mdso);
			sacrdist[pos] = mdss;
		} else {
			cout << "error!" << endl;
			exit(0);
		}
	}
}

int main() {
	scanf("%d%d", &N, &D);
    assert(N <= 18);
	T = vector<vector<int> > (N);
	opt = vector<int> (N, 0);
	optdist = vector<int> (N, 0);
	sacrdist = vector<int> (N, 0);
	for(int i = 1; i < N; ++i) {
		int a;
		scanf("%d", &a);
		T[a].push_back(i);
	}
	DFS(0);
	printf("%d\n", opt[0]);
	return 0;
}
