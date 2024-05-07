#include <bits/stdc++.h>
using namespace std;
long long sqr(long long a) {
    return a * a;
}
int main() {
    int n;
    cin >> n;
    long long a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // first -> node
    // second -> weight
    vector<pair<int, long long>> edges[n + 1];
    for(int i = 2; i <= n; ++i) {
        if(i > 2) {
            edges[i].push_back(make_pair(i - 2, 3 * sqr(a[i] - a[i - 2])));
            edges[i - 2].push_back(make_pair(i, 3 * sqr(a[i] - a[i - 2])));
        }
        edges[i].push_back(make_pair(i - 1, sqr(a[i] - a[i - 1])));
        edges[i - 1].push_back(make_pair(i, sqr(a[i] - a[i - 1])));
    }
    // first -> jarak
    // second -> node
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, 1));
    long long dist[n + 1];
    memset(dist, -1, sizeof(dist));
    while(pq.size()) {
        long long jarak = pq.top().first;
        int node = pq.top().second;
        // cout << "node: " << node << " " << jarak << endl;
        pq.pop();
        if(dist[node] != -1)
            continue;
        dist[node] = jarak;
        for(auto i : edges[node]) {
            if(dist[i.first] == -1)
                pq.push(make_pair(jarak + i.second, i.first));
        } 
    }
    cout << dist[n] << endl;
}