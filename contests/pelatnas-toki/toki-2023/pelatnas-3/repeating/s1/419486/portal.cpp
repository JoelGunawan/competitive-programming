#include "portal.h"
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
//vector<ll> arr;
//vector<ll> pref;
int n;
vector<ll> p;
vector<pair<ll, ll>> v;
void init(int N, std::vector<long long> P) {
    // b[i] = 0 -> cari a[i] doang -> trivial? (harusnya max O(log)) ish sih...
    // pake pr_sum boleh extend by 1...pr_sum + 1
    /*
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
    */
   // buat dp O(NAi)
   // works for all, for given O(NAi), cek apakah bisa buat Ai dan Bi
   // tiap node harus masuk ke Ai atau Bi, kalo ga anggep aja dia gabisa kan... (karena makin besar pasti makin gabisa)
   sort(P.begin(), P.end());
   ll pre = 0;
   p = P;
   n = N;
   int cnt = 0;
    
    //cout << v.size() << endl;
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
    /*
    int x = --upper_bound(arr.begin(), arr.end(), k) - arr.begin();
    // query aja lgsg
    ll res = pref[x];
    return res >= a;
    */
   // sampah N <= 10?
   // O(2^n * 2^n) aja?
   // jadi nanti tiap query coba 2^n di kiri dan 2^n di kanan
   // coba cek tiap konfigurasi yg dipilih, terus apa bisa buat sum tertentu, jika iya, maka nanti 
   // observasi -> hanya ada at most 2^2n kemungkinan sum
   // cari di tiap mask bisa sum brp aja, inverse masknya itu b
    v.clear();
    int y = 0;
    for(int i = 0; i < n; ++i) {
        if(p[i] <= k)
            ++y;
    }
   for(int i = 0; i < (1 << y); ++i) {
        ll sum = 0;
        for(int j = 0; j < y; ++j) {
            if((1 << j) & i) {
                sum += p[j];
            }
        }
        for(int j = 0; j < (1 << y); ++j) {
            ll sum2 = 0;
            bool invalid = 0;
            for(int k = 0; k < y; ++k) {
                if((1 << k) & j) {
                    if((1 << k) & i) {
                        //cout << i << " " << j << endl;
                        invalid = 1;
                        break;
                    }
                    sum2 += p[k];
                }
            }
            if(!invalid)
                v.push_back({sum, sum2});
            //cout << sum << " " << sum2 << endl;
        }
    }
    //cout << v.size() << endl;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int x = 0;
    for(auto i : v) {
        if(i.first <= a && i.second <= b) {
            //cout << i.first << " " << i.second << endl;
            ++x;
        }
    }
    return x == 1ll * (a + 1) * (b + 1);
}