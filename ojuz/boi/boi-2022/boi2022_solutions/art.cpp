#include <bits/stdc++.h>
#include "art.h"
using namespace std;

void solve(int N) {
    vector<int> responses;
    for(int i = 0; i < N; ++i) {
        vector<int> order(N);
        for(int j = 0; j < N; ++j)
            order[j] = (j+i)%N + 1;

        responses.push_back(publish(order));
    }

    vector<int> final_order(N);
    for(int i = 0; i < N; ++i) {
        final_order[(responses[i]-responses[(i+1)%N] + N - 1) / 2] = i + 1;
    }

    answer(final_order);
}

