#include "aplusb.h"
#include <cassert>
#include <cstdio>

int main() {
	int N;
	assert(1 == scanf("%d", &N));
	std::vector<int> A(N);
	for (int i = 0; i < N; ++i)
		assert(1 == scanf("%d", &A[i]));
	std::vector<int> B(N);
	for (int i = 0; i < N; ++i)
		assert(1 == scanf("%d", &B[i]));

	fclose(stdin);

	std::vector<int> res = smallest_sums(N, A, B);

	int n = res.size();
	for (int i = 0; i < n; ++i) {
		if (i > 0)
			printf(" ");
		printf("%d", res[i]);
	}
	printf("\n");
	fclose(stdout);

	return 0;
}
