#include "coreputer.h"

#include <cassert>
#include <cstdio>
#include <string>
#include <vector>

static inline constexpr int maxDiagnostics = 32;
static int diagnostic_counter = 0;
static int malfunctioningCores = 0;

static int N;
static std::vector<int> M;

static inline void protocol_violation(std::string message) {
	printf("Protocol Violation: %s\n", message.c_str());
	exit(0);
}

int run_diagnostic(std::vector<int> T) {
	++diagnostic_counter;
	if (diagnostic_counter > maxDiagnostics) {
		protocol_violation("too many calls");
	}

	int l = T.size();
	if (l > N) {
		protocol_violation("invalid array");
	}

	for (int i = 0; i < l; ++i) {
		if (T[i] < 0 || T[i] >= N) {
			protocol_violation("invalid array");
		}
		for (int j = 0; j < i; ++j) {
			if (T[i] == T[j]) {
				protocol_violation("invalid array");
			}
		}
	}

	int malfunctioningTaggedCores = 0;
    for (int i : T) {
        if (M[i] == 1) malfunctioningTaggedCores++;
    }

    int malfunctioningUntaggedCores = malfunctioningCores - malfunctioningTaggedCores;
    if (malfunctioningTaggedCores > malfunctioningUntaggedCores) {
        return 1;
    }
    if (malfunctioningTaggedCores == malfunctioningUntaggedCores) {
        return 0;
    }
    return -1;
}

int main() {
	assert(1 == scanf("%d", &N));
	M.resize(N);
	for (int i = 0; i < N; ++i) {
		assert(1 == scanf("%d", &M[i]));
		malfunctioningCores += M[i];
	}

	if (malfunctioningCores == 0) {
		printf("No Malfunctioning Core\n");
        exit(0);
	}

	std::vector<int> c = malfunctioning_cores(N);
	int n = c.size();
	for (int i = 0; i < n; ++i) {
		printf(i == 0 ? "%d" : " %d", c[i]);
	}
	printf("\n");
	printf("%d\n", diagnostic_counter);

	return 0;
}
