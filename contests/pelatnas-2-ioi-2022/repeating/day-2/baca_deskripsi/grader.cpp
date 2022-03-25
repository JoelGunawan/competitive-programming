#include "baca_deskripsi.h"
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
	int n, m;
	
	scanf("%d", &n);
	vector<int> A(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	vector<int> B(m);
	for(int j = 0; j < m; ++j)
		scanf("%d", &B[j]);
	
	vector<int> answers = getAnswers(n, m, A, B);
	for(auto ans: answers)
		printf("%d\n", ans);

	return 0;
}

