#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define fi first
#define se second
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define endl "\n"
using namespace std;
int main() {
  // ios_base::sync_with_stdio(0); cin.tie(0);
  // find a subarray of size k that contains all numbers between 1 to x
  // observe: penambahan is at most N 
  // we can pick any arbitrary subarray of size K such that all the elements are different and max - min = len - 1
  int n, k;
  cin >> n >> k;
  int a[2 * n + 5];
  for(int i = 1; i <= n; ++i)
    cin >> a[i];
  a[0] = a[2 * n + 1] = 1e9;
  for(int i = n + 1; i <= 2 * n; ++i)
    a[i] = a[i - n];
  // observe: subarray we take must be distinct elements only 
  // use two pointers, set L as minimum and find the longest right we can take such that all elements are distinct and the min value is A_L
  // the longest right we need to check is just K
  // or we can process from smallest A[i] to largest A[i]
  // binser just using fenwick, find count of smaller elements to the right and find furthest
  // then later we use two pointers to find distinct?
  // max - min in subarray can not be more than K
  // BSTA COST
  int l = 1, r = k, ans = 0;
  int cnt[n + 1];
  int mx[2 * n + 5], mn[2 * n + 5], le[2 * n + 5], ri[2 * n + 5];
  while(l <= r) {
    int mid = (l + r) / 2;
    // find a subarray of size mid that contains distinct elements and the max - min is at most k
    // if find -> valid
    // else -> invalid
    memset(cnt, 0, sizeof(cnt));
    memset(mx, 0, sizeof(mx));
    fill(mn, mn + 2 * n + 5, 5 * n);
    int distinct = 0;
    // find max/min using precompute nearest smaller elemen weird ah algo
    // precompute: 
    // - find larger element in left and right
    // - set cur as max in subarrays that contain cur (from cur - mid to cur) but are not "handled" by other numbers
    // - the left bound is the next larger element to the left or cur - mid
    // - the right bound is the next larger element to the right - mid or cur
    vector<int> v = {0};
    a[0] = a[2 * n + 1] = 1e9;
    for(int i = 1; i <= 2 * n; ++i) {
      while(a[v.back()] <= a[i])
        v.pop_back();
      le[i] = v.back() + 1;
      v.pb(i);
    }
    v = {2 * n + 1};
    for(int i = 2 * n; i >= 1; --i) {
      while(a[v.back()] < a[i])
        v.pop_back();
      ri[i] = v.back() - mid;
      v.pb(i);
    }
    for(int i = 1; i <= 2 * n; ++i) {
      for(int j = max(le[i], i - mid + 1); j <= min(ri[i], i); ++j)
        mx[j] = a[i];
    }
    a[0] = a[2 * n + 1] = -5;
    v = {0};
    for(int i = 1; i <= 2 * n; ++i) {
      while(a[v.back()] >= a[i])
        v.pop_back();
      le[i] = v.back() + 1;
      v.pb(i);
    }
    v = {2 * n + 1};
    for(int i = 2 * n; i >= 1; --i) {
      while(a[v.back()] > a[i])
        v.pop_back();
      ri[i] = v.back() - mid;
      v.pb(i);
    }
    for(int i = 1; i <= 2 * n; ++i) {
      for(int j = max(le[i], i - mid + 1); j <= min(ri[i], i); ++j)
        mn[j] = a[i];
    }
    for(int i = 1; i <= mid; ++i)
      ++cnt[a[i]], distinct += (cnt[a[i]] == 1);
    if(distinct == mid && mx[1] - mn[1] <= k - 1) {
      ans = mid, l = mid + 1;
      continue;
    }
    // cout << mid << endl;
    // for(int i = 1; i <= 2 * n; ++i) {
    //    cout << "DEB " << i << " " << mn[i] << " " << mx[i] << endl;
    // }
    bool valid = 0;
    for(int i = mid + 1; i <= 2 * n; ++i) {
      --cnt[a[i - mid]];
      if(cnt[a[i - mid]] == 0)
        --distinct;
      ++cnt[a[i]];
      distinct += (cnt[a[i]] == 1);
      // cout << mid << " " << distinct << " " << mx.top() << " " << mn.top() << endl;
      if(distinct == mid && mx[i - mid + 1] - mn[i - mid + 1] <= k - 1 && mx[i - mid] - mn[i - mid] >= 0) {
        // cout << mx.top() << " " << mn.top() << " " << distinct << endl;
        ans = mid, l = mid + 1;
        valid = 1;
        break;
      }
    }
    if(!valid)
      r = mid - 1;
  }
  cout << k - ans << endl;
}