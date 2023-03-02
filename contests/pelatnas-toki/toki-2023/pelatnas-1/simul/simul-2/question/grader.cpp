#include <iostream>
#include <ios>
#include <algorithm>
#include <stdlib.h>
#include "answerer.h"
#include "shouter.h"

static void wrong_answer() {
	printf("WA\n0\n");
	exit(0);
}

static void give_score(int score) {
	printf("OK\n%d\n", score);
	exit(0);
}

static int N[2000000];
static int h[2000000];
static int order[2000000];
static int key[2000000];
static int q[2000000][2];
static bool ans[2000000];

int main() {
	srand(112233); // might be different in server

	int t;
	scanf("%d", &t);
	int max_hint = 0;

	for (int tc = 0; tc < t; tc++) {
		scanf("%d%d%d%d", &N[tc], &q[tc][0], &q[tc][1], &key[tc]);
		h[tc] = give_hint(N[tc], q[tc][0], q[tc][1]);
		if (h[tc] <= 0) {
			wrong_answer();
		}
		order[tc] = tc;
	}

	std::random_shuffle(order, order + t);
	for (int idx = 0; idx < t; idx ++) {
		int tc = order[idx];
		max_hint = std::max(max_hint, h[tc]);
		ans[tc] = answer(N[tc], q[tc][key[tc]], h[tc]);
	}

	for (int tc = 0; tc < t; tc ++) {
		if (ans[tc]) {
			printf("true\n");
		} else {
			printf("false\n");
		}
	}

	give_score(max_hint);
}
