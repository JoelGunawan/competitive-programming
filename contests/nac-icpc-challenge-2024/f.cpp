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
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string input;
  getline(cin, input);
  int a[12][4];
  int mxw = 20 * 1e6, mxv = 25 * 1e6;
  // q v m l
  // q -> max buy
  // v -> value
  // m -> weight
  // l -> vol
  // cerr << "OUT1: " << input << endl;
  int q[12], v[12], m[12], l[12];
  for(int i = 0; i < 12; ++i) {
    getline(cin, input);
    // cerr << "OUT2: " << input << endl;
    getline(cin, input);
    // cerr << "OUT3: " << input << endl;
    input.erase(--input.end());
    q[i] = stoi(input);
    getline(cin, input);
    input.erase(--input.end());
    v[i] = stoi(input);
    getline(cin, input);
    input.erase(--input.end());
    m[i] = stoi(input);
    getline(cin, input);
    l[i] = stoi(input);
    getline(cin, input);
  }
  getline(cin, input);
  int mx[12];
  memset(mx, 0, sizeof(mx));
  for(int i = 0; i < 12; ++i) {
    mx[i] = max(mx[i], min(mxw / m[i], mxv / l[i]));
  }
  int it = 7e5;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  vector<int> arr2(12);
  for(int i = 0; i < 12; ++i)
    arr2[i] = i;

  vector <double> val(12);
  for (int i = 0; i < 12; i++) {
    val[i] = (double) v[i] / l[i] + (double) v[i] / m[i];
  }

  sort(arr2.begin(), arr2.end(), [&](int i, int j) {
    return val[i] > val[j];
  }); 

  pair<ll, vector<int>> mex = mp(0ll, vector<int>());
  for(;it;--it) {
    // random_shuffle(arr2.begin(), arr2.end());
    ll choose = 0;
    ll curw = 0, curv = 0;
    ll cur_res = 0; 
    vector<int> cur(12);
    for(int i = 0; i < 12; ++i) {
      ll curmx = min((mxw - curw) / m[arr2[i]], (mxv - curv) / l[arr2[i]]);
      ll buy = rng() % (min(curmx, (ll)q[arr2[i]]) + 1);
      cur_res += 1ll * buy * v[arr2[i]];
      curw += 1ll * buy * m[arr2[i]];
      curv += 1ll * buy * l[arr2[i]];
      cur[arr2[i]] = buy;
    }
    assert(curw <= mxw &&  curv <= mxv);
    mex = max(mex, mp(cur_res, cur));
  }
  cout << "{" << endl;
  string arr[] = {"circlet", "coppercoin", "crown", "dagger", "figurine", "goblet", "goldcoin", "helm", "jewelry", "plate", "silvercoin", "torc"};
  for(int i = 0; i < 12; ++i) {
    assert(mex.se[i] <= q[i]);
    cout << " " << (char)34 << arr[i] << (char)34 << ": " << mex.se[i];
    if(i == 11)
      cout << endl;
    else
      cout << "," << endl;
  }
  cout << "}" << endl;
  return 0;
}