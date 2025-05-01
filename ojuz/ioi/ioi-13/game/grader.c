#include <stdio.h>
#include <stdlib.h>
#include "game.h"

#define fail(s, x...) do { \
		fprintf(stderr, s "\n", ## x); \
		exit(1); \
	} while(0)

#define MAX_SIZE 1000000000
#define MAX_N 272000

int main() {
	int R, C, N;
    int P, Q, U, V;
    long long K;
    int i, type;
	int res;

	res = scanf("%d", &R);
	res = scanf("%d", &C);
	res = scanf("%d", &N);

    init(R, C);

	for (i = 0; i < N; i++) {
        res = scanf("%d", &type);
        if (type == 1) {
		    res = scanf("%d%d%lld", &P, &Q, &K);
            update(P, Q, K);
        } else if (type == 2) {
		    res = scanf("%d%d%d%d", &P, &Q, &U, &V);
            printf("%lld\n", calculate(P, Q, U, V));
        }
	}

	return 0;
}
