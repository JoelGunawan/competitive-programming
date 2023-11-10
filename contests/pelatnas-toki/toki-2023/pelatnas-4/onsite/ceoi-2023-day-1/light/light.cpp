#include <bits/stdc++.h>
#include "light.h"

using namespace std;

long long N = 1;
vector<long long> v = {1};

void prepare() {

}

void clean(vector<long long> &a, long long p) {
    if(a.size() <= 2)
        return;
    if(a[1] - (1 + p) <= 2 * (a[2] - a[1])) {
        // ganti a[1] dengan 1 + p
        a.erase(a.begin() + 1);
        a.insert(a.begin() + 1, 1 + p);
    }
}

pair<long long, vector<long long>> join(long long p) {
    // geser semuanya ke kanan
    // kalo jarak ke kiri itu lebih dr 2 kali jarak sebelumnya, 
    N += p;
    vector<long long> nv;
    nv.push_back(N);
    nv.push_back(N - 1);
    // coba construct dr belakang
    long long diff = 1;
    int done = 0;
    while(true) {
        ++done;
        diff = max({diff, nv[nv.size() - 2] - nv.back()});
        long long nxt = nv.back() - max(2ll, 2 * diff - 1);
        //cout << nv.back() << " " << nv[nv.size() - 2] << " " << diff << " " << nxt << endl;
        if(diff == 0) {
            return {};
        }
        if(nxt <= 1) {
            if(nv.back() != 1)
                nv.push_back(1);
            break;
        }
        // cari --upper_bound
        long closest_v = *--upper_bound(v.begin(), v.end(), nxt);
        //cout << "DEBUG " << nxt << " " << closest_v << endl;
        if(nxt - closest_v > p) {
            // cari nxt yg lebih dekat
            // lower_bound v aja
            if(*lower_bound(v.begin(), v.end(), nxt) == nv.back())
                nv.push_back(closest_v + p);
            else
                nv.push_back(*lower_bound(v.begin(), v.end(), nxt));
        }
        else {
            // berarti push back nxt
            nv.push_back(nxt);
        }
    }
    v = nv;
    reverse(v.begin(), v.end());
    return {p, v};
    // clean -> bersihin v supaya ga ada gap sub optimal
}

pair<long long, vector<long long>> leave(long long p) {
    // cek yg kehapus mana aja
    N -= p;
    while(v.back() > N)
        v.pop_back();
    if(N == 1)
        return {v.size(), v};
    // coba reassign
    vector<long long> nv;
    nv.push_back(N);
    nv.push_back(N - 1);
    // coba construct dr belakang
    long long diff = 1;
    int done = 0;
    while(true) {
        ++done;
        diff = max({diff, nv[nv.size() - 2] - nv.back()});
        long long nxt = nv.back() - max(2ll, 2 * diff - 1);
        //cout << nv.back() << " " << nv[nv.size() - 2] << " " << diff << " " << nxt << endl;
        if(diff == 0) {
            return {};
        }
        if(nxt <= 1) {
            if(nv.back() != 1)
                nv.push_back(1);
            break;
        }
        // cari --upper_bound
        long closest_v = *--upper_bound(v.begin(), v.end(), nxt);
        //cout << "DEBUG " << nxt << " " << closest_v << endl;
        if(nxt - closest_v > p) {
            // cari nxt yg lebih dekat
            // lower_bound v aja
            if(*lower_bound(v.begin(), v.end(), nxt) == nv.back())
                nv.push_back(closest_v + p);
            else
                nv.push_back(*lower_bound(v.begin(), v.end(), nxt));
        }
        else {
            // berarti push back nxt
            nv.push_back(nxt);
        }
    }
    v = nv;
    reverse(v.begin(), v.end());
    return {p, v};
}
