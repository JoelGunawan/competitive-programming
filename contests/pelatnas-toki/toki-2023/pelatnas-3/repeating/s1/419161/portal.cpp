#include "portal.h"
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<ll> arr;
vector<ll> pref;
int n;
void init(int N, std::vector<long long> P) {
    // b[i] = 0 -> cari a[i] doang -> trivial? (harusnya max O(log)) ish sih...
    // pake pr_sum boleh extend by 1...pr_sum + 1
    sort(P.begin(), P.end());
    arr.pb(-1);
    for(auto i : P)
        arr.pb(i);
    n = N;
    sort(arr.begin(), arr.end());
    // nanti buat dp O(Nmin(A[i], B[i]) bisa
    pref.pb(0);
    for(int i = 1; i <= n; ++i) {
        if(arr[i] <= pref[i - 1] + 1) {
            pref.pb(pref[i - 1] + arr[i]);
        }
        else {
            pref.pb(pref[i - 1]);
        }
    }
}

bool query(long long k, long long a, long long b) { 
    // mis a > b
    // semua segment x > b pasti diambil a aja
    // sisanya gatau :)
    // construct bareng untuk a < b, nanti sisanya buat construct yg lebih gede
    // jadi samain a, b
    // sampai size x
    // terus nanti yg kelebihannya paling besar yg di gas?
    // klo a, b bareng -> sizenya bakal mirip" jadi ambil terkecil terus aja bisa harusnya
    // pertama cek dlu apakah possible b, b bareng bisa
    // cari posisi k nya yg bener dmn
    // last element yg <= k
    int x = --upper_bound(arr.begin(), arr.end(), k) - arr.begin();
    // query aja lgsg
    ll res = pref[x];
    return res >= a;
}