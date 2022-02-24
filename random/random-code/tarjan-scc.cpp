#include<iostream>

#include<stack>

#define lim 5
using namespace std;

int graph[lim][lim];

int min(int a, int b) {
  return (a < b) ? a : b;
}

void findComponent(int u, int disc[], int lowLink[], stack < int > & stk, bool stkItem[]) {
  static int time = 0;
  disc[u] = lowLink[u] = ++time;
  stk.push(u);
  stkItem[u] = true;

  for (int v = 0; v < lim; v++) {
    if (graph[u][v]) {
      if (disc[v] == -1) {
        findComponent(v, disc, lowLink, stk, stkItem);
        lowLink[u] = min(lowLink[u], lowLink[v]);
      } else if (stkItem[v])
        lowLink[u] = min(lowLink[u], disc[v]);
    }
  }
  int poppedItem = 0;
  if (lowLink[u] == disc[u]) {
    while (stk.top() != u) {
      poppedItem = stk.top();
      cout << poppedItem << " ";
      stkItem[poppedItem] = false;
      stk.pop();
    }
    poppedItem = stk.top();
    cout << poppedItem << endl;
    stkItem[poppedItem] = false;
    stk.pop();
  }
}

void strongConComponent() {
  int disc[lim], lowLink[lim];
  bool stkItem[lim];
  stack < int > stk;

  for (int i = 0; i < lim; i++) {
    disc[i] = lowLink[i] = -1;
    stkItem[i] = false;
  }

  for (int i = 0; i < lim; i++)
    if (disc[i] == -1)
      findComponent(i, disc, lowLink, stk, stkItem);
}

int main() {
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> graph[i][j];
        }
    }
    strongConComponent();
}