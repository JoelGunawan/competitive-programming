#include<cassert>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<stack>
#include<set>
#include<cstdlib>

using namespace std;

int n,p,q;
vector<vector<int> > G;

vector<bool> visited; // already put in some previous group
vector<bool> in; // active group
vector<bool> undecided; // neighbors of active group, may go into active group.
stack<int> undecidedStack; // a stack of the yet undecided neighbors of the active group
vector<bool> out; // neighbors of active group, may NOT go into active group.

vector<set<int> > output;
vector<int> myGroup;


bool branchWithFirstVertexOut(int groupSize, int neighSize);
bool mainBranch(int groupSize, int neighSize);
bool branchWithFirstVertexInGroup(int groupSize, int neighSize);
bool findgroup(int v);

void fix(int i, int j);
int firstConflict(); 
bool isValidGroup(const set<int> &s);


void printSet(const set<int> &S);
void printPartition();


// ----------------------------------------
// ---------------------------------------------- MAIN GREEDY
// ----------------------------------------

int main() {

	scanf("%d %d %d",&n, &p, &q);
    assert(n <= 250 && q <= 2);
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
	
	myGroup = vector<int>(n, -1);
	
	for(int i = 0; i < n && success; ++i) {
		//cout << i << endl;
		if(visited[i]) continue;
		if(!findgroup(i)) {
			success = false;
			break;
		}
				
		// resolve conflicts between new group and old groups
		int p = output.size() - 1; 
		
		//printf("set:\n");
		//printSet(output[p]);
		
		while(true) {
			int conf = firstConflict();
			//printf("CONF %d\n", conf);
			if(conf == -1) break;
			fix(p, conf);
		}
		
		for(set<int>::iterator it = output[p].begin(); it != output[p].end(); ++it) {myGroup[*it] = p;}
		
		//printf("second\n");
		//printPartition();

	}
	
	if(success) {
		printf("home\n");
		printPartition();
	} else {
		printf("detention\n"); 
	}
	
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
	if(ans) output[output.size() - 1].insert(v);
	visited[v] = true;
	return ans;
}

// groupsize is the current size of the group, cutsize is the size of the cut
bool mainBranch(int groupSize, int cutSize) {

	if(groupSize > p || cutSize > q || groupSize + cutSize + undecidedStack.size() > p+q) return false;
	if(undecidedStack.empty()) {
		output.push_back(set<int>());
		return true;
	}
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
	
	if(ans) {output[output.size() - 1].insert(v);}
	
	in[v] = false;
	for(int i = 0; i < nv.size(); ++i) {popUndecided();}
	pushUndecided(v);

	if(ans)	visited[v] = true; // If found a group with v in it, v becomes visited. 
	
	return ans;
}

int firstConflict() {
	int p = output.size() - 1; 
	if(p < 0) return - 1; 
	for(set<int>::iterator s = output[p].begin(); s != output[p].end(); ++s) {
		if(*s < 0 || *s > n-1) {
			cout << "wtf" << endl;
			exit(0);
		}
		
		if(myGroup[*s] != -1 && myGroup[*s] != p) return myGroup[*s]; }
	return -1;
}

// i is the new group, j is the old one. 
void fix(int i, int j) {
	set<int> si(output[i]), sj(output[j]), nsi(output[i]), nsj(output[j]);
	for(set<int>::iterator it = si.begin(); it != si.end(); ++it) {
		if(sj.count(*it) != 0) {
			nsi.erase(*it);
			nsj.erase(*it);
		}
	}
	
	/*
	printf("si:\n");
	printSet(si);
	printf("nsi:\n");
	printSet(nsi);
	printf("sj:\n");
	printSet(sj);
	printf("nsj:\n");
	printSet(nsj);
	*/
	/*
	if(nsj.empty() && isValidGroup(si)) {
		// cout << "i should be here" << endl;
		// kill the conflict group, update myGroup.
		for(set<int>::iterator it = sj.begin(); it != sj.end(); ++it) {myGroup[*it] = i;}
		output[j] = set<int>();
	} else 
	*/	
	if(isValidGroup(nsi)) {
		// make last group smaller
		printf("nsi was valid\n");
		output[i] = set<int> (nsi);
	} else if(isValidGroup(nsj)) {
		// make the conflict group smaller, update myGroup.
		for(set<int>::iterator it = sj.begin(); it != sj.end(); ++it) {
			if(nsj.count(*it) == 0) myGroup[*it] = i;
		}
		output[j] = set<int> (nsj);
	} else {
		printf("goddammit\n");
		exit(1); 
}}

bool isValidGroup(const set<int> &s) {
	//printf("is valid group:\n");
	//printSet(s);

	int cnt = 0;
	if(s.empty()) return true;
	for(set<int>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		int u = *itr;
		//printf("vertex u: %d\n", u);
		for(int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			cnt += (s.count(G[u][i]) == 0 ? 1 : 0);
			//printf("vertex v: %d   count: %d\n", v, cnt);
		}
	}
	//printf("answer is %d\n", (cnt <= q ? 1 : 0));
	return cnt <= q;
}


void printSet(const set<int> &S) {
	if(S.empty()) return;
	printf("%d", S.size());
	for(set<int>::iterator s = S.begin(); s != S.end(); ++s) {printf(" %d", (*s));}
	printf("\n");
}

void printPartition() {
	// DEBUG:
	//printf("current partition\n");
	// ---
	int numGroups = 0;
	for(int i = 0; i < output.size(); ++i) {if(!output[i].empty()) numGroups++;}
	
	printf("%d\n", numGroups);
	for(int i = 0; i < output.size(); ++i) {
		//cout << "-- " << i << "--  " << endl;
		printSet(output[i]);
	}
}


