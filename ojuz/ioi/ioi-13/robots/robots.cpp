#include "robots.h"
#include <bits/stdc++.h>
using namespace std;

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    // bsta
    // cari max
    vector<pair<int, int>> a, b;
    sort(X, X + A);
    sort(Y, Y + B);
    for(int i = 0; i < T; ++i) {
        //cout << "OUT " << W[i] << " " << S[i] << endl;
        a.push_back(make_pair(W[i], S[i]));
    }
    int l = 1, r = T, ans = -1;
    sort(a.begin(), a.end());
    //cout << a[0].first << " " << a[0].second << endl;
    while(l <= r) {
        int mid = (l + r) / 2;
        // try max mid
        // putaway
        // ambil dr w terbesar yg bs diambil s nya
        // x -> weight limit
        // y -> size limit
        bool done[T];
        // use priority queue to find whether largest element is sufficient?
        // or use count and sliding
        // should be doable? as finding next available element can be done using MAKE PAIR
        memset(done, 0, sizeof(done));
        // pake priority queue, check largest element
        // insert beberapa weights, 
        // fi -> size
        // se -> idx;
        priority_queue<pair<int, int>> pq;
        int idx = 0;
        int proc = 0;
        //cout << mid << endl;
        for(int i = 0; i < A; ++i) {
            // fi diambil dr a[idx].se
            while(idx < T && a[idx].first < X[i]) {
                pq.push({a[idx].second, idx});
                ++idx;
            }
            for(int j = 0; j < mid; ++j) {
                if(pq.empty())
                    break;
                else {
                    int tmp = pq.top().second;
                    //cout << "USE A " << pq.top().first << " " << pq.top().second << " " << a[tmp].first << " " << a[tmp].second << endl;
                    pq.pop();
                    done[tmp] = 1;
                    ++proc;
                }
            }   
        }
        b.clear();
        while(pq.size())
            pq.pop();
        for(int i = 0; i < T; ++i) {
            if(!done[i])
                b.push_back(a[i]), swap(b.back().first, b.back().second);
        }
        //cout << b.size() << " " << b[0].first << " " << b[0].second << endl;
        sort(b.begin(), b.end());
        idx = 0;
        for(int i = 0; i < B; ++i) {
            //cout << Y[i] << " " << b[idx].first << endl;
            while(idx < b.size() && b[idx].first < Y[i]) {
                //cout << b[idx].first << " " << b[idx].second << endl;
                pq.push({b[idx].second, idx});
                ++idx;
            }
            for(int j = 0; j < mid; ++j) {
                if(pq.empty())
                    break;
                else {
                    //cout << " USE B" << b[pq.top().second].first << " " << b[pq.top().second].second << endl;
                    pq.pop();
                    ++proc;
                }
            }
        }
        if(proc == T)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
        // next ambil dr s terbesar yg bs diambil w nya
    }
    return ans;
}
