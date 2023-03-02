#include "simulasi_pertarungan.h"
#include <utility>
#include <bits/stdc++.h>
using namespace std;
int calls = 0;
map<pair<int, int>, int> memo;
int get_ans(int m, int k) {
    ++calls;
    if(m <= 1)
        return 0;
    else if(k == 1)
        return m - 1;
    else {
        if(memo[make_pair(m, k)])
            return memo[make_pair(m, k)];
        // buat bsta supaya l dan r nya sesuai
        // l itu langsung aja sesuai yang kita mau
        // kalo r itu nanti harus target - 1
        int l = 1, r = m - 1, ret = m - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(get_ans(mid, k - 1) < get_ans(m - mid, k))
                l = mid + 1;
            else
                r = mid - 1;
            ret = min(ret, max(get_ans(mid, k - 1), get_ans(m - mid, k)) + 1);
            // if mid == 0?
            // assume split segments -> mid is non zero and not equal to m
            //cout << "MID " << m << " " << k << " " << mid << " " << get_ans(mid, k - 1) << " " << get_ans(m - mid, k) + 1 << endl;
        }
        //cout << m << " " << k << " " << ret << endl;
        return memo[make_pair(m, k)] = ret;
    }
}
// next segment selalu lebih rendah dari current segment
int findMinSimulations(int M, int K) { 
    // k = 2 -> ga butuh simulate = false
    // berarti done in probably around sqrt time? -> ini pasti bisa
    // mis skrg klo fail kita butuh tambah x
    // berarti next harus x - 1
    // and so on
    // observasi -> segment sizes are always non increasing
    // semakin ke kanan, segment yang di search akan selalu lebih kecil
    // coba "bsta" point dimana dia bisa hasilnya 1 kurang dari sebelumnya (atau boleh jadi lebih yang penting less than previous)
    // jadi nanti, kita lakukan bsta untuk given M, K
    // bsta for first segment, kemudian bsta for second segment
    // kalo ga mungkin -> berarti coba angka yang lebih tinggi
    // bsta on every level -> log^3?
    // if bsta based on answer?
    // have target answer, how many k to achieve?
    // ada segment limit sebenarnya
    // segment limit -> tiap segment pasti non increasing
    // jumlah maksimum segmen -> sqrt
    // last -> ukurannya 1
    // before last -> ukurannya lebih dari 1
    // coba constructive algo
    // dari 1, 1 -> 1
    // base case k = 1 atau m = 1
    // untuk tiap height, cari next maximum segment dgn cost +1
    return get_ans(M + 1, min(K, 30));
}

int findL(bool simulate) {
    return -1; 
}
