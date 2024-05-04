#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int lim = 2e5 + 5;
int a[lim], s[lim];
ll merge_sort(int l, int r) {
  if(l == r) {
    s[l] = a[l];
    return 0;
  }
  int mid = (l + r) / 2;
  // gabung kiri dan kanan
  // detail penting: kalo ada yg sama -> masukkan yg kanan dlu karena inversion >= 
  // misal inversion >, masukkin yg kiri dlu
  ll ret = 0;
  ret += merge_sort(l, mid), ret += merge_sort(mid + 1, r);
  int lidx = l, ridx = mid + 1, idx = l;
  vector<int> v;
  while(lidx <= mid || ridx <= r) {
    // salah satu udah lebih dari batas -> langsung ambil satunya
    if(lidx > mid) {
      // karena left udah ga ada, pasti ambil yg kanan
      // gaperlu hitung inversion
      v.push_back(s[ridx++]);
    }
    else if(ridx > r) {
      // karena right udah ga ada, pasti ambil yg kiri
      // ambil kiri, hitung inversion
      // cari di kanan yg udah diambil
      ret += ridx - mid - 1;
      v.push_back(s[lidx++]);
    }
    else {
      if(s[ridx] <= s[lidx]) {
        v.push_back(s[ridx++]);
      }
      else {
        ret += ridx - mid - 1;
        v.push_back(s[lidx++]);
      }
    }
  } 
  for(int i = 0; i < v.size(); ++i) {
    s[l + i] = v[i];
  }
  return ret;
}
int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
      cin >> a[i];
    cout << merge_sort(1, n) << endl;
  }
}