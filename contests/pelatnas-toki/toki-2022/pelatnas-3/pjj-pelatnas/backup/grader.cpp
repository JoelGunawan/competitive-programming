#include <stdio.h>

#include <string>
#include <vector>

#include "client.h"
#include "server.h"

int get_bit(int p);

std::vector<int> server(int N, std::vector<int> A, std::vector<int> B, std::vector<int> C);

int client(int N, std::vector<int> A, std::vector<int> B, int W);

namespace {

static const int NMAX = 500;
static const int QMAX = 500;
static const int L = 1000;
static const int K = 20;

static int BackupServer[L];
static int InteractionCount;

static void WA(std::string msg) {
  puts(("Wrong Answer: " + msg).c_str());
  exit(0);
}

static void AC() {
  puts("Accepted");
  exit(0);
}

static void ERR(std::string msg) {
  puts(("Error: " + msg).c_str());
  exit(0);
}

static void backup_data(std::vector<int> s) {
  if (s.size() > L) {
    WA("server() returns an array of size over 1000");
  }
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] != 0 && s[i] != 1) {
      WA("server() tries to store a bit with value not in {0, 1}");
    }
  }
  InteractionCount = 0;
  for (int i = 0; i < L; i++) {
    if (i < int(s.size())) {
      BackupServer[i] = s[i];
    } else {
      BackupServer[i] = 0;
    }
  }
}

static int get_answer(int N, int W, std::vector<int> A, std::vector<int> B, std::vector<int> C) {
  if (!(2 <= N && N <= NMAX)) {
    ERR("N does not satisfy constraints");
  }
  if (!(0 <= W && W <= N - 1)) {
    ERR("W does not satisfy constraints");
  }
  for (int i = 0; i < N - 1; i++) {
    if (!(0 <= A[i] && A[i] <= N - 1)) {
      ERR("A[" + std::to_string(i) + "] does not satisfy constraints");
    }
    if (!(0 <= B[i] && B[i] <= N - 1)) {
      ERR("B[" + std::to_string(i) + "] does not satisfy constraints");
    }
    if (!(0 <= C[i] && C[i] <= 1)) {
      ERR("C[" + std::to_string(i) + "] does not satisfy constraints");
    }
  }

  std::vector<std::vector<std::pair<int, int>>> adj(N);
  for (int i = 0; i < N - 1; i++) {
    adj[A[i]].emplace_back(B[i], C[i]);
    adj[B[i]].emplace_back(A[i], C[i]);
  }

  std::vector<int> vis(N, -1);
  std::vector<int> que = {0};
  vis[0] = 0;
  for (int q = 0; q < int(que.size()); q++) {
    int u = que[q];
    for (std::pair<int, int> t : adj[u]) {
      int v = t.first;
      int w = t.second;
      if (vis[v] == -1) {
        vis[v] = vis[u] + w;
        que.emplace_back(v);
      }
    }
  }

  if (que.size() != N) {
    ERR("city is not connected");
  }

  return vis[W];
}

}  // namespace

int get_bit(int p) {
  if (p < 0 || p >= L) {
    WA("get_bit() requests an invalid position");
  }
  InteractionCount++;
  if (InteractionCount > K) {
    WA("over 20 calls to get_bit()");
  }
  return BackupServer[p];
}

int main() {
  int Q;
  scanf("%d", &Q);
  for (int q = 0; q < Q; q++) {
    int N, W;
    scanf("%d %d", &N, &W);
    std::vector<int> A(N - 1), B(N - 1), C(N - 1);
    for (int i = 0; i < N - 1; i++) {
      scanf("%d %d %d", &A[i], &B[i], &C[i]);
    }
    get_answer(N, W, A, B, C);  // check for constraints
    backup_data(server(N, A, B, C));
    if (client(N, A, B, W) != get_answer(N, W, A, B, C)) {
      WA("client() returns incorrect number of congested roads");
    }
  }
  AC();
  return 0;
}
