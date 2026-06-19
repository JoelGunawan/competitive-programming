#include "message.h"
#include <bits/stdc++.h>
using namespace std;

// Q = 70 soln.
void send_message(std::vector<bool> M, std::vector<bool> C) {
  // nl -> not last
  auto nl = !M.back();
  while (M.size() < 1025) {
    M.push_back(nl);
  }
  // fs -> first safe, lsm -> last sent message
  int fs = 0, lsm = 0;
  for (int i = 0; i < C.size(); ++i) {
    if (C[i] == 0) {
      fs = i;
      break;
    }
  }
  
  // send safe bit
  for (int i = 0; i < 4; ++i) {
    bool b = fs & (1 << i);
    std::vector<bool> A(31, b);
    send_packet(A);
  }

  // next 30 messages, send remainder values while communicating safe
  for (int i = 0; i < 31; ++i) {
    if (i == fs) {
      continue;
    }

    std::vector<bool> A(31, 0);
    for (int j = 0; j < 31; ++j) {
      if (j == fs) A[j] = C[i];
      else if (C[j] == 0) A[j] = M[lsm++];
    }

    send_packet(A);
  }

  // next 36 messages, send the message
  for (int i = 0; i < 36; ++i) {
    std::vector<bool> A(31, 0);
    for (int j = 0; j < 31; ++j) {
      if (C[j] == 0) A[j] = M[lsm++];
    }
    
    send_packet(A);
  }
}

std::vector<bool> receive_message(std::vector<std::vector<bool>> R) {
  // deduce safe bit from first four messages
  // cm -> current message number, fs -> first safe
  int cm = 0, fs = 0;
  for (int i = 0; i < 4; ++i) {
    auto &cur = R[cm++];

    int cnt1 = 0;
    for (int j = 0; j < 31; ++j) {
      if (cur[j] == 1) ++cnt1;
    }

    if (cnt1 >= 16) fs += 1 << i;
  }

  // deduce safe bits
  vector<bool> C;
  for (int i = 0; i < 30; ++i) {
    C.push_back(R[cm + i][fs]);
  }
  C.insert(C.begin() + fs, 0);

  // lsm -> last message index
  int lsm = 0;
  std::vector<bool> message(1025);

  // read 30 messages while communicating safe
  for (int i = 0; i < 30; ++i) {
    auto &cur = R[cm++];

    for (int j = 0; j < 31; ++j) {
      if (j != fs && C[j] == 0) {
        message[lsm++] = cur[j];
      }
    }
  }

  // read 36 messages
  for (int i = 0; i < 36; ++i) {
    auto &cur = R[cm++];
    for (int j = 0; j < 31; ++j) {
      if (C[j] == 0) message[lsm++] = cur[j];
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
