#include <bits/stdc++.h>
#define iPair pair<int, double>
# define INF 1e18L
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

//sumber prim algorithm: https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

const double pi = acos(-1);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(3);
    int n;
    
    while(cin >> n){
        if(n == -1) return 0;
        long long x[n], y[n], r[n];
        
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i] >> r[i];
        }
        double cost[n][n];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cost[i][j] = 0;
        //vector<iPair> adj[n];
        //for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cost[i][j] = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                double singgung = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) - (r[i]-r[j])*(r[i]-r[j]));
                long long selisih = abs(r[i]-r[j]);
                double jarak = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                double sudut;
                if(jarak == 0.0) sudut = 0.0;
                else sudut = asin(selisih/jarak);
                //cout << singgung << endl;
                //cout << sudut << endl;
                cost[i][j] = cost[j][i] = 2.0*(singgung + sudut*selisih) + pi*(r[i]+r[j]);
                //adj[i].push_back(make_pair(j, cost));
                //adj[j].push_back(make_pair(i, cost));
            }
        }
        // Create a priority queue to store vertices that
        // are being primMST. This is weird syntax in C++.
        // Refer below link for details of this syntax
        // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    
        int src = 0; // Taking vertex 0 as source
    
        // Create a vector for keys and initialize all
        // keys as infinite (INF)
        double key[n];
        for(int i = 0; i < n; i++) key[i] = INF;
        //vector<double> key(n, INF);
    
        // To store parent array which in turn store MST
        //vector<int> parent(n, -1);
        int parent[n]; memset(parent, -1, sizeof(parent));
    
        // To keep track of vertices included in MST
        //vector<bool> inMST(n, false);
        bool inMST[n]; memset(inMST, 0, sizeof(inMST));
    
        // Insert source itself in priority queue and initialize
        // its key as 0.
        pq.push(make_pair(0, src));
        key[src] = 0;
    
        /* Looping till priority queue becomes empty */
        while (!pq.empty())
        {
            // The first vertex in pair is the minimum key
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted key (key must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();
    
            // Different key values for the same vertex may exist in the priority queue.
            // The one with the least key value is always processed first.
            // Therefore, ignore the rest.
            if (inMST[u] == true) {
                continue;
            }
    
            inMST[u] = true; // Include vertex in MST

            // Traverse all adjacent of u
            //int x = u;
            //for (auto x : cost[u])
            for(int x = 0; x < n; x++)
            {
                if(x == u) continue;
                // Get vertex label and weight of the current adjacent of u.
                //int v = x.first;
                //double weight = x.second;
                int v = x;
                double weight = cost[u][x];
    
                // If v is not in MST and the weight of (u,v) is smaller
                // than the current key of v
                if (inMST[v] == false && key[v] > weight)
                {
                    // Updating key of v
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
    
        double res = 0.0;
        for (int i = 1; i < n; ++i)
            res += key[i];
        cout << res << "\n";
    }
    return 0;
}