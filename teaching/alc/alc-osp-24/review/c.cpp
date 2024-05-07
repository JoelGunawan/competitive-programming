#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    char a[n + 1][m + 1];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    pair<int, int> apos;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'A')
                apos = make_pair(i, j);
        }
    }
    pair<int, int> bpos;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] == 'B')
                bpos = make_pair(i, j);
        }
    }
    // fi -> koordinat
    // se-> dist
    queue<pair<pair<int, int>, int>> bfs;
    bfs.push(make_pair(apos, 0));
    int dist[n + 1][m + 1];
    memset(dist, -1, sizeof(dist));
    while(bfs.size()) {
        int x = bfs.front().first.first, y = bfs.front().first.second, d = bfs.front().second;
        bfs.pop();
        if(dist[x][y] != -1 || a[x][y] == '#')
            continue;
        //cout << x << " " << y << endl;
        dist[x][y] = d;
        // ke bawah, ke kiri, ke atas, dan ke kanan
        vector<pair<int, int>> nxt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(auto p : nxt) {
            if(x + p.first >= 1 && x + p.first <= n && y + p.second && y + p.second <= m 
            && dist[x + p.first][y + p.second] == -1) {
                bfs.push(make_pair(make_pair(x + p.first, y + p.second), d + 1));
            }
        }
    }
    if(dist[bpos.first][bpos.second] == -1) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << dist[bpos.first][bpos.second] << endl;
    vector<char> c;
    while(bpos != apos) {
        // yg sebelahn yg jaraknya dikurang dari 1 dari yg skrg
        vector<pair<int, int>> nxt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int x = bpos.first, y = bpos.second;
        for(auto p : nxt) {
            if(x + p.first >= 1 && x + p.first <= n && y + p.second && y + p.second <= m &&
            dist[x + p.first][y + p.second] == dist[x][y] - 1) {
                bpos = make_pair(x + p.first, y + p.second);
                if(p.first == 1) {
                    c.push_back('U');
                }
                else if(p.first == -1) {
                    c.push_back('D');
                }
                else if(p.second == -1) {
                    c.push_back('R');
                }
                else {
                    c.push_back('L');
                }
                break;
            }
        }
    }
    reverse(c.begin(), c.end());
    for(auto x : c)
        cout << x;
    cout << endl;
}