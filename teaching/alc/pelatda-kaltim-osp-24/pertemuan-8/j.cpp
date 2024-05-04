#include <bits/stdc++.h>
using namespace std;
vector<int> edges[200005];
bool vis[200005];
int subtree[200005];
void dfs(int nd) {
  vis[nd] = 1;
  subtree[nd] = 1;
  for(auto x : edges[nd]) {
    if(!vis[x]) {
      dfs(x);
      subtree[nd] += subtree[x];
    }
  }
}
int main() {
  int n;
  cin >> n;
  for(int i = 2; i <= n; ++i) {
    int x;
    cin >> x;
    // artinya: ada edge antara i dengan x
    edges[x].push_back(i);
    edges[i].push_back(x);
  }
  dfs(1);
  for(int i = 1; i <= n; ++i) {
    cout << subtree[i] - 1 << " ";
  }
  cout << endl;
}