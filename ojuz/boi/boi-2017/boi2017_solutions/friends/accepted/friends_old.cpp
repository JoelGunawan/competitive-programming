#include<stdio.h>
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

int n,p,q;
vector<vector<int> > G;

vector<bool> visited; // already put in some previous group
vector<bool> in; // active group
vector<bool> undecided; // neighbors of active group, may go into active group.
stack<int> undecidedStack; // a stack of the yet undecided neighbors of the active group
vector<bool> out; // neighbors of active group, may NOT go into active group.

bool branchWithFirstVertexOut(int groupSize, int neighSize);
bool mainBranch(int groupSize, int neighSize);
bool branchWithFirstVertexInGroup(int groupSize, int neighSize);
bool findgroup(int v);

// ----------------------------------------
// ---------------------------------------------- MAIN GREEDY
// ----------------------------------------

int main() {

	scanf("%d %d %d",&n, &p, &q);
	G = vector<vector<int> > ();
	bool success = true;

	// read graph	
	for(int i = 0; i < n && success; ++i) {
		int mi;
		scanf("%d", &mi);
		if(mi > p + q) success = false;
		G.push_back(vector<int> (mi, 0));
		for(int j = 0; j < mi; ++j) {
			scanf("%d", &(G[i][j]));
		}
	}
	
	// verify undirected
	for(int u = 0; u < n && success; ++u) {
		for(int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			bool foundu = false;
			for(int j = 0; j < G[v].size(); ++j) {foundu |= (G[v][j] == u);}
			success &= foundu;
		}
	}
	
	// check that each vertex can be put in some group.
	visited = vector<bool> (n, false);
	in = vector<bool> (n, false);
	undecided = vector<bool> (n, false);
	out = vector<bool> (n, false);
	
	for(int i = 0; i < n && success; ++i) {
		if(!visited[i] && !findgroup(i)) {
			success = false;
			break;
	}}
	
	if(success) printf("home\n"); else printf("detention\n");
	
	return 0;
	
}

// ----------------------------
// ---------------------- HELPER FUCNTIONS FOR BRANCHING ALGORITHM BELOW
// ----------------------------

inline int popUndecided() {
	int v = undecidedStack.top();
	undecidedStack.pop();
	undecided[v] = false;
	return v;
}

inline void pushUndecided(int v) {
	undecided[v] = true;
	undecidedStack.push(v);
}

vector<int> freshNeighbors(int v) {
	vector<int> ans;
	for(int i = 0; i < G[v].size(); ++i) {
		if(!(in[G[v][i]] || undecided[G[v][i]] || out[G[v][i]])) ans.push_back(G[v][i]);
	}
	return ans;
}

// ------------------------------------------------- BRANCHING
// ------------------------------------------------- FINDING IF V CAN BE PUT IN A GROUP
bool findgroup(int v) {
	pushUndecided(v);
	bool ans = branchWithFirstVertexInGroup(0,0);
	popUndecided();
	visited[v] = true;
	return ans;
}

// groupsize is the current size of the group, cutsize is the size of the cut
bool mainBranch(int groupSize, int cutSize) {

	if(groupSize > p || cutSize > q || groupSize + cutSize + undecidedStack.size() > p+q) return false;
	if(undecidedStack.empty()) {return true;}
	return(branchWithFirstVertexOut(groupSize, cutSize) || branchWithFirstVertexInGroup(groupSize, cutSize));

}

bool branchWithFirstVertexOut(int groupSize, int cutSize) {
	int v = popUndecided();
	out[v] = true; 
	for(int i = 0; i < G[v].size(); ++i) {cutSize += in[G[v][i]];}

	bool ans = mainBranch(groupSize, cutSize);
	
	out[v] = false;
	pushUndecided(v);
	
	return ans;
}

bool branchWithFirstVertexInGroup(int groupSize, int cutSize) {
	int v = popUndecided();
	in[v] = true;

	vector<int> nv = freshNeighbors(v);
	for(int i = 0; i < nv.size(); ++i) {pushUndecided(nv[i]);}
	for(int i = 0; i < G[v].size(); ++i) {cutSize += out[G[v][i]];}
	
	bool ans = mainBranch(groupSize + 1, cutSize);
	
	in[v] = false;
	for(int i = 0; i < nv.size(); ++i) {popUndecided();}
	pushUndecided(v);

	if(ans)	visited[v] = true; // If found a group with v in it, v becomes visited. 
	
	return ans;
}
