#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2,sse,sse3,sse4,sse4.1,avx,mmx")
using namespace std;
const int N = 3e5 + 1, A = 3e5 + 1, B = 427;
int n;
int a[N];
vector<int> primes, divs[A];
int lp[A], mu[A], tot[A], sf[A];
int blk[A], ans[A], ma[A];
bool skp[A];
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i < A; i++) {
    blk[i] = -1;
    for (int j = i; j < A; j += i) {
      divs[j].push_back(i);
    }
  }
  sf[1] = 1;
  for (int i = 2; i < A; i++) {
    if (lp[i] == 0) {
      sf[i] = i;
      mu[i] = -1;
      primes.push_back(lp[i] = i);
    }
    for (int j = 0; j < primes.size() && i * primes[j] < A; j++) {
      lp[i * primes[j]] = primes[j];
      sf[i * primes[j]] = sf[i] * primes[j];
      if (lp[i] == primes[j]) {
        sf[i * primes[j]] = sf[i];
        mu[i * primes[j]] = 0;
        break;
      }
      mu[i * primes[j]] = -mu[i];
    }
  }
  cin >> n;
  unordered_set<int> ind;
  vector<int> vals;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    // a[i] = i;
    ma[sf[a[i]]] = max(ma[sf[a[i]]], a[i]);
    ind.insert(sf[a[i]]);
    vals.push_back(sf[a[i]]);
  }
  sort(begin(vals), end(vals));
  vals.erase(unique(begin(vals), end(vals)), end(vals));
  reverse(begin(vals), end(vals));
  vector<int> tcnt(A, 0), tera;
  for (int i = 0; i < vals.size(); i++) {
    for (int j: divs[i]) {
      tcnt[j] += mu[j];
    }
  }
  for (int i: ind) {
    int tcc = 0;
    for (int j: divs[i]) {
      tcc += tcnt[j];
    }
    if (tcc + 1 == vals.size()) {
      tera.push_back(i);
      ans[i] = 1;
      skp[i] = 1;
    }
  }
  for (int i: tera) {
    ind.erase(i);
  }
  for (int i = 0; i < vals.size(); i += B) {
    vector<int> dist;
    int cnt = 0;
    for (int j = 0; j < B && i + j < vals.size(); j++) {
      if (ma[vals[i + j]]) {
        cnt++;
        for (int k: divs[vals[i + j]]) {
          tot[k] += mu[k];
          dist.push_back(k);
        }
      }
    }
    vector<int> era;
    for (int j: ind) {
      int cc = 0;
      for (int k: divs[j]) {
        cc += tot[k];
      }
      if (cc != cnt) {
        era.push_back(j);
        blk[j] = i;
      }
    }
    for (int j: era) {
      ind.erase(j);
    }
    for (int j: dist) {
      tot[j] = 0;
    }
  }
  // auto t1 = chrono::steady_clock::now();
  for (int i = 1; i < A; i++) {
    if (blk[i] != -1 && !skp[i]) {
      for (int j = 0; j < B && j + blk[i] < vals.size(); j++) {
        if (ma[vals[j + blk[i]]] && __gcd(vals[j + blk[i]], i) == 1) {
          ans[i] = ma[vals[j + blk[i]]];
          break;
        }
      }
    }
  }
  // auto t2 = chrono::steady_clock::now();
  // auto elapsed = t2 - t1;
  // auto t3 = chrono::steady_clock::now();
  for (int i = 1; i <= n; i++) {
    cout << ans[sf[a[i]]] << ' ';
    // assert(__gcd(ans[sf[a[i]]], a[i]) == 1);
  }
  // auto t4 = chrono::steady_clock::now();
  // auto elapsed2 = t4 - t3;
  // cout << elapsed.count() / 1e9 << endl;
  // cout << elapsed2.count() / 1e9 << endl;
}