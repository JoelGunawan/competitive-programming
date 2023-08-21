#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, k, myClock;

//indexed by n
vector<vector<int> > T, ID, ministersInCity; //   ,ministersForWhichThisCityIsImportant;
vector<bool> onDFSStack;
vector<int> pre, post, val;
vector<vector<pair<int, int> > > importantCityList; 

  
//indexed by m
vector<vector<int> > importantCitiesOfMinister;
vector<int> possibleRootOfMinister;

//general
vector<int> importantTracks, DFSStack;

// DEBUGGING
void printvec(string s, vector<int> v) {
	cout << s;
	for(int i = 0; i < v.size(); ++i) cout << " " << v[i];
	cout << endl;
} 

void printvecvec(string s, vector<vector<int> > v) {
	cout << s << endl;
	for(int i = 0; i < v.size(); ++i) {
		cout << i;
		printvec(":", v[i]);
	}
}	




void initialize() {
 	scanf("%d%d%d", &n, &m, &k);
   	
	onDFSStack = vector<bool> (n, false);
	pre = vector<int> (n, 0);
	post = vector<int> (n, 0);
	val = vector<int> (n, 0);
    	
	T = vector<vector<int> > (n, vector<int>());
	ID = vector<vector<int> > (n, vector<int>());
	ministersInCity = vector<vector<int> > (n, vector<int>());
    
	// for each city, a list of pairs (minister for which this city is important, ID of this city in that ministers important city list)
	importantCityList = vector<vector<pair<int, int> > > (n, vector<pair<int, int> > ());

   	for(int i = 1; i <= n-1; ++i) {
   		int u, v;
		scanf("%d%d", &u, &v);
   		T[--u].push_back(--v);
   		T[v].push_back(u);
   		ID[u].push_back(i);
   		ID[v].push_back(i);
   	}
	
	possibleRootOfMinister = vector<int> (m, -1);
	importantCitiesOfMinister = vector<vector<int> > (m, vector<int>());
	
   	for(int i = 0; i < m; ++i) {
   		int si;
		scanf("%d", &si);
    	for(int j = 0; j < si; ++j) {
    		int city;
			scanf("%d", &city);
			ministersInCity[--city].push_back(i);
    	}
   	}
}

// prePostDFS
void prePostDFS(int pos) {
	pre[pos] = ++myClock;
	onDFSStack[pos] = true;

	for(int i = 0; i < T[pos].size(); ++i) {
		int ch = T[pos][i];
   		if(onDFSStack[ch]) continue;
		prePostDFS(ch);
   	}
   	
	onDFSStack[pos] = false;
   	post[pos] = ++myClock;
}

void importantCityDFS(int pos) {
	onDFSStack[pos] = true;
	
	for(int i = 0; i < ministersInCity[pos].size(); ++i) {
		int minister = ministersInCity[pos][i];
		while(!importantCitiesOfMinister[minister].empty() && post[importantCitiesOfMinister[minister].back()] > pre[pos]) {
			importantCitiesOfMinister[minister].pop_back(); }
		importantCitiesOfMinister[minister].push_back(pos);
	}
	
	for(int i = 0; i < T[pos].size(); ++i) {
		int ch = T[pos][i];
   		if(onDFSStack[ch]) continue;
		importantCityDFS(ch);
   	}
	
	for(int i = 0; i < ministersInCity[pos].size(); ++i) {
		int minister = ministersInCity[pos][i];
		possibleRootOfMinister[minister] = pos;
	}
	
	onDFSStack[pos] = false;
}

void setPositiveValues() {
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < importantCitiesOfMinister[i].size(); ++j) {
			val[importantCitiesOfMinister[i][j]]++;
	}}
}

void setImportantCityList() {
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < importantCitiesOfMinister[i].size(); ++j) {
			int thisCity = importantCitiesOfMinister[i][j];
			importantCityList[thisCity].push_back(pair<int, int> (i, j));
	}}
}

bool isAncestorOf(int possibleParent, int possibleChild) {return post[possibleParent] > post[possibleChild];}

// computes the LCA of DFSStack[pos] and targetCity, assuming the LCA is abovr or equal to pos on the DFSStack,
// and below (bigger than) or including lb.
int LCA(int pos, int lb, int targetCity) {
	int city = DFSStack[pos];
	//cout << "LCA(" << pos << " " << lb << " " << targetCity << ")" << endl;
	if(lb + 1 >= pos) {
		if(isAncestorOf(city, targetCity)) return city;
		return DFSStack[lb];
	}
	int test = (pos + lb) / 2;
	int testCity = DFSStack[test];
	if(isAncestorOf(testCity, targetCity)) {return LCA(pos, test, targetCity);} 
	return LCA(test, lb, targetCity);
}

void setNegativeValueDFS(int pos) {
	DFSStack.push_back(pos);
	onDFSStack[pos] = true;

	for(int i = 0; i < importantCityList[pos].size(); ++i) {
		int minister = importantCityList[pos][i].first;
		int j = importantCityList[pos][i].second;
		if(j + 1 == importantCitiesOfMinister[minister].size()) continue;
		int nextCity = importantCitiesOfMinister[minister][j+1];
		
		// LCA of pos and nextCity:
		int stackSize = DFSStack.size();
		
		//cout << "computing LCA of " << pos << " " << " and " << nextCity << endl; 
		int minusPos = LCA(stackSize - 1, 0, nextCity);
		
		// update possible root of minister
		if(post[minusPos] > post[possibleRootOfMinister[minister]]) possibleRootOfMinister[minister] = minusPos;
		
		// decrease value!
		//cout << "decreasing city # " << minusPos << " for minister " << minister << endl;
		val[minusPos]--;
	}
	
	for(int i = 0; i < T[pos].size(); ++i) {
		int ch = T[pos][i];
   		if(onDFSStack[ch]) continue;
		setNegativeValueDFS(ch);
   	}
	
	onDFSStack[pos] = false;
	DFSStack.pop_back();
}

void setNegativeRootValues() {
	for(int i = 0; i < m; ++i) {val[possibleRootOfMinister[i]]--;}
}

int findTargetEdgeDFS(int pos, int edgeID) {
	onDFSStack[pos] = true;
	
	int myVal = val[pos];
	for(int i = 0; i < T[pos].size(); ++i) {
		int ch = T[pos][i];
		int chID = ID[pos][i];
   		if(onDFSStack[ch]) continue;
		myVal += findTargetEdgeDFS(ch, chID);
   	}
	
	//cout << "pos " << pos << " myVal " << myVal << endl;
	if(myVal >= k) importantTracks.push_back(edgeID);
	
	onDFSStack[pos] = false;
	return myVal;
}
    
int main() {
   	initialize();
	
	//printvecvec("T:", T);
	//printvecvec("Ministers In City:", ministersInCity);

	prePostDFS(0);
	importantCityDFS(0);
	
	//printvecvec("Important Cities", importantCitiesOfMinister);
	
	setPositiveValues();
	//printvec("Only positive values: ", val);

	setImportantCityList();

	setNegativeValueDFS(0);
	//printvec("Values after removing LCA's: ", val);
	
	//printvec("Roots", possibleRootOfMinister);
	
	setNegativeRootValues();

	//printvec("Values: ", val);
	
	int dummy = findTargetEdgeDFS(0, -1);
	
   	sort(importantTracks.begin(), importantTracks.end());
    printf("%d\n", importantTracks.size());	
   	
   	for(int i = 0; i + 1 < importantTracks.size(); ++i) {printf("%d ", importantTracks[i]);}		
	if(importantTracks.size() != 0) {
		printf("%d\n", importantTracks[importantTracks.size() - 1]); 
	} 
}
