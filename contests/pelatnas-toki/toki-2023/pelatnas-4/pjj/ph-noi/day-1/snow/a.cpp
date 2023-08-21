#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
ifstream fin;
ofstream fout;
void tc() {
    int n;
    fin >> n;
    ll grid[n + 2][n + 2];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            fin >> grid[i][j];
        }
    }
    // use dijkstra on grid
    // use random + dijkstra on grid
    priority_queue<pair<ll, pair<pair<int, int>, pair<int, int>>>> mx;
    mx.push(mp(0, mp(mp(1, 1), mp(0, 0))));
    bool vis[n + 2][n + 2];
    memset(vis, 0, sizeof(vis));
    pair<int, int> pr[n + 2][n + 2];
    vector<pair<int, int>> nxt = {mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1)};
    while(mx.size()) {
        ll dist = mx.top().fi; int x = mx.top().se.fi.fi, y = mx.top().se.fi.se;
        int prx = mx.top().se.se.fi, pry = mx.top().se.se.se;
        mx.pop();
        if(x < 1 || y < 1 || x > n || y > n || vis[x][y])
            continue;
        vis[x][y] = 1;
        dist += grid[x][y];
        pr[x][y] = mp(prx, pry);
        for(auto i : nxt) {
            if(!vis[x + i.fi][y + i.se]);
                mx.push(mp(dist, mp(mp(x + i.fi, y + i.se), mp(x, y))));
        }
        if(x == n && y == n)
            cout << dist << endl;
    }
    vector<pair<int, int>> x;
    while(x.empty() || x.back() != mp(1, 1)) {
        if(x.empty()) {
            x.push_back(mp(n, n));
        }
        else {
            x.push_back(pr[x.back().fi][x.back().se]);
        }
    }
    reverse(x.begin(), x.end());
    string out = "";
    for(int i = 1; i < x.size(); ++i) {
        if(x[i].fi == x[i - 1].fi) {
            if(x[i].se == x[i - 1].se + 1) 
                out += 'E';
            else
                out += 'W';
        }
        else {
            if(x[i].fi == x[i - 1].fi + 1)
                out += 'S';
            else
                out += 'N';
        }
    }
    fout << out << endl;
    x.clear();
    out = "";
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<ll, pair<pair<int, int>, pair<int, int>>>
    , vector<pair<ll, pair<pair<int, int>, pair<int, int>>>>
    , greater<pair<ll, pair<pair<int, int>, pair<int, int>>>>> mn;
    mn.push(mp(0, mp(mp(1, 1), mp(0, 0))));
    while(mn.size()) {
        ll dist = mn.top().fi; int x = mn.top().se.fi.fi, y = mn.top().se.fi.se;
        int prx = mn.top().se.se.fi, pry = mn.top().se.se.se;
        mn.pop();
        if(x < 1 || y < 1 || x > n || y > n || vis[x][y])
            continue;
        vis[x][y] = 1;
        dist += grid[x][y];
        pr[x][y] = mp(prx, pry);
        for(auto i : nxt) {
            if(!vis[x + i.fi][y + i.se]);
                mn.push(mp(dist, mp(mp(x + i.fi, y + i.se), mp(x, y))));
        }
        if(x == n && y == n)
            cout << dist << endl;
    }
    while(x.empty() || x.back() != mp(1, 1)) {
        if(x.empty()) {
            x.push_back(mp(n, n));
        }
        else {
            x.push_back(pr[x.back().fi][x.back().se]);
        }
    }
    reverse(x.begin(), x.end());
    for(int i = 1; i < x.size(); ++i) {
        if(x[i].fi == x[i - 1].fi) {
            if(x[i].se == x[i - 1].se + 1) 
                out += 'E';
            else
                out += 'W';
        }
        else {
            if(x[i].fi == x[i - 1].fi + 1)
                out += 'S';
            else
                out += 'N';
        }
    }
    fout << out << endl;
}
int main() {
    // dijkstra min max
    for(int i = 0; i < 5; ++i) {
        fin.open("input_" + to_string(i) + ".txt");
        fout.open("output_" + to_string(i) + ".txt");
        tc();
        fout.close();
        fin.close();
    }
}