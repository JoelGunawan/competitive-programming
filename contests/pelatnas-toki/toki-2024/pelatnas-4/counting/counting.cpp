#include "counting.h"
#include <bits/stdc++.h>
using namespace std;

int count_valid_configuration(int N, int K, int M) {
    // subtask 1 -> brute force NK * 3^N
    // subtask 2 -> brute force DP Bitmask N*2^N states, O(1)/O(N) Transition
    // subtask 3 -> K = 1 -> observe that K = 1 means that from each state there is only one move
    // therefore it is very easy to check if a state is valid
    // a state is valid if and only if we go right by one every time, there is a path towards N
    // one node has **exactly** one outgoing edge and we need to find the configurations of nodes such that there is a valid path
    // hard constraint -> a node X with an outgoing edge not equal to X + 1 means that the dest. of the edge must have an outgoing edge equal to X + 1
    // observe: jika kita ada beberapa "CC" dimana sebuah CC didefinisikan sebagai subarray contiguous dimana semua kecuali terakhirnya merupakan landing step, maka kita bisa mem-brute force setiap kemungkinan pengurutan proses CC
    // ada case dimana ga ada landing step untuk sebuah CC -> masuk ke buang
    // perhatikan bahwa setiap urutan proses CC dapat menjadi valid
    // transisi pembuatan CC dapat dilakukan sebagai berikut:
    // - DP[idx][cc][buang] = DP[idx - 1][cc][buang - 1] -> setiap edge 
    // - DP[idx][cc][buang] = DP[idx - i][cc - 1][buang] -> i > 1 (buat CC baru)
    // nanti dari setiap DP[N][cc][buang] kita bisa hitung banyaknya cara untuk membuatnya valid
    // subtask 4/5 -> observe that kita bisa meloncati sebuah/serangkaian CC
    // as a result, observe that CC yang kita buat ga harus contiguous, bisa skip at most K - 1 objects at once.
    return -1;
}
