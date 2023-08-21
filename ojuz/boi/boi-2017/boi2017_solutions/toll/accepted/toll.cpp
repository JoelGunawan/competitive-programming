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

// binary segment tree for spms without update capability. 
struct bst {
	vector<spm> a;
	int N;
	int offs;
	
	bst(vector<spm> initArray) {
		int n = initArray.size();
		N = 2;
		while(N < 2*n+4) N *= 2;
		offs = N/2 + 1;
		a = vector<spm> (N, spm(K, bigVal, bigVal));
		for(int i = 0; i < n; ++i) a[i+offs] = initArray[i];
		for(int i = offs-2; i > 0; --i) a[i] = a[2*i] + a[(2*i)+1];
	}
	
	spm sum(int i, int j) {
		int L = i + offs - 1;
		int R = j + offs + 1;
		spm Lans(K,bigVal,(llint)0);
		spm Rans(K,bigVal,(llint)0);
		while(true) {
			bool Lright = L%2 == 0;
			bool Rleft = R%2 == 1;
			L /= 2; 
			R /= 2;
			if(L==R) break;
			if(Lright) Lans = Lans + a[2*L+1];
			if(Rleft) Rans = a[2*R] + Rans;
		}
		return Lans + Rans;
	}
};

int main() {
	
	int N,M,O;
		
	// read input
	scanf("%d%d%d%d",&K,&N,&M,&O);
	vector<spm> initArray(N/K, spm(K, bigVal, bigVal));
	for(int i = 0; i < M; ++i) {
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		initArray[a/K].M[a%K][b%K] = t;
	}

	// make bst
	bst T(initArray);
	
	// answer queries
	for(int i = 0; i < O; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		if(a/K >= b/K) {
			printf("-1\n");
		} else {
			spm ans = T.sum(a/K, b/K-1);
			printf("%lld\n", (ans.M[a%K][b%K] < bigVal ? ans.M[a%K][b%K] : -1));
		}
	}
	
	return 0;
}