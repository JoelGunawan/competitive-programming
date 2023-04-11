#include "cave.h"
#include <bits/stdc++.h>
using namespace std;

void exploreCave(int N) {
    /* ... */
    // simple way
    // determine if 0/1
    // then determine where
    vector<pair<int, int>> p;
    int query[N];
    bool picked[N];
    vector<pair<int, int>> s;
    memset(picked, 0, sizeof(picked));
    for(int i = 0; i < N; ++i) {
        // determine 0 or 1
        // buat yg sebelum i harus di set manual
        for(int j = 0; j < N; ++j) {
            if(!picked[j])
                query[j] = 0;
        }
        int first = tryCombination(query);
        if(first > i || first == -1) {
            // is 0
            int l = 0, r = N - 1;
            while(l < r) {
                // coba jadikan l...mid 0 dan mid+1...r 1
                int mid = (l + r) / 2;
                for(int j = 0; j < N; ++j)
                    if(!picked[j])
                        query[j] = 1;
                for(int j = l; j <= mid; ++j)
                    if(!picked[j])
                        query[j] = 0;
                int q = tryCombination(query);
                if(q != i)
                    r = mid;
                else
                    l = mid + 1;
            }
            query[l] = 0;
            picked[l] = 1;
            p.push_back(make_pair(l, 0));
        }
        else {
            // is 1
            int l = 0, r = N - 1;
            while(l < r) {
                // coba jadikan l...mid 0 dan mid+1...r 1
                int mid = (l + r) / 2;
                for(int j = 0; j < N; ++j)
                    if(!picked[j])
                        query[j] = 0;
                for(int j = l; j <= mid; ++j)
                    if(!picked[j])
                        query[j] = 1;
                int q = tryCombination(query);
                if(q != i)
                    r = mid;
                else
                    l = mid + 1;
            }
            query[l] = 1;
            picked[l] = 1;
            p.push_back(make_pair(l, 1));
        }
    }
    int S[N], D[N];
    for(int i = 0; i < N; ++i)
        S[p[i].first] = p[i].second, D[p[i].first] = i;
    answer(S, D);
}
