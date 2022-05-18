#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ins insert
using namespace std;
int tmp1[251][251], tmp2[251][251];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n][m], c[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> c[i][j];
    // bitmask aja elemen apa yang mau kita ambil
    // cari median
    // cek apakah terhubung
    // cek apakah semua elemen valid
    // cara dp agar tc sample valid (ke kanan terus ke kiri lagi)
    // pilih 5 titik dari warna yang berbeda
    // cari minimum tree yang menghubungkan mereka semua (kok kyk soal tower :thinkies:)
    // need dp backtrack
    // dp backtrack to get median
    // median probably bisa di bsta
    // + backtrack
    // dpnya gmn :sob:
    // tutorial gf when UwU
    
    int computer_count = INT_MAX, median = INT_MAX;
    ll op_cnt = 0;
    vector<vector<bool>> ext, vis;
    bool color[9];
    int elements[n * m];
    
    for(int i = 0; i < (1 << (n * m)); ++i) {
        int cnt = 0;
        vis = ext = vector<vector<bool>>(n, vector<bool>(m, 0));
        memset(color, 0, sizeof(color));
        pair<int, int> tmp;
        for(int j = 0; j < n * m; ++j) {
            if((1 << j) & i) {
                ext[j / m][j % m] = 1;
                elements[cnt] = a[j / m][j % m];
                ++cnt;
                color[c[j / m][j % m]] = 1;
                tmp = make_pair(j / m, j % m);
            }
        }
        int color_cnt = 0;
        for(int i = 0; i < 9; ++i)
            color_cnt += color[i];
        if(color[0] || color_cnt != 5 || cnt > computer_count)
            continue;
        // cek apakah cur 
        // cek median
        function<int(int, int)> dfs = [&] (int x, int y) -> int {
            if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || !ext[x][y])
                return 0;
            vis[x][y] = 1;
            int res = 1;
            res += dfs(x - 1, y);
            res += dfs(x + 1, y);
            res += dfs(x, y - 1);
            res += dfs(x, y + 1);
            return res;
        };
        if(dfs(tmp.fi, tmp.se) != cnt)
            continue;
        std::sort(elements, elements + cnt);
        if(cnt < computer_count) {
            computer_count = cnt;
            median = elements[cnt / 2 + cnt % 2 - 1];
        }
        else if(elements[cnt / 2 + cnt % 2 - 1] < median)
            median = elements[cnt / 2 + cnt % 2 - 1];
    }
    std::cout << computer_count << " " << median << endl;
    return 0;
}