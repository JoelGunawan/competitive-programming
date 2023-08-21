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
	
	//spm(const spm &cp) {M = vector<vector<llint> > (cp.M);}
	
	inline int dim() {return M.size();}
};

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
	
	// answer queries
	for(int i = 0; i < O; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ag = a/K, bg = b/K;
		
		if(bg <= ag) {
			printf("-1\n");
		} else {
			vector<llint> ans (K, bigVal);
			ans[a%K] = 0;
			
			for(int g = ag; g < bg; ++g) {
				vector<llint> nans;
				for(int p = 0; p < K; ++p) {
					llint best = bigVal;
					for(int ap = 0; ap < K; ++ap) {best = min(best, ans[ap] + initArray[g].M[ap][p]);}
					nans.push_back(best);
				}
				ans = nans;
			}
			printf("%lld\n", (ans[b%K] < bigVal ? ans[b%K] : -1));			
		}
	}
	
	return 0;
}