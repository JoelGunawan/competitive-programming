// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
int adj(int nd) {
    cout << "adj " << nd << endl;
    int in;
    cin >> in;
    return in;
}
int subtree(int nd) {
    cout << "subtree " << nd << endl;
    int in;
    cin >> in;
    return in;
}
int move(int nd) {
    cout << "move " << nd << endl;
    int in;
    cin >> in;
    return in;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dia traverse dari paling mendekati leaf, 
    // mulai dari 1, jika hanya ada 1 edge -> langsung move ke adj nodenya
    // jika ada 2 child atau lebih, maka ada beberapa possibility
    // bisa ke node itu lewat parent
    // bisa lewat child tapi gatau child yang mana
    // tiap node discovery butuh 3 operasi
    // subtree
    // adj
    // move
    int n;
    cin >> n;
    int cur_node = 1;
    int par[n + 1], subtree[n + 1];
    memset(subtree, 0, sizeof(subtree));
    subtree[1] = n;
    memset(par, -1, sizeof(par));
    vector<int> child[n + 1];
    // try dfs ke new node, klo node itu di child node sekarang, berarti pergi ke node itu, kalo ga, berarti skip dulu :D
    // if at any point ada node yg child count >= n / 2 -> pasti itu centroid
    // kalo sampe di parent ada > n / 2 -> langsung gak bisa, pergi ke parent
    int par_cnt = 0;
    mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());
    while(true) {
        // use random and probabilities
        // di sebuah node coba random beberapa node lain, kalo distribusinya cukup uniform
        //, coba pastiin apakah node ini bs jadi centroid dengan pake lebih banyak node
        // choose around 20 nodes
        // kalo cmn ada 1, ya pasti ke situ
        // kalo ada lebih dari 1, 
        
    }
    return 0;
}