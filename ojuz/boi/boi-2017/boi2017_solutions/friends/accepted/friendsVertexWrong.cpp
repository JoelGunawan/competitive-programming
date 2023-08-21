#include<stdio.h>
#include<vector>
#include<iostream>
#include<stack>

using namespace std;

int n,p,q;
vector<vector<int> > G;

vector<bool> visited; // already put in previous group
vector<bool> newgroup; // active group
vector<bool> neighboursUndecided; // neighbors of active group, may go into active group.
stack<int> neihborsUndecidedStack; // a stack of the yet undecided neighbors of the active group
vector<bool> neighborsOut; // neighbors of active group, may NOT go into active group.

bool branchWithFirstVertexOut(int groupSize, int neighSize);
bool mainBranch(int groupSize, int neighSize);
bool branchWithFirstVertexInGroup(int groupSize, int neighSize);
bool findgroup(int v);

// ----------------------------------------
// ---------------------------------------------- MAIN GREEDY
// ----------------------------------------

int main() {
	// read input
	scanf("%d %d %d",&n, &p, &q);
	G = vector<vector<int> > ();
	for(int i = 0; i < n; ++i) {
		int mi;
		scanf("%d", &mi);
		G.push_back(vector<int> (mi, 0));
		for(int j = 0; j < mi; ++j) {scanf("%d", &(G[i][j]));}
	}

	visited = vector<bool> (n, false);
	newgroup = vector<bool> (n, false);
	neighboursUndecided = vector<bool> (n, false);
	neighborsOut = vector<bool> (n, false);
	
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

inline void setIn(int v) {newgroup[v] = true;}
inline void undoSetIn(int v) {newgroup[v] = false;}

inline void setOut(int v) {neighborsOut[v] = true;}
inline void undoSetOut(int v) {neighborsOut[v] = false;}

inline int popUndecidedNeighbor() {
	int v = neihborsUndecidedStack.top();
	neihborsUndecidedStack.pop();
	neighboursUndecided[v] = false;
	return v;
}

inline void pushUndecidedNeighbor(int v) {
	neighboursUndecided[v] = true;
	neihborsUndecidedStack.push(v);
}

inline bool isFreshVertex(int v) {return !(visited[v] || newgroup[v] || neighboursUndecided[v] || neighborsOut[v]);}
inline bool isFreshVisitedVertex(int v) {return visited[v] && !(newgroup[v] || neighboursUndecided[v] || neighborsOut[v]);}

vector<int> freshNeighbors(int v) {
	vector<int> ans;
	for(int i = 0; i < G[v].size(); ++i) {
		if(isFreshVertex(G[v][i])) ans.push_back(G[v][i]);
	}
	return ans;
}

vector<int> freshVisitedNeighbors(int v) {
	vector<int> ans;
	for(int i = 0; i < G[v].size(); ++i) {
		if(isFreshVisitedVertex(G[v][i])) ans.push_back(G[v][i]);
	}
	return ans;
}

// ------------------------------------------------- BRANCHING
// ------------------------------------------------- FINDING IF V CAN BE PUT IN A GROUP
// ------------- finds an inclusion minimal group that can contain v if there is one.
bool findgroup(int v) {
	pushUndecidedNeighbor(v);
	bool ans = branchWithFirstVertexInGroup(0,0);
	popUndecidedNeighbor();
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

// groupsize is the current size of the group, neighsize is the size of the neighbors NOT in group 
bool mainBranch(int groupSize, int neighSize) {
	
	if(groupSize > p || neighSize > q || groupSize + neighSize + neihborsUndecidedStack.size() > p+q) return false;
	if(neihborsUndecidedStack.empty()) {
		cout << "found group [";
		for(int i = 0; i < n; ++i) {if(newgroup[i]) cout << i << " ";}
		cout << "] " << endl;
		return true;
	}

	return(branchWithFirstVertexOut(groupSize, neighSize) || branchWithFirstVertexInGroup(groupSize, neighSize));
}

bool branchWithFirstVertexOut(int groupSize, int neighSize) {
	int v = popUndecidedNeighbor();
	setOut(v);

	// cout << "OUT " << v << "  gs: " << groupSize << "  ns: " << (neighSize+1) << endl;
	
	bool ans = mainBranch(groupSize, neighSize + 1);

	// cout << "retOUT " << v << "  gs: " << groupSize << "  ns: " << (neighSize+1) << " ans = " << ans << endl;
	
	undoSetOut(v);
	pushUndecidedNeighbor(v);
	
	return ans;
}

bool branchWithFirstVertexInGroup(int groupSize, int neighSize) {
	int v = popUndecidedNeighbor();
	setIn(v); 

	vector<int> nv = freshNeighbors(v);
	for(int i = 0; i < nv.size(); ++i) {pushUndecidedNeighbor(nv[i]);}

	vector<int> newOut = freshVisitedNeighbors(v);
	for(int i = 0; i < newOut.size(); ++i) {setOut(newOut[i]); }	
	
	// cout << "IN " << v << "  gs: " << groupSize + 1 << "  ns: " << (neighSize+newOut.size()) << endl;	
	bool ans = mainBranch(groupSize + 1, neighSize + newOut.size());
	// cout << "retIN " << v << "  gs: " << groupSize + 1 << "  ns: " << (neighSize+newOut.size()) << " ans = " << ans << endl;	
	
	undoSetIn(v); 
	for(int i = 0; i < nv.size(); ++i) {popUndecidedNeighbor();}
	for(int i = 0; i < newOut.size(); ++i) {undoSetOut(newOut[i]);}	
	pushUndecidedNeighbor(v);

	if(ans)	visited[v] = true; // If found a group with v in it, v becomes visited. 
	
	return ans;
}

	
