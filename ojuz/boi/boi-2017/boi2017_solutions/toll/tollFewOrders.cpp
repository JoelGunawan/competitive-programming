#include<stdio.h>
#include<vector>
#include<iostream>
#include<set>
#include<algorithm>

#define llint long long 

using namespace std;

const llint bigVal = ((long long) 100000)*((long long) 100001);
int K;

// shortest path matrix
struct spm {
	vector<vector<llint> > M;
	
	spm(int dim, llint initVal, llint diagVal) {
		M = vector<vector<llint> > (dim, vector<llint> (dim, initVal));
		for(int i = 0; i < dim; ++i) M[i][i] = diagVal;
	}
	
	spm(int dim, llint initVal) {M = vector<vector<llint> > (dim, vector<llint> (dim, initVal));}
	
	inline int dim() {return M.size();}
	
	void print() {
		for(int i = 0; i < M.size(); ++i) {
			for(int j = 0; j < M.size(); ++j) {
				cout << (M[i][j] >= bigVal ? -1 : M[i][j]) << " ";
			}
			cout << endl;
		}
		
	}
};

// overload + to (min,+) product for spm's.
spm operator + (spm L, spm R) {
	int dim = L.dim();
	spm ans(dim, 0, 0);
	for(int i = 0; i < dim; ++i) {
		for(int j = 0; j < dim; ++j) {
			llint cur = L.M[i][0] + R.M[0][j];
			for(int k = 1; k < dim; ++k) {
				llint newVal = L.M[i][k] + R.M[k][j];
				cur = cur < newVal ? cur : newVal;
			}
			ans.M[i][j] = cur;
		}
	}
	return ans;
}

int main() {
	
	int N,M,O;
		
	// read input
	scanf("%d%d%d%d",&K,&N,&M,&O);
	vector<spm> initArray(N/K, spm(K, bigVal, bigVal));	
		
	//vector<spm> initArray(N/K+1, spm(K, bigVal));
	for(int i = 0; i < M; ++i) {
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		initArray[a/K].M[a%K][b%K] = t;
	}
	
	// read queries
	vector<int> qa, qb;
	vector<bool> importantGroup(initArray.size() + 1, false);
	set<int> allImportantGroups;
	
	for(int i = 0; i < O; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		qa.push_back(a); qb.push_back(b);
		if(a/K < b/K) {
			importantGroup[a/K] = true; importantGroup[b/K] = true;
			allImportantGroups.insert(a/K); allImportantGroups.insert(b/K);
		}
	}
	
	/*
	for(set<int>::iterator i = allImportantGroups.begin(); i != allImportantGroups.end(); ++i) {
		cout << (*i) << endl;
	}
	cout << endl;
	*/
	
	
	// make prefix sum beteen important groups
	vector<spm> prefixSum;
	prefixSum.push_back(initArray[0]);
	for(int i = 1; i < initArray.size(); ++i) {
		if(importantGroup[i]) {
			prefixSum.push_back(initArray[i]);
		} else {
			prefixSum.push_back(prefixSum[i-1] + initArray[i]);
		}
	}
	
	/*
	for(int i = 0; i < prefixSum.size(); ++i) {
		prefixSum[i].print();
		cout << endl;
	}
	
	cout << "QUERIES    ------------" << endl;
	*/
	// answer queries
	for(int i = 0; i < O; ++i) {
		int a = qa[i]; int b = qb[i];
		int ag = a/K; int bg = b/K;
		if(bg <= ag) {printf("-1\n"); continue;}
		
		//cout << "query: " << a << " " << b << endl;
		//cout << "groups: " << ag << " " << bg << endl;
		
		// find b's group in important groups
		spm ans(K, bigVal, 0);
		for(set<int>::iterator it = allImportantGroups.find(bg); (*it) > ag; it--) {

			//cout << "adding group" << (*it) - 1 << endl;
			ans = prefixSum[(*it)-1] + ans;
		}
		
/*		
		it++;
		spm ans = prefixSum[(*it)-1];
		
		ans.print();
		cout << endl;
		while((*it) <= bg) {
			it++;		
			ans = ans + prefixSum[(*it)-1];
			
			ans.print();
			cout << endl;
		}
*/		
		printf("%lld\n", (ans.M[a%K][b%K] < bigVal ? ans.M[a%K][b%K] : -1));
	}
	
	return 0;
}