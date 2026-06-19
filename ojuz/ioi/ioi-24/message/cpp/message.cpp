#include "message.h"
#include <bits/stdc++.h>
using namespace std;

// Full solution
void send_message(std::vector<bool> M, std::vector<bool> C) {
  // nl -> not last
  auto nl = !M.back();
  while (M.size() < 1025) {
    M.push_back(nl);
  }
  int lsm = 0;
  
  vector<vector<int>> messages(66, vector<int>(31, -1));

  auto send_message = [&] (int i) -> void {
    vector<bool> cur(31, 0);
    for (int j = 0; j < 31; ++j) {
      if (messages[i][j] != -1) cur[j] = messages[i][j];
    }

    send_packet(cur);
  };

  for (int i = 0; i < 31; ++i) {
    if (C[i] == 0) {
      // find next
      int nx_dist = 0, tmp = i;
      ++tmp;
      tmp %= 31;
      while (C[tmp] == 1) {
        ++tmp, tmp %= 31, ++nx_dist;
      }

      for (int j = 0; j < nx_dist; ++j) {
        messages[j][i] = 0;
      }

      messages[nx_dist][i] = 1;
    }
  }

  // send the rest of the messages
  for (int i = 0; i < 66; ++i) {
    for (int j = 0; j < 31; ++j) {
      if (C[j] == 0 && messages[i][j] == -1) {
        messages[i][j] = M[lsm++];
      }
    }
  }

  for (int i = 0; i < 66; ++i) send_message(i);
}

std::vector<bool> receive_message(std::vector<std::vector<bool>> R) {
  // find safe bits, then decode the message
  vector<vector<bool>> used(R.size(), vector<bool>(31, 0));
  vector<bool> C(31, 1);
  // find cycle of size 16
  for (int i = 0; i < 16; ++i) {
    // try to find where the cycle starts + values in cycle
    int sum = 0;

    vector<int> vals = {i};
    vector<int> dists;
    do {
      bool found = 0;
      for (int j = 0; j < 66; ++j) {
        if (R[j][vals.back()] == 1) {
          int dst = j + 1;
          int nx = vals.back() + dst;
          nx %= 31;
          sum += dst;
          vals.push_back(nx);
          dists.push_back(dst);
          found = 1;
          break;
        }
      }
      if (!found) break;
    } while (vals.back() != i && sum < 31);

    if (sum != 31 || vals.back() != i || vals.size() != 17) {
      continue;
    }

    for (auto x : vals) C[x] = 0;
    for (int j = 0; j < 16; ++j) {
      for (int k = 0; k < dists[j]; ++k) {
        used[k][vals[j]] = 1;
      }
    }
    break;
  }

  int lsm = 0;
  vector<bool> message(1025);
  for (int i = 0; i < 66; ++i) {
    for (int j = 0; j < 31; ++j) {
      if (C[j] == 0 && !used[i][j]) {
        message[lsm++] = R[i][j];
      }
    }
  }

  for (int i = 1023; i >= 0; --i) {
    if (message[i] != message[i + 1]) {
      message.resize(i + 1);
      break;
    }
  }

  return message;
}
