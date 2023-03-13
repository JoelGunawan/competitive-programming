#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
int main() {
    int k, n, m, o;
    cin >> k >> n >> m >> o;
    vector<pair<int, int>> edges[n + 6];
    for(int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[a].push_back(make_pair(b, t));
    }
    vector<pair<int, int>> queries[n + 6];
    for(int i = 0; i < o; ++i) {
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        queries[a].push_back({b, i});
    }
    // pake modified binary lifting
    // binlift contains to 5 nodes for k binlift
    
}