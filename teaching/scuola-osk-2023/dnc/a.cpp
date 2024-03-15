#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// l kiri
// r kanan
// x yg dicari
// m -> mid
// binser -> fungsi
void binser(int l, int r, int x) {
    int m = (l + r) / 2;
    if(l == r) {
        // ini merupakan hasil
        // entah hitungnya bagaimana
        return;
    }
    // hitungan
    // anggap aja hasil k
    int k;
    if(x <= k) {
        binser(m, r, x);
    }
    else {
        binser(l, m - 1, x);
    }
}
void merge(vector<int> &a, int l, int m, int r) {
    // asumsi l1 ke r1 udah sorted
    // l2 ke r2 udah sorted
    // ambil minimum dr array kiri/kanan
    int idx1 = l, idx2 = m + 1;
    vector<int> tmp;
    while(idx1 <= m || idx2 <= r) {
        // idx1 > m -> array 1 kosong
        // idx2 > r -> array 2 kosong
        if(idx1 > m) {
            // array 1 kosong, pasti ambil dari array 2
            tmp.push_back(a[idx2]);
            idx2++;
        }
        else if(idx2 > r) {
            // array 2 kosong, pasti ambil dari array 1
            tmp.push_back(a[idx1]);
            idx1++;
        }
        else {
            // array 1 dan array 2 tidak kosong
            // ambil yg minimal
            if(a[idx1] < a[idx2]) {
                tmp.push_back(a[idx1]);
                idx1++;
            }
            else {
                tmp.push_back(a[idx2]);
                idx2++;
            }
        }
    }
    for(int i = l; i <= r; i++)
        a[i] = tmp[i - l];
}
void divide(vector<int> &a, int l, int r) {
    int m = (l + r) / 2;
    if(l == r)
        return;
    divide(a, l, m), divide(a, m + 1, r);
    merge(a, l, m, r);
}
// main -> fungsi khusus
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // binary search
    // 2 tipe:
    // fungsi
    // while loop
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    divide(a, 0, a.size() - 1);
    for(auto i : a)
        cout << i << " ";
    cout << endl;
    int l, r, ans;
    while(l <= r) {
        int m = (l + r) / 2;
        // hitungan tertentu
        // anggap aja x hasil
        int x;
        // x memenuhi kondisi tertentu
        if(x >= 5) {
            l = m + 1;
            ans = m;
        }
        else {
            r = m - 1;
        }
    }
    while(l < r) {
        int m = (l + r) / 2;
        // hitungan tertentu
        int x;
        if(x >= 5) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    return 0;
}