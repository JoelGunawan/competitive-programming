#include "guess.h"

#include <bits/stdc++.h>
using namespace std;

static int VALUE_MAX = 1000000000;
static int n;
static int a[100010];
static int b[100010];
static int Ask_Count;

int ask(int x,int y,int z) {
  if (!(1 <= x && x <= n && 1 <= y && y <= n && 1 <= z && z<=n)) {
    puts("Invalid Ask");
    exit(0);
  }
  if (!(x != y && y != z && z != x)) {
    puts("Invalid Ask");
    exit(0);
  }
  Ask_Count++;
  if (a[x] > a[y]) swap(x,y);
  if (a[y] > a[z]) swap(y,z);
  if (a[x] > a[y]) swap(x,y);
  return a[y];
}

void answer(int x,int v) {
  if (!(1 <= x && x <= n && b[x] == -1)) {
    puts("Invalid Answer");
    exit(1);
  }
  if (!(1 <= v && v <= VALUE_MAX)) {
    puts("Invalid Answer");
    exit(1);
  }
  b[x] = v;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = -1;
  }

  guess(n);

	for (int i = 1; i <= n; ++i) {
    printf("%d ", b[i]);
  }
  printf("\n");
  printf("Count: %d\n", Ask_Count);
  return 0;
}
