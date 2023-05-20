#include "paint.h"

#include <bits/stdc++.h>
using namespace std;

std::string solve_puzzle(std::string s, std::vector<int> c) {
    // dp O(NK)
    // nanti transisi coba dari i - 1 terus anggep
    // nanti cari semua previous states
    // bisa semacam dijkstra semua previous states/bfs
    // nanti previous state ada kemungkinan 0 atau 1?
    // yg dp[i][k] = 1 nanti jadiin yes terus nanti cari state sebelumnya dmn
    // find latest sm find earliest
    // nanti cek state boleh transisi kalo???
    // dia statenya harus ambil sisanya
    int n = s.size(), k = c.size();
    bool dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    // bisa ambil coba ambil dr n - c[i], i - 1 atau n - 1, i
    // nanti case ambilnya bs coba dua"nya
    // case valid:
    s = " " + s;
    c.insert(c.begin(), 0);
    int prefa[n + 1], prefb[n + 1];
    prefa[0] = prefb[0] = 0;
    prefb[0] = 1;
    for(int i = 1; i <= n; ++i) {
        prefa[i] = prefa[i - 1];
        prefb[i] = 0;
        if(s[i] == '.')
            prefa[i]++, prefb[i]++;
        else if(s[i] == 'X')
            prefa[i]++;
        else
            prefb[i]++;
    }
    for(int i = 0; i <= n; ++i) {
        if(s[i] == 'X')
            break;
        dp[i][0] = 1;
    }
    for(int j = 1; j <= k; ++j) {
        for(int i = 1; i <= n; ++i) {
            //if(i == 13)
            //    cout << i << " " << c[j] << " " << prefa[i] << " " << prefa[i - c[j]] << " " << prefb[i - c[j]] << " " << c[j] << endl;
            // di first loop cari smallest x, gaboleh ambil yang lebih besar dr smallest x
            //cout << s[i] << endl;
            if(i >= c[j] && prefa[i] - prefa[i - c[j]] == c[j] && prefb[i - c[j]]) {
                //cout << "DEBUG " << i << " " << j << endl;
                //cout << i - c[j] << " " << j - 1 << endl;
                if(i == c[j])
                    dp[i][j] = dp[i - c[j]][j - 1];
                else
                    dp[i][j] = dp[i - c[j] - 1][j - 1];
            }
            if(s[i] != 'X') {
                //cout << i << endl;
                dp[i][j] |= dp[i - 1][j];
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    // coba dr kemunculan X terakhir atau 0
    // terus nanti cek dia bs dateng drmn aja
    // cek previousnya yg berlaku
    // nanti kalo misal bisa dr i - 1, j berarti sel sekarang itu white
    // kalo misal bs dr i - c[j], j - 1 berarti sel sekarang itu black
    bool white[n + 1], black[n + 1];
    memset(white, 0, sizeof(white));
    memset(black, 0, sizeof(black));
    bool vis[n + 1][k + 1];
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    int diff[n + 2];
    memset(diff, 0, sizeof(diff));
    //cout << "TEST" << endl;
    for(int i = n; i >= 1; --i) {
        if(dp[i][k])
            q.push(make_pair(i, k)), vis[i][k] = 1;
        if(s[i] == 'X')
            break;
    }
    // yg penting tidak ada X yg di skip
    // how to handle?
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x < 0 || y < 0 || !dp[x][y]) 
            continue;
        if(x != 0 && dp[x - 1][y] && s[x] != 'X') {
            //cout << x << " " << y << endl;
            white[x] = 1;
            if(!vis[x - 1][y])
                q.push({x - 1, y}), vis[x - 1][y] = 1;
        }
        if(y != 0 && x >= c[y] && prefa[x] - prefa[x - c[y]] == c[y] && prefb[x - c[y]] && dp[max(0, x - c[y] - 1)][y - 1]) {
            //cout << x << " " << y << endl;
            // antara x - c[y] sampai x jadiin black
            ++diff[x - c[y] + 1];
            --diff[x + 1];
            if(x - c[y] - 1 >= 0 && !vis[x - c[y] - 1][y - 1])
                q.push(make_pair(x - c[y] - 1, y - 1)), vis[x - c[y] - 1][y - 1] = 1;
            //cout << x << " " << y << endl;
            white[x - c[y]] = 1;
        }
    }
    // bug: langsung ke elemen 1
    int pr = 0;
    for(int i = 1; i <= n; ++i) {
        pr += diff[i];
        if(pr)
            black[i] = 1;
    }
    string ret = "";
    for(int i = 1; i <= n; ++i) {
        if(white[i] && black[i])
            ret += '?';
        else if(black[i])
            ret += 'X';
        else
            ret += '_';
    }
    return ret;
}
