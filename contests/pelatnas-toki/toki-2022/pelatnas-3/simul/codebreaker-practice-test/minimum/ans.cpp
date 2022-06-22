#include "minimum.h"
#include <bits/stdc++.h>
using namespace std;

int findMin(int N, int A[]) {
    int mini = INT_MAX;
    for(int i = 0; i < N; ++i) {
        mini = min(mini, A[i]);
    }
    return mini;
}
