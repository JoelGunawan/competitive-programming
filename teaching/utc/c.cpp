// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int gcd(int a, int b) {
  if(b == 0)
    return a;
  else
    return gcd(b % a, a);
}
int gcd2(int a, int b) {
  while(b != 0) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  cout << gcd2(a, b) << endl;
  /*
  int n;
  cin >> n;
  // cari semua prime dari 1 ke n
  bool prime[n + 5];
  // anggap awalnya semuanya prime
  memset(prime, 1, sizeof(prime)); // semua isi prime jadi 1
  // memset: 
  // di array boolean bs set jadi 0/1
  // di array int bs set jadi 0/-1
  prime[0] = prime[1] = 0;
  for(int i = 2; i <= n; ++i) {
    if(prime[i]) {
      // mulai dari 2i, 2i + i, 2i + 2i, 2i + 3i
      // -> 2i, 3i, 4i, 5i, ...
      for(int j = i * 2; j <= n; j += i) {
        prime[j] = 0;
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    if(prime[i])
      cout << i << " ";
  }
  cout << endl;
  */
  /*
  bool prime = true;
  for(int i = 2; i <= sqrt(n); ++i) {
    if(n % i == 0) {
      prime = false;
    }
  }
  if(prime)
    cout << "PRIME" << endl;
  else
    cout << "NOT PRIME" << endl;
  */
  return 0;
}