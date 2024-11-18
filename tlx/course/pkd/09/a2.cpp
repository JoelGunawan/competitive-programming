#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define err cout<<"error"<<endl;

int main() {
    ll n,m,x,y;
    cin >> n >> m;

    int a[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> x >> y;
    // cout << x << " " << y << endl;

    bool visited[n][m];
    memset(visited,0,sizeof(visited));

    queue<pair<int,pair<int,int>>>q; // distance i j
    q.push(make_pair(1,make_pair(x-1,y-1)));

    while(q.size()) {
        // err
        int dist=q.front().first;
        pair<int,int>cur=q.front().second;
        q.pop();

        int fi=cur.first;
        int se=cur.second;

        if(visited[fi][se]) continue;
        visited[fi][se]=true; 

        // cout << fi << " " << se << endl;

        if(fi==0 or fi==n-1 or se==0 or se==m-1) cout << dist, exit(0);
        // atas
        ++dist;
        if(a[fi-1][se]==0) q.push({dist,{fi-1,se}});
        // bawah
        if(a[fi+1][se]==0) q.push({dist,{fi+1,se}});
        // kanan
        if(a[fi][se+1]==0) q.push({dist,{fi,se+1}});
        // kiri
        if(a[fi][se-1]==0) q.push({dist,{fi,se-1}});
    }
}