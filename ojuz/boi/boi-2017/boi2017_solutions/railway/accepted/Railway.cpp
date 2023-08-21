#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, k;

vector<vector<int> > T, ID, ministersInCity;
vector<int> biggestChild, passiveMinisters, onDFSStack, ministerNumCities, importantTracks;

void initialize() {
 	scanf("%d%d%d", &n, &m, &k);
   	
   	passiveMinisters = vector<int> (n, 0); 
   	biggestChild = vector<int> (n, -1);
   	
	//onDFSStack = vector<bool> (n, false);
	for(int i = 0; i < n; ++i) onDFSStack.push_back(false);
    	
	T = vector<vector<int> > (n, vector<int>());
	ID = vector<vector<int> > (n, vector<int>());
	ministersInCity = vector<vector<int> > (n, vector<int>());
    		
   	for(int i = 1; i <= n-1; ++i) {
   		int u, v;
		scanf("%d%d", &u, &v);
   		T[--u].push_back(--v);
   		T[v].push_back(u);
   		ID[u].push_back(i);
   		ID[v].push_back(i);
   	}
		
   	ministerNumCities = vector<int> (m, 0); 
   	for(int i = 0; i < m; ++i) {
   		int si;
		scanf("%d", &si);
		ministerNumCities[i] = si;
    	for(int j = 0; j < si; ++j) {
    		int city;
			scanf("%d", &city);
			ministersInCity[--city].push_back(i);
    	}
   	}
}
    
// when this is over biggestChild[pos] = u for child u with largest subtree. 
int makeBiggestChildDFS(int pos) {
	onDFSStack[pos] = true;
   	int biggestSize = -1, myBiggestChild = -1, ans = 1;
	for(int i = 0; i < T[pos].size(); ++i) {
		int ch = T[pos][i];
   		if(onDFSStack[ch]) continue;
   		int mySize = makeBiggestChildDFS(ch);
   		ans += mySize;
   		if(biggestSize < mySize) {
   			biggestSize = mySize;
   			myBiggestChild = ch;
   		}
   	}
   	biggestChild[pos] = myBiggestChild;
	onDFSStack[pos] = false;
   	return ans;
}
    
// returns for each minister below the tree how many times he appears below the tree
// sets passive-ministers = number of ministers that have appeared entirely in the subtree
// counts the number of important edges
void DFS(int pos, int edgeID, unordered_map<int, int> &ministers) {	
	//cerr << "in " << pos << endl;
	onDFSStack[pos] = true;
	
	if(biggestChild[pos] >= 0) {
		int bigChildPos;
		for(bigChildPos = 0; bigChildPos < T[pos].size(); ++bigChildPos) {if(T[pos][bigChildPos] == biggestChild[pos]) break;}
		DFS(biggestChild[pos], ID[pos][bigChildPos], ministers);
		passiveMinisters[pos] = passiveMinisters[biggestChild[pos]];
	}


	
	unordered_map<int, int> newMinisters;
	for(int i = 0; i < T[pos].size(); ++i) {

		int ch = T[pos][i];

		int chID = ID[pos][i];

		if(onDFSStack[ch] || ch == biggestChild[pos]) continue;
		
 		newMinisters.clear();
		DFS(ch, chID, newMinisters);

		for(auto it = newMinisters.begin(); it != newMinisters.end(); it++) {
			int minister = (*it).first;
			int numOccurences = (*it).second;
			int totalOccurences = ministers[minister] + numOccurences;
			ministers[minister] = totalOccurences;
			if(ministers[minister] == ministerNumCities[minister]) {passiveMinisters[pos]++;}
		}
   	}
		
   	for(int i = 0; i < ministersInCity[pos].size(); ++i) {
		int minister = ministersInCity[pos][i];
		int totalOccurences = ministers[minister] + 1;
		ministers[minister] = totalOccurences;
		if(ministers[minister] == ministerNumCities[minister]) {passiveMinisters[pos]++;}
	}
	
   	if(ministers.size() - passiveMinisters[pos] >= k) importantTracks.push_back(edgeID);
	onDFSStack[pos] = false;	
	//cerr << "out " << pos << endl;
}
    
int main() {
   	initialize();
   	makeBiggestChildDFS(0);
	unordered_map<int, int> dummy;
	DFS(0, -1, dummy);
    	
   	sort(importantTracks.begin(), importantTracks.end());
    printf("%d\n", importantTracks.size());	
   	
   	for(int i = 0; i + 1 < importantTracks.size(); ++i) {printf("%d ", importantTracks[i]);}		
	if(importantTracks.size() != 0) {
		printf("%d\n", importantTracks[importantTracks.size() - 1]); 
	} 
}
