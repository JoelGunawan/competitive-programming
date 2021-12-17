#include "timbang.h"
#include <vector>
#include <cstdlib>
#include <iostream>

static std::vector<int> V;
static int N, K, cntr;

int compare(int A, int B) {
    A --;
    B --;
    if(A < 0 || B < 0 || A >= N || B >= N) {
        std::cout << "Invalid parameter of compare function (index out of bound)" << std::endl;
        exit(0);
    }

    if(A == B) {
        std::cout << "Invalid parameter of compare function (same duck *kwek*)" << std::endl;
        exit(0);
    }

    cntr ++;
    if(cntr > K) {
        std::cout << "Compare function calls limit exceeded" << std::endl;
        exit(0);
    }

    return V[A] < V[B] ? -1 : (V[A] > V[B]);
}

int main() {
    cntr = 0;
    std::cin >> N >> K;
    V = std::vector<int>(N);
    for(int i = 0 ; i < N ; i ++) {
        int x;
        std::cin >> x;
        V[x - 1] = i;
    }

    std::vector<int> res = findOrder(N, K);
    for(int i = 0; i < res.size() ; i ++)
        std::cout << res[i] << " \n"[i + 1 == res.size()];
}