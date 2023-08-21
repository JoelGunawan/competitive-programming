#include <bits/stdc++.h>
#define ll long long
using namespace std;
string init = "100001010111110011111010011100100011010101010111101010110110000011010111110";
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    // x = y = z or x = y = 1
    // for small n, try to do O(N^2) -> 36 poin ish
    // bigger N -> ada observasi di string
    // the front 1 -> always the same (atau technically bs tambah)
    // modulating between 0 and 1 only?
    // end string length -> init * 2n
    // udah some small n, nanti di semua 0 nya pasti lengthnya pendek?
    // ga juga
    // cara lain -> hanya consider 0 / 1 aja, pasti nanti reach "stability"
    // from a block of 1111111, the only change is in the last 2 elements
    // size '0' bakal stabil di ukuran 1/2
    // nanti 0 bakalan bisa merge antara 2 sequence yg beda
    // tiap operasi: selalu tambah 1 di depan
    // di belakang tambah gatau :sob:
    bool state[2][6250000 * 2 + 5];
    memset(state, 1, sizeof(state));
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
    int l = 2;
    for(int i = l; i < l + init.size(); ++i) {
        state[1][i] = init[i - l] == '1';
    }
    int r = l + init.size() - 1;
    int len = init.size();
    const int lim = 6250000;
    int n;
    fin >> n;
    vector<int> a;
    bool vis[n];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        a.push_back(x);
    }
   //int n;
   //cin >> n;
    for(int i = 0; i < lim; ++i) {
        int idx = i & 1;
        r += 2;
        for(int j = l; j <= r; ++j) {
            state[idx][j] = (state[idx ^ 1][j - 2] == state[idx ^ 1][j - 1] && state[idx ^ 1][j - 2] == state[idx ^ 1][j]) 
            || (state[idx ^ 1][j - 2] && state[idx ^ 1][j - 1]);
        }
        if(binary_search(a.begin(), a.end(), i + 1)) {
            vis[lower_bound(a.begin(), a.end(), i + 1) - a.begin()] = 1;
            ll res = 0;
            for(int j = l; j <= r; ++j) {
                if(state[idx][j])
                    res = (res + powmod(10, r - j)) % mod;
            }
            fout << res << endl;
        }
       //for(int j = l; j <= r; ++j) {
       //     cout << state[idx][j];
       //}
       //cout << endl;
    }
    /*
    ll res = 0;
    for(int j = l; j <= r; ++j) {
        cout << state[(n - 1) & 1][j];
        if(state[(n - 1) & 1][j])
            res = (res + powmod(10, r - j)) % mod;
    }
    cout << endl;
    cout << res << endl;
    */
    for(int i = 0; i < n; ++i) {
        if(!vis[i])
            fout << "PASS" << endl;
    }
}