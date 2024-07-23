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
  int t;
  cin >> t;
  while(t--) {
    int a, b, k;
    cin >> a >> b >> k;
    if(a > 2 * (b + 1) || b > k * (a + 1)) {
      cout << "mustahil" << endl;
    }
    else if(a > b) {
      // laki > perempuan
      // LLPLLPLLP...
      int cntlaki = a, cntperempuan = b;
      bool terakhir_keluar = 0;
      for(int i = 0; i < a + b; ++i) {
        if(cntlaki == cntperempuan)
          break;
        if(i % 3 == 0 || i % 3 == 1) {
          // L
          cout << "L";
          terakhir_keluar = false;
          --cntlaki;
        }
        else {
          // P
          cout << "P";
          terakhir_keluar = true;
          --cntperempuan;
        }
      }
      // antara LP atau PL tergantung yang terakhir di keluarkan
      for(int i = 0; i < cntlaki + cntperempuan; ++i) {
        if(terakhir_keluar) {
          if(i % 2 == 0)
            cout << "L";
          else
            cout << "P";
        }
        else {
          if(i % 2 == 0)  
            cout << "P";
          else
            cout << "L";
        }
      }
      cout << endl;
    }
    else if(b > a) {
      int cntlaki = a, cntperempuan = b;
      // PP...PLPP...PL
      // pola berulang setiap K + 1
      // PP..PL
      // jika di modulo (K + 1) sisanya dari 0...K-1 -> P
      // jika di modulo (K + 1) sisanya K -> L
      bool terakhir_keluar = 0;
      for(int i = 0; i < a + b; ++i) {
        if(cntlaki == cntperempuan)
          break;
        if(i % (k + 1) < k) {
          cout << "P";
          --cntperempuan;
          terakhir_keluar = 1;
        }
        else {
          cout << "L";
          --cntlaki;
          terakhir_keluar = 0;
        }
      }
      for(int i = 0; i < cntlaki + cntperempuan; ++i) {
        if(terakhir_keluar) {
          if(i % 2 == 0)
            cout << "L";
          else
            cout << "P";
        }
        else {
          if(i % 2 == 0)  
            cout << "P";
          else
            cout << "L";
        }
      }
      cout << endl;
    }
    else {
      // laki = perempuan
      for(int i = 0; i < a + b; ++i) {
        if(i % 2 == 1)
          cout << "L";
        else
          cout << "P";
      }
      cout << endl;
    }
    /*
    if(a == 0) {
      if(b <= k) {
        for(int i = 0; i < b; ++i)
          cout << "P";
        cout << endl;
      }
      else {
        cout << "mustahil" << endl;
      }
    }
    else {
      if(b / 2 + (b % 2) <= k) {
        for(int i = 0; i < b / 2; ++i)
          cout << "P";
        cout << "L";
        for(int i = b / 2; i < b; ++i)
          cout << "P";
        cout << endl;
      }
      else {
        cout << "mustahil" << endl;
      }
    }
    */
  }
  return 0;
}