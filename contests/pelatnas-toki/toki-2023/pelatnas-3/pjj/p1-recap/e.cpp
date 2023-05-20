#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
struct line {
    int x1, y1, x2, y2;
};
pair<long long, long long> sub(pair<long long, long long> a, pair<long long, long long> b) {
    a.first -= b.first;
    a.second -= b.second;
    return a;
}
long long cross(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first * b.second - a.second * b.first;
}
bool intersect(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    long long x = cross(sub(a.se, b.fi), sub(b.se, b.fi)), y = cross(sub(a.fi, b.fi), sub(b.se, b.fi));
    if((x > 0 && y > 0) || (x < 0 && y < 0))
        return false;
    long long c = cross(sub(b.se, a.fi), sub(a.se, a.fi)), d = cross(sub(b.fi, a.fi), sub(a.se, a.fi));
    if((c > 0 && d > 0) || (c < 0 && d < 0))
        return false;
    return true;
}
int main() {
    int n, c;
    ifstream fin("crazy.in");
    ofstream fout("crazy.out");
    fin >> n >> c;
    // make polygons, then find inside which polygon
    // additional case: can be inside multiple polygons
    // determine count of each combination of inside
    // use trie struct to do so? (ez part)
    // cek intersect 2 line
    // x1y2 - x2y1
    // if di kiri dan di kanan
    // cek kiri kanan for both
    vector<vector<pair<int, int>>> hulls;
    line a[n];
    for(int i = 0; i < n; ++i)
        fin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    pair<int, int> cows[c];
    for(int i = 0; i < c; ++i)
        fin >> cows[i].first >> cows[i].second;
    // create hulls
    map<pair<int, int>, vector<pair<int, int>>> edges;
    for(int i = 0; i < n; ++i) {
        pair<int, int> p1 = {a[i].x1, a[i].y1}, p2 = {a[i].x2, a[i].y2};
        edges[p1].push_back(p2);
        edges[p2].push_back(p1);
    }
    map<pair<int, int>, bool> vis;
    for(int i = 0; i < n; ++i) {
        pair<int, int> p1 = {a[i].x1, a[i].y1}, p2 = {a[i].x2, a[i].y2};
        if(!vis[p1]) {
            vis[p1] = 1;
            pair<int, int> cur = p1;
            vector<pair<int, int>> tmp = {cur};
            // do dfs searah thing
            do {
                vis[cur] = 1;
                for(auto j : edges[cur]) {
                    if(!vis[j]) {
                        cur = j;
                        tmp.push_back(cur);
                        break;
                    }
                }
            } while(!vis[cur]);
            hulls.push_back(tmp);
        }
    }
    pair<int, int> inf = {1e9, 2e9 + 7};
    map<vector<int>, int> ans;
    int out = 0;
    for(auto p : cows) {
        vector<int> res;
        int idx = 0;
        for(auto hull : hulls) {
            int cnt = 0;
            for(int i = 0; i < hull.size(); ++i) {
                if(intersect({hull[i], hull[(i + 1) % hull.size()]}, {inf, p})) {
                    ++cnt;
                }
            }
            if(cnt & 1)
                res.push_back(idx);
            ++idx;
        }
        ++ans[res];
        out = max(out, ans[res]);
    }
    fout << out << endl;
    return 0;
}