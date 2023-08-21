#include "rail.h"
#include <bits/stdc++.h>
using namespace std;

void findLocation(int N, int first, int location[], int stype[]) {
    int dist0[N], distse[N];
    location[0] = first;
    stype[0] = 1;
    for(int i = 1; i < N; ++i)
        dist0[i] = getDistance(0, i);
    int closest, closest_dist = 1e9;
    for(int i = 1; i < N; ++i) {
        if(dist0[i] < closest_dist)
            closest = i, closest_dist = dist0[i];
    }
    location[closest] = first + closest_dist;
    stype[closest] = 2;
    distse[0] = dist0[closest];
}
