#include<stdio.h>
#include<vector>
#include<iostream>
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

	vector<spm> prefixSum;
	prefixSum.push_back(initArray[0]);
	for(int i = 1; i < initArray.size(); ++i) prefixSum.push_back(prefixSum[i-1] + initArray[i]);
	
	// answer queries
	for(int i = 0; i < O; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(a != 0) {
			printf("meow\n");
		} else if((b/K)-1 >= 0) {
			spm ans = prefixSum[b/K-1];
			printf("%lld\n", (ans.M[a%K][b%K] < bigVal ? ans.M[a%K][b%K] : -1));
		} else {
			printf("-1\n");
		}
	}
	
	return 0;
}