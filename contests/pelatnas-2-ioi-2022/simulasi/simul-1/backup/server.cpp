#include "server.h"

#include <vector>
#include <bits/stdc++.h>
using namespace std;
// coba subtask a[i] = i, b[i] = i + 1
// graph merupakan garis lurus
// mungkin kita bisa store pake checkpoint
// kita buat yang distance nya setengah dari root
// HLD????????????
// MAYBE??????????
// how to HLD
// AAAAAAAAAAAAAAAAAAAAAAA
// HLD pake 2 dfs tapi gimana kok lupa ._.

// buat sub a[i] = i, b[i] = i + 1 -> simpen distance dari i ke root pake binary number
// kita simpen distance yang pangkat 2 aja buat tiap node
// semacam BIT
string to_binary(int number, int size) {
  // kita pad sampe jadi size
  string res = "";
  while(number > 0) {
    if(number & 1)
      res += '1';
    else
      res += '0';
    number /= 2;
  }
  while(res.size() < size)
    res += '0';
  reverse(res.begin(), res.end());
  //cout << number << " " << size << " " << res << endl;
  return res;
}
vector<pair<int, int>> edges[501];
int dist[501];
bool vis[501];
void dfs(int nd, int d = 0) {
  vis[nd] = 1;
  dist[nd] = d;
  for(auto i : edges[nd]) {
    if(!vis[i.first])
      dfs(i.first, d + i.second);
  }
}
std::vector<int> server(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < N; ++i)
    edges[i].clear();
  for(int i = 0; i < A.size(); ++i) {
    edges[A[i]].push_back(make_pair(B[i], C[i]));
    edges[B[i]].push_back(make_pair(A[i], C[i]));
  }
  //cout << "TEST" << endl;
  dfs(0);
  // 9 * 100
  //cout << "TEST" << endl;
  // each digit -> 9
  vector<int> ans(9 * N, 0);
  for(int i = 0; i < N; ++i) {
    int start = 9 * i;
    string tmp = to_binary(dist[i], 9);
    for(int j = start; j < start + 9; ++j)
      ans[j] = (tmp[j - start] == '1');
  }
  return ans;
  // dfs on A[i]
  /*
  int size[N + 1];
  size[0] = 0;
  int sum = 0, m = 0;
  for(int i = 1; i < N; ++i) {
    size[i] = 1;
    for(int j = 0; j < 10; ++j) {
      if(i % (1 << j) == 0)
        size[i] = j + 1;
    }
    sum += size[i];
    m = max(m, size[i]);
  }
  for(int j = 0; j < 10; ++j) {
    if((1 << j) & N)
      size[N] = j + 1;
  }
  sum += size[N];
  // tiap angka determine ke atas atau ke bawah
  // tergantung count yang lebih kecil yang mana
  vector<int> ans(sum, 0);
  //cout << "TEST" << endl;
  int pref[N + 1], nxt[N];
  nxt[N] = 0;
  memset(pref, 0, sizeof(pref));
  int cur_sum = 0;
  for(int i = 1; i < N; ++i) {
    pref[i] = pref[i - 1] + C[i - 1];
  }
  pref[N] = pref[N - 1];
  for(int i = 1; i < N; ++i) {
    //cout << pref[i] << " ";
    int cnt = 0, tmp = 0, inverse = 0;
    for(int j = 0; j < m; ++j) {
           if(i & (1 << j))
            tmp += j + 1;
          else
            inverse += j + 1;
    }
    inverse += size[i];
    string res;
    if(tmp >= inverse) {
      // pergi ke bawah instead
      nxt[i] = min(N, i + (1 << (size[i] - 1))), res = to_binary(pref[nxt[i]] - pref[i], size[i]);
    }
    else
      nxt[i] = i - (1 << (size[i] - 1)), res = to_binary(pref[i] - pref[nxt[i]], size[i]);
    //cout << tmp << " " << inverse << " " << i << " " << nxt[i] << " " << pref[i] << " " << pref[nxt[i]] << endl;
    for(int j = cur_sum; j < cur_sum + size[i]; ++j) {
      ans[j] = (res[j - cur_sum] == '1');
    }
    cur_sum += size[i];
  }
  string res = to_binary(pref[N - 1], size[N]);
  for(int j = cur_sum ; j < sum; ++j)
    ans[j] = (res[j - cur_sum] == '1');
  //cout << endl;
  return ans;
  */
}