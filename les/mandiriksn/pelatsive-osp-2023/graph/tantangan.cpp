#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int k;
    cin >> k;
    // map<T1, T2> a;
    // a[T1] = T2
    // permutasi ke graph?
    // graph -> node dan edge
    // node -> sebuah permutasi
    // edge -> menghubungkan 2 node
    // kalo ada cara membuat 1 node dr node lain, tambahin edge
    // edge berasal dari operasi pembalikkan
    // bfs aja, shortest path unweighted graph
    queue<pair<int, vector<int>>> bfs;
    bfs.push(make_pair(0, a));
    map<vector<int>, bool> vis;
    map<vector<int>, int> min_dist;
    while(bfs.size()) {
        int dist = bfs.front().first;
        vector<int> permutation = bfs.front().second;
        bfs.pop();
        if(vis[permutation])
            continue;
        vis[permutation] = 1;
        min_dist[permutation] = dist;
        for(int i = 0; i <= n - k; ++i) {
            // coba reverse i...i+k-1
            reverse(permutation.begin() + i, permutation.begin() + i + k);
            bfs.push(make_pair(dist + 1, permutation));
            reverse(permutation.begin() + i, permutation.begin() + i + k);
        }
    }
    vector<int> target(n);
    for(int i = 0; i < n; ++i)
        target[i] = i + 1;
    if(!vis[target])
        cout << -1 << endl;
    else
        cout << min_dist[target] << endl;
}