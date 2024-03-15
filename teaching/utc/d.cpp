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
long long int pangkat(int x, int y) {
  if(y == 0)
    return 1;
  // optional
  else if(y == 1)
    return x;
  else {
    long long int tmp = pangkat(x, y / 2);
    tmp = (tmp * tmp);
    if(y % 2 == 1)
      return tmp * x;
    else
      return tmp;
  }
}
void merge_sort(vector<int> &a, int l, int r) {
  // 1 selalu sorted
  if(l == r)
    return;
  int mid = (l + r) / 2;
  merge_sort(a, l, mid);
  merge_sort(a, mid + 1, r);
  // merge [l...mid], [mid + 1...r]
  vector<int> v;
  int idxl = l, idxr = mid + 1;
  for(int i = l; i <= r; ++i) {
    // cek kiri udah kosong atau belum
    if(idxl > mid) {
      v.pb(a[idxr++]);
    }
    // cek kanan udah kosong atau belum
    else if(idxr > r) {
      v.pb(a[idxl++]);
    }
    // dua"nya belum kosong
    else {
      // pilih yang paling kecil
      if(a[idxl] < a[idxr]) {
        v.pb(a[idxl++]);
      }
      else {
        v.pb(a[idxr++]);
      }
    }
  }
  for(int i = l; i <= r; ++i)
    a[i] = v[i - l];
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  /*
  int x, y;
  cin >> x >> y;
  cout << pow(x, y) << endl;
  */
  /*
  int n;
  cin >> n;
  vector<int> a;
  for(int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  merge_sort(a, 0, a.size() - 1);
  for(auto i : a)
    cout << i << " ";
  cout << endl;
  */
  // binary search angka x di vector a
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; ++i)
    cin >> a[i];
  // l -> paling kecil
  // r -> paling besar
  merge_sort(a, 0, n - 1);
  int cl = 0, cr = n - 1, ans = -1;
  while(cl <= cr) {
    int mid = (cl + cr) / 2;
    // cek posisi mid
    if(a[mid] == x) {
      // ktmu jawaban, print
      ans = mid;
      break;
    }
    else if(a[mid] < x) {
      // mid terlalu kecil
      cl = mid + 1;
    }
    else {
      // mid terlalu besar
      cr = mid - 1;
    }
  }
  cout << ans << endl;
  return 0;
}