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
	for(int i = 0; i < n; ++i) {
		int mi;
		scanf("%d", &mi);
		G.push_back(vector<int> (mi, 0));
		for(int j = 0; j < mi; ++j) {scanf("%d", &(G[i][j]));}
	}

	visited = vector<bool> (n, false);
	in = vector<bool> (n, false);
	undecided = vector<bool> (n, false);
	out = vector<bool> (n, false);
	
	bool success = true;
	for(int i = 0; i < n; ++i) {
		cout << i << endl;
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
// ------------- finds an inclusion minimal group that can contain v if there is one.
bool findgroup(int v) {
	pushUndecided(v);
	bool ans = branchWithFirstVertexInGroup(0,0);
	popUndecided();
	visited[v] = true;
	
	//---------------- for bug fixing, here all flags except visited should be zero.
	/*
	for(int i = 0; i < n; ++i) {if(newgroup[i]) cout << "NG[" << i << "]" << endl;}
	for(int i = 0; i < n; ++i) {if(neighboursUndecided[i]) cout << "NU[" << i << "]" << endl;}
	for(int i = 0; i < n; ++i) {if(neighborsOut[i]) cout << "NO[" << i << "]" << endl;}
	if(!neihborsUndecidedStack.empty()) {
		cout << "STACK! :";
		while(!neihborsUndecidedStack.empty()) {
			cout << neihborsUndecidedStack.top() << " ";
			neihborsUndecidedStack.pop();
		}
		cout << endl;
	}
	*/
	//----------------
	
	return ans;
}

// groupsize is the current size of the group, cutsize is the size of the cut
bool mainBranch(int groupSize, int cutSize) {
	
	if(groupSize > p || cutSize > q || groupSize + cutSize + undecidedStack.size() > p+q) return false;
	if(undecidedStack.empty()) {
		cout << "found group [";
		for(int i = 0; i < n; ++i) {if(in[i]) cout << i << " ";}
		cout << "] " << endl;
		return true;
	}

	return(branchWithFirstVertexOut(groupSize, cutSize) || branchWithFirstVertexInGroup(groupSize, cutSize));
}

bool branchWithFirstVertexOut(int groupSize, int cutSize) {
	int v = popUndecided();
	out[v] = true; 

	// cout << "OUT " << v << "  gs: " << groupSize << "  ns: " << (neighSize+1) << endl;
	for(int i = 0; i < G[v].size(); ++i) {cutSize += in[G[v][i]];}
	bool ans = mainBranch(groupSize, cutSize);

	// cout << "retOUT " << v << "  gs: " << groupSize << "  ns: " << (neighSize+1) << " ans = " << ans << endl;
	
	out[v] = false;
	pushUndecided(v);
	
	return ans;
}

bool branchWithFirstVertexInGroup(int groupSize, int cutSize) {
	int v = popUndecided();
	in[v] = true;

	vector<int> nv = freshNeighbors(v);
	for(int i = 0; i < nv.size(); ++i) {pushUndecided(nv[i]);}
	
	// cout << "IN " << v << "  gs: " << groupSize + 1 << "  ns: " << (neighSize+newOut.size()) << endl;	
	for(int i = 0; i < G[v].size(); ++i) {cutSize += out[G[v][i]];}
	
	bool ans = mainBranch(groupSize + 1, cutSize);
	// cout << "retIN " << v << "  gs: " << groupSize + 1 << "  ns: " << (neighSize+newOut.size()) << " ans = " << ans << endl;	
	
	in[v] = false;
	for(int i = 0; i < nv.size(); ++i) {popUndecided();}
	pushUndecided(v);

	if(ans)	visited[v] = true; // If found a group with v in it, v becomes visited. 
	
	return ans;
}

	
