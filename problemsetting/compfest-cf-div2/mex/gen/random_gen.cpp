#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> random_array(int sz, int minv, int maxv) {
  vector<int> res(sz);
  for (auto& i: res) i = rnd.next(minv, maxv);
  return res;
}

int main(int argc, char** argv) {
  registerGen(argc, argv, 1);
  int test_count = opt<int>("test-count");
  int sum_n = opt<int>("sum-n");
  int min_a = opt<int>("min-a");
  int max_a = opt<int>("max-a");
  int min_x = opt<int>("min-x");
  int max_x = opt<int>("max-x");
  
  cout << test_count << endl;

  auto lengths = rnd.partition(test_count, sum_n);
  for(int i = 0; i < test_count; ++i) {
    int n = lengths[i], x = rnd.next(min_x, max_x);
    auto a = random_array(n, min_a, max_a);
    cout << n << " " << x << endl;
    println(a);
  }
}