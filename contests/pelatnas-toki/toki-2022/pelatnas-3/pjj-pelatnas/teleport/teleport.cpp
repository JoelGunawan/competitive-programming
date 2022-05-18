#include "teleport.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
int last_color = 1;
int memo[200][200], edge_cnt[200];
vector<int> edges[200];
int last[200];
std::vector<int> explore(int N, int X) {
  // use a bfs algo
  // each ctv maintains a previous
  // maintains node and previous node index in teleporter
  change_news_channel(1);
  queue<pair<int, vector<int>>> bfs;  
  vector<int> tmp111111 = vector<int>(0);
  bfs.push(make_pair(1, tmp111111));
  bool vis[N];
  memset(vis, 0, sizeof(vis));
  memset(last, -1, sizeof(last));
  while(bfs.size() > 0) {
    vector<int> arr = bfs.front().second;
    int nd = bfs.front().first;
    bfs.pop();
    //cout << nd << endl;
    if(vis[nd])
      continue;
    for(int i : arr)
      use_teleporter(i);
    vis[nd] = 1;
    last[nd] = ask_last_teleporter();
    edge_cnt[nd] = ask_count_teleporters();
    for(int i = 0; i < edge_cnt[nd]; ++i) {
      if(i != last[nd]) {
        // go to i
        use_teleporter(i);
        int tmp = ask_news_channel(), p = ask_last_teleporter();
        // kalo misal not visited dan kita harus tambahkan
        if(tmp == 0 && last_color + 1 < X)
          change_news_channel(++last_color);
        // jika diganti kita query lagi
        tmp = ask_news_channel();
        // masukkan sementara i untuk mendapatkan path
        arr.push_back(i);
        if(!vis[tmp])
          bfs.push(make_pair(tmp, arr));
        arr.pop_back();
        //cout << nd << " " << i << " " << tmp << endl;
        memo[nd][i] = tmp;
        memo[tmp][p] = nd;
        // go back from i
        use_teleporter(p);
      }
    }
    while(last[ask_news_channel()] != -1 && ask_news_channel() != 1)
      use_teleporter(last[ask_news_channel()]);
  }
  for(int i = 0; i < N; ++i) {
    //cout << "EDGE " << i << " ";
    for(int j = 0; j < edge_cnt[i]; ++j) {
      edges[i].push_back(memo[i][j]);
      //cout << memo[i][j] << " ";
    }
    //cout << endl;
  }
  vector<int> ans(N, 0);
  for(int i = 0; i < N; ++i) {
    memset(vis, 0, sizeof(vis));
    // do a BFS with 2 states
    queue<pair<int, int>> bfs;
    bfs.push(make_pair(i, 0));
    while(bfs.size() > 0) {
      int nd = bfs.front().first, dist = bfs.front().second;
      bfs.pop();
      if(vis[nd])
        continue;
      vis[nd] = 1;
      if(nd <= i)
        ++ans[dist];
      for(auto i : edges[nd]) {
        if(!vis[i])
          bfs.push(make_pair(i, dist + 1));
      }
    }
  }
  return ans;
}
