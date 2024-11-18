#include "counting.h"
#include <cstdio>

int main() {
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    printf("%d\n", count_valid_configuration(N, K, M));
}
