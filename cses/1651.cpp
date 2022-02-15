// header file
#include <bits/stdc++.h>
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
const int lim = 262144;
struct segtree {
    int a[2 * lim + 1], arr_size = lim;
    segtree() {
        memset(a, 0, sizeof(a));
    }
    void update(int index, int value) {
        index += arr_size;
        a[index] = value;
        while(index > 1) {
            index >>= 1;
            a[index] = a[2 * index] + a[2 * index + 1];
        }
    }
    int query(int left, int right) {
        
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    
    return 0;
}